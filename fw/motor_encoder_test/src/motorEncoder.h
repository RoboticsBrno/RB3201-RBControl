#ifndef _MOTOR_ENCODER_
#define _MOTOR_ENCODER_s

#ifdef __cplusplus
extern "C" {
#endif
//*************************************************************** Lib begin
#include "driver/pcnt.h"

#define ENGINES_NUMBER 8    //number of engines being measured
#define PCNT_H_LIM_VAL      32767
#define PCNT_L_LIM_VAL     -32768
#define PCNT_THRESH1_VAL    32766
#define PCNT_THRESH0_VAL   -32767
#define INC_PER_REVOLUTION  2//2880    //PCNT increments per 1 wheel revolution

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

static void pcnt_example_init(pcnt_unit_t pcntUnit, uint8_t GPIO_A, uint8_t GPIO_B);
void initWheelCounters();
void updateWheelCounters(int16_t * aCounterWheel, float * aFreqWheel, uint16_t aMeasureTaskPeriod);


//*************************************************************** Lib end
#ifdef __cplusplus
}
#endif

#endif /* _I2C_DEVICES_ */