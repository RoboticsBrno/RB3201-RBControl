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

unsigned long long gpioInputPinSel = 1;

static void IRAM_ATTR gpio_isr_handler(void* arg)
{
    int64_t currentTime = esp_timer_get_time();
    uint32_t counterIndex = (uint32_t) arg;
    if(currentTime > counterPrevTime[counterIndex] + ENC_DEBOUNCE_US){
        counterTimeDiff[counterIndex] = currentTime - counterPrevTime[counterIndex];
        counterPrevTime[counterIndex] = currentTime;
        xQueueSendFromISR(gpio_evt_queue, &counterIndex, NULL);
    }
}



/* Initialize PCNT functions:
 *  - configure and initialize PCNT
 *  - set up the input filter
 *  - set up the counter events to watch
 */
static void pcnt_example_init(pcnt_unit_t pcntUnit, uint8_t GPIO_A, uint8_t GPIO_B)
{
    /* Prepare configuration for the PCNT unit */
    /*pcnt_config_t pcnt_config = {
        // Set PCNT input signal and control GPIOs
        .pulse_gpio_num = GPIO_A,
        .ctrl_gpio_num = GPIO_B,
        .channel = PCNT_CHANNEL_0,
        .unit = pcntUnit,
        // What to do on the positive / negative edge of pulse input?
        .pos_mode = PCNT_COUNT_INC,   // Count up on the positive edge
        .neg_mode = PCNT_COUNT_DEC,   // Keep the counter value on the negative edge
        // What to do when control input is low or high?
        .lctrl_mode = PCNT_MODE_KEEP,  // Keep the primary counter mode if high
        .hctrl_mode = PCNT_MODE_REVERSE,   // Reverse counting direction if low 
        // Set the maximum and minimum limit values to watch
        .counter_h_lim = PCNT_H_LIM_VAL,
        .counter_l_lim = PCNT_L_LIM_VAL,
    };*/
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
void initWheelCounters(){
    /* Initialize PCNT functions */
    for( uint8_t i = 0; i < COUNTERS_NUMBER; ++i){
        pcnt_example_init(pcntUnits[i], encPins[2*i], encPins[2*i + 1]);
        gpioInputPinSel = gpioInputPinSel | (1ULL<<encPins[2*i]);
    }
    gpio_config_t io_conf;
    //disable interrupt
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    //interrupt of rising edge
    io_conf.intr_type = GPIO_INTR_POSEDGE;  //ANYEDGE gives oscillating time differences in engine rotor half turns
    //bit mask of the pins
    io_conf.pin_bit_mask = gpioInputPinSel;
    //set as input mode    
    io_conf.mode = GPIO_MODE_INPUT;
    //enable pull-up mode - unconnected GPIOs tend to invoke interrupts unintentionally
    io_conf.pull_up_en = 1;
    gpio_config(&io_conf);
}
void updateWheelCounters(int16_t * aCounterWheel, float * aFreqWheel, uint16_t aMeasureTaskPeriod){
    for( uint8_t i = 0; i < COUNTERS_NUMBER; ++i){
        pcnt_get_counter_value(pcntUnits[i], &aCounterWheel[i]);        
    }

    for( uint8_t i = 0; i < COUNTERS_NUMBER; ++i){
        pcnt_counter_clear(pcntUnits[i]);
    }

    for(uint8_t i = 0; i < COUNTERS_NUMBER; ++i)
        {
            aFreqWheel[i] = 1000 * (float)aCounterWheel[i] / (INC_PER_REVOLUTION * aMeasureTaskPeriod);
        }
}
void hookInterruptPins(){
    //install gpio isr service
    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    //hook isr handler for specific gpio pins
    for( uint8_t i = 0; i < 2*COUNTERS_NUMBER; i = i+2){
        gpio_isr_handler_add(encPins[i], gpio_isr_handler, (void*)(i/2));   //interrupts use counter index 0-7 instead of invoking GPIO pin number
    }
}