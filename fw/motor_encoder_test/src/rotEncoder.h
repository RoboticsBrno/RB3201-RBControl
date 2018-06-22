#ifndef _ROTAS5306B_
#define _ROTAS5306B_

#ifdef __cplusplus
extern "C" {
#endif
//*************************************************************** Lib begin
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

#include <driver/adc.h>
#include "esp_system.h"

#define PCNT_WHEEL_1      PCNT_UNIT_0
#define PCNT_WHEEL_2      PCNT_UNIT_1
#define PCNT_WHEEL_3      PCNT_UNIT_2
#define PCNT_WHEEL_4      PCNT_UNIT_3

const pcnt_unit_t pcntUnits[8] = {
    PCNT_UNIT_0,    //motor1
    PCNT_UNIT_1,    //motor2
    PCNT_UNIT_2, 
    PCNT_UNIT_3, 
    PCNT_UNIT_4, 
    PCNT_UNIT_5, 
    PCNT_UNIT_6, 
    PCNT_UNIT_7
};

#define PCNT_WHEEL_1_SIG_A   32  // Pulse Input GPIO 32
#define PCNT_WHEEL_1_SIG_B   33  // Control GPIO 33
#define PCNT_WHEEL_2_SIG_A   25  // Pulse Input GPIO 25
#define PCNT_WHEEL_2_SIG_B   26  // Control GPIO 26
#define PCNT_WHEEL_3_SIG_A   27  // Pulse Input GPIO
#define PCNT_WHEEL_3_SIG_B   14  // Control GPIO
#define PCNT_WHEEL_4_SIG_A   17  // Pulse Input GPIO
#define PCNT_WHEEL_4_SIG_B   13  // Control GPIO

const uint8_t pcntPins[16] = {
    32, 33,     //motor1
    25, 26,     //motor2
    27, 14, 
    17, 13
};

#define PCNT_H_LIM_VAL      32767
#define PCNT_L_LIM_VAL     -32768
#define PCNT_THRESH1_VAL    32766
#define PCNT_THRESH0_VAL   -32767
#define INC_PER_REVOLUTION  2//2880    //PCNT increments per 1 wheel revolution

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
    for( uint8_t i = 0; i < 4; ++i){
        pcnt_example_init(pcntUnits[i], pcntPins[2*i], pcntPins[2*i + 1]);
    }
}
void updateWheelCounters(int16_t * aCounterWheel, float * aFreqWheel, uint16_t aMeasureTaskPeriod){
    for( uint8_t i = 0; i < 4; ++i){
        pcnt_get_counter_value(pcntUnits[i], &aCounterWheel[i]);        
    }

    for( uint8_t i = 0; i < 4; ++i){
        pcnt_counter_clear(pcntUnits[i]);
    }

    for(uint8_t i = 0; i < 4; ++i)
        {
            aFreqWheel[i] = 1000 * (float)aCounterWheel[i] / (INC_PER_REVOLUTION * aMeasureTaskPeriod);
        }
}

//*************************************************************** Lib end
#ifdef __cplusplus
}
#endif

#endif /* _I2C_DEVICES_ */