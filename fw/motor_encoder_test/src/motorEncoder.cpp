#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/portmacro.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/periph_ctrl.h"
#include "driver/gpio.h"
#include "driver/pcnt.h"
#include "esp_attr.h"
#include "esp_log.h"
#include "soc/gpio_sig_map.h"
#include "esp32-hal-adc.h"
#include "esp_system.h"
#include "motorEncoder.h"

unsigned long long MotorEncoder::gpioInputPinSel = 1;

void IRAM_ATTR MotorEncoder::gpio_isr_handler(void* arg)
{
    //Handle edge interrupt time for frequency calculation
    int64_t currentTime = esp_timer_get_time();
    struct CounterTimeData * aCounterTimeData = (struct CounterTimeData *)arg;
    if(currentTime > aCounterTimeData->counterPrevTime + ENC_DEBOUNCE_US){
        aCounterTimeData->counterTimeDiff = currentTime - aCounterTimeData->counterPrevTime;
        if(gpio_get_level(static_cast<gpio_num_t>(encPins[2*(aCounterTimeData->aCounterIndex) + 1])))
            aCounterTimeData->counterTimeDiff = -aCounterTimeData->counterTimeDiff;
        aCounterTimeData->counterPrevTime = currentTime;
    }
    //TODO - Handle possible PCNT overflow interrupt...
}
void MotorEncoder::pcnt_init(pcnt_unit_t pcntUnit, uint8_t GPIO_A, uint8_t GPIO_B)
{
    pcnt_config_t pcnt_config = {
        // Set PCNT input signal and control GPIOs
        GPIO_A,   //pulse_gpio_num
        GPIO_B,    //ctrl_gpio_num
        // What to do when control input is low or high?
        PCNT_MODE_KEEP,   //lctrl_mode  // Keep the primary counter mode if high
        PCNT_MODE_REVERSE,  //hctrl_mode   // Reverse counting direction if low 
        // What to do on the positive / negative edge of pulse input?
        PCNT_COUNT_INC, //pos_mode   // Count up on the positive edge
        PCNT_COUNT_DEC, //neg_mode   // Keep the counter value on the negative edge
        // Set the maximum and minimum limit values to watch
        PCNT_H_LIM_VAL, //counter_h_lim
        PCNT_L_LIM_VAL, //counter_l_lim
        pcntUnit,   //unit
        PCNT_CHANNEL_0, //channel
    };
    pcnt_unit_config(&pcnt_config); //Initialize PCNT units

    /* Configure and enable the input filter */
    pcnt_set_filter_value(pcntUnit, 255);
    pcnt_filter_enable(pcntUnit);

    /* Set threshold 0 and 1 values and enable events to watch */
    pcnt_set_event_value(pcntUnit, PCNT_EVT_THRES_1, PCNT_THRESH1_VAL);
    pcnt_event_enable(pcntUnit, PCNT_EVT_THRES_1);
    pcnt_set_event_value(pcntUnit, PCNT_EVT_THRES_0, PCNT_THRESH0_VAL);
    pcnt_event_enable(pcntUnit, PCNT_EVT_THRES_0);
    /* Enable events on zero, maximum and minimum limit values */
    pcnt_event_enable(pcntUnit, PCNT_EVT_ZERO);
    pcnt_event_enable(pcntUnit, PCNT_EVT_H_LIM);
    pcnt_event_enable(pcntUnit, PCNT_EVT_L_LIM);

    /* Initialize PCNT's counter */
    pcnt_counter_pause(pcntUnit);
    pcnt_counter_clear(pcntUnit);

    /* Everything is set up, now go to counting */
    pcnt_counter_resume(pcntUnit);
}
MotorEncoder::MotorEncoder(uint8_t index){
    if(index >= 1 && index <= 8)
        counterIndex = index - 1;
    else //wrong input encoder slot
        counterIndex = 0;

    // Initialize PCNT functions
    pcnt_init(pcntUnits[counterIndex], encPins[2*counterIndex], encPins[2*counterIndex + 1]);
    gpioInputPinSel = gpioInputPinSel | (1ULL<<encPins[2*counterIndex]);

    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = static_cast<gpio_int_type_t>(GPIO_PIN_INTR_DISABLE);
    //interrupt of rising edge
    io_conf.intr_type = GPIO_INTR_POSEDGE;  //ANYEDGE gives oscillating time differences in engine rotor half turns
    //bit mask of the pins
    io_conf.pin_bit_mask = gpioInputPinSel;
    //set as input mode
    io_conf.mode = GPIO_MODE_INPUT;
    //enable pull-up mode - unconnected GPIOs tend to invoke interrupts unintentionally
    io_conf.pull_up_en = static_cast<gpio_pullup_t>(1);
    gpio_config(&io_conf);

    //install gpio isr service
    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    //hook isr handler for specific gpio pins
    gpio_isr_handler_add(static_cast<gpio_num_t>(encPins[2*counterIndex]), gpio_isr_handler, (void*)&counterTimeData);   //interrupts use counter index 0-7 instead of invoking GPIO pin number

    PCNT_count = 0;
    counterTimeData.counterTimeDiff = 0;
    counterTimeData.counterPrevTime = 0;
    counterTimeData.aCounterIndex = counterIndex;
}
int32_t MotorEncoder::getCount(){
        //return number of MotorEncoder increments with resolution 2 increments per revolution
        pcnt_get_counter_value(pcntUnits[counterIndex], &PCNT_internal_count);
        pcnt_counter_clear(pcntUnits[counterIndex]);
        PCNT_count += PCNT_internal_count;
        return PCNT_count;
    }
float MotorEncoder::getFrequency(){
        //return motor axis frequency in [Hz]
        if(esp_timer_get_time() > (counterTimeData.counterPrevTime + MAX_ENGINE_PERIOD))
            frequency = 0.0;
        else if(abs(counterTimeData.counterTimeDiff) < MIN_ENGINE_PERIOD){
            frequency = 0.0;
            counterTimeData.counterTimeDiff = 0;
        }
        else
            frequency = 1000000.0 / counterTimeData.counterTimeDiff;
        return frequency; 
    }