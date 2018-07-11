/* MotorEncoder library and class serve for measuring frequency and counting revolutions of
a DC engine of a yellow geared Smart Chassis engine. The class is aimed to be used on Mickoflus
robotic platform with its MainBoard and MotorBoard hall sensor encoders with specifying index of 
encoder slot being used on MainBoard in object constructor, eg. "MotorEncoder encoder1(1);" is 
used for encoder connected to slot 1 (of 1-8) with quadrature signals A-GPIO 21, B-GPIO 19.
Pulse counter resolution is 2 increments per motor revolution. Motor frequency is calculated 
from duration of 1 last complete 360° motor axis revolution.  
*/
#ifndef _MOTOR_ENCODER_
#define _MOTOR_ENCODER_

#ifdef __cplusplus
extern "C" {
#endif
//*************************************************************** Lib begin
#include "driver/pcnt.h"

#define PCNT_H_LIM_VAL      32767
#define PCNT_L_LIM_VAL     -32768
#define PCNT_THRESH1_VAL    32766
#define PCNT_THRESH0_VAL   -32767
#define INC_PER_REVOLUTION  2       //PCNT increments per 1 engine revolution
#define ESP_INTR_FLAG_DEFAULT 0
#define ENC_DEBOUNCE_US 20          //[microseconds]
#define MAX_ENGINE_PERIOD 100000    //engine period limit separating zero result [us]
#define MIN_ENGINE_PERIOD 1000      //engine period limit separating zero results [us]

const pcnt_unit_t pcntUnits[8] = {
    PCNT_UNIT_0,    //engine1
    PCNT_UNIT_1,    //engine2
    PCNT_UNIT_2, 
    PCNT_UNIT_3, 
    PCNT_UNIT_4, 
    PCNT_UNIT_5, 
    PCNT_UNIT_6, 
    PCNT_UNIT_7
};
const uint8_t encPins[16] = {
    21, 19,     //engine1 - ENC1A, ENC1B
    18, 5,      //engine2 - ENC2A, ENC2B
    17, 16,     //engine3 - ENC3A, ENC3B
    15, 13,     //engine4 - ENC4A, ENC4B
    4, 14,      //engine5 - ENC5A, ENC5B
    27, 26,     //engine6 - ENC6A, ENC6B
    25, 33,     //engine7 - ENC7A, ENC7B
    32, 35      //engine8 - ENC8A, ENC8B
};
struct CounterTimeData{
        volatile int64_t counterPrevTime;   //prev time of pulse interrupt call
        volatile int32_t counterTimeDiff;   //time difference of pulse interrupt calls
        uint8_t aCounterIndex;
    };
class MotorEncoder{
    uint8_t counterIndex;   //0-7
    int16_t PCNT_internal_count;   //variable to store PCNT coming data, PCNT is only int16_t
    int32_t PCNT_count; //counter variable for external usage
    float frequency;
    static unsigned long long gpioInputPinSel;
    struct CounterTimeData counterTimeData;
    static void pcnt_init(pcnt_unit_t pcntUnit, uint8_t GPIO_A, uint8_t GPIO_B);
    static void IRAM_ATTR gpio_isr_handler(void* arg);
public:
    MotorEncoder(uint8_t index);    //motorEncoder slot index 1-8 as parameter
    int32_t getCount(); //return number of MotorEncoder increments with resolution 2 increments per revolution
    void clearCount(){
        //clear encoder counter value to set zero position
        PCNT_count = 0;
    }
    float getFrequency(); //return motor axis frequency in [Hz]
};
//*************************************************************** Lib end
#ifdef __cplusplus
}
#endif
#endif /* _MOTOR_ENCODER_ */