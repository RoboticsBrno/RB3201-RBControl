#ifndef _MOTOR_ENCODER_
#define _MOTOR_ENCODER_s

#ifdef __cplusplus
extern "C" {
#endif
//*************************************************************** Lib begin
#include "driver/pcnt.h"

#define COUNTERS_NUMBER 2    //number of engine counters being used
#define PCNT_H_LIM_VAL      32767
#define PCNT_L_LIM_VAL     -32768
#define PCNT_THRESH1_VAL    32766
#define PCNT_THRESH0_VAL   -32767
#define INC_PER_REVOLUTION  2//2880    //PCNT increments per 1 wheel revolution
#define ESP_INTR_FLAG_DEFAULT 0
#define ENC_DEBOUNCE_US 20 //[microseconds]

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

extern volatile uint64_t counterPrevTime[COUNTERS_NUMBER];   //prev time of pulse interrupt call
extern volatile uint32_t counterTimeDiff[COUNTERS_NUMBER];   //time difference of pulse interrupt calls

static void IRAM_ATTR gpio_isr_handler(void* arg);
static void pcnt_example_init(pcnt_unit_t pcntUnit, uint8_t GPIO_A, uint8_t GPIO_B);
void initWheelCounters();
void updateWheelCounters(int16_t * aCounterWheel, float * aFreqWheel, uint16_t aMeasureTaskPeriod);
void hookInterruptPins();
//*************************************************************** Lib end
#ifdef __cplusplus
}
#endif

#endif /* _I2C_DEVICES_ */