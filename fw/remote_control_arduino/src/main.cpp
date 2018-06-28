#include <Arduino.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#include <i2s_parallel.h>
#include <format.h>
using fmt::print;


#include "hexdump.h"
#include "serialpcm.hpp"

#define ATOMS_NO_EXCEPTION
#include "avakar.h"

 void printPwm(int pwmi, const SerialPCM::value_type & pwm) {
     printf("pwm[%i] = %3i \n", pwmi, pwm);
 }

// channels
// M1: 12, 13
// M2: 2, 3 
// M3: 8, 9
// M4: 14, 15    
// M5: 4, 5
// M6: 10, 11
// M7: 1, 2
// M8: 6, 7 
// M: 12, 13, 2, 3, 8, 9, 14, 15, 4, 5, 10, 11, 1, 2, 6, 7

int clamp(int val, int min, int max) {
    if(val < min) {
        return min;
    } else if (val > max) {
        return max;
    }
    return val;
}

void motorPwmSet(SerialPCM::value_type & pwm0, SerialPCM::value_type & pwm1, int power) {
    int _power = clamp(power, 0, 255);
    
    if(power > 0) {
        pwm0 = 0;
        pwm1 = _power;
    } else {
        pwm0 = _power;
        pwm1 = 0;
    }
}

BluetoothSerial SerialBT;

void setup() {
    Serial.begin(115200);
    print(Serial, "\n\nMickoflus BT test\n\t{} {}\n\n", __DATE__, __TIME__);

    if (!SerialBT.begin("Mickoflus")) //Bluetooth device name
        print(Serial, "!!! Bluetooth initialization failed!\n");
    
    const int channels = 16;

    // After uncomment get exception in terminal from ESP32 
    SerialPCM pwm {channels, {2}, 0, 12};
    // int pwmi = 0;
    // for (int i = 0; i != channels; ++i)
    //     pwm[i] = 0;
    // pwm.update();

    atoms::AvakarPacket packet;

    int axe[4];
    int lmot, rmot;

    for (;;) {
        micros(); // update overflow
        if (SerialBT.available()) {
            char c = SerialBT.read();
            //Serial.write(c);
            
            if(packet.push_byte(c)) {
                if((int)packet.get_command() == 1) { //&& (int)in.size() == 9) {
                    for(int i = 0; i < 4; ++i) {
                        axe[i] = (packet.get<int16_t>(i*2))>>8;
                        //print(Serial, "{:6}", axe[i]);
                    }
                    Serial.println();

                    lmot = axe[0]/2 + axe[1]/2;
                    rmot = axe[0]/2 - axe[1]/2;

                    // motorPwmSet(pwm[12], pwm[13], lmot);
                    // motorPwmSet(pwm[2], pwm[3], rmot);
                    // pwm.update();

                    print(Serial, "{:3} {:3}\n", lmot, rmot);

                    packet.clear();
                }
            }
        }
    }
}

void loop() {}