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

#define PRINT_WARNING(x) do {Serial.print("[Warning] "); Serial.println(x);} while(false)

class Joystick {   
    int m_axe[4] = {0};
    int m_buttons = 0;
    atoms::AvakarPacket packet;

public:
    bool onByte(int byte) {
        if(byte == -1) {
            PRINT_WARNING("Byte is -1. Check if you are not reading empty stream/Serial/...");
        }
        if(packet.push_byte(byte)) {
            if((packet.get_command() == 1) && (packet.size() == 9)) {
                for(int i = 0; i < 4; ++i) {
                    m_axe[i] = packet.get<int16_t>(i*2);
                }
                m_buttons = packet.get<uint8_t>(8);
                packet.clear();
                return true;
            } else {
                PRINT_WARNING("Unknown packet");
            }
        }
        return false;
    }

    int axe(int index) {
        if(index < 0 || index > 3) {
            PRINT_WARNING("axe index - out of range");
            return 0;
        }
        return m_axe[index];
    }

    int buttons() {
        return m_buttons;
    }

    bool button(int index) {
        if(index < 0 || index > 7) {
            PRINT_WARNING("button index - out of range");
            return false;
        }
        return m_buttons & (1 << index);
    }
};

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
    power = clamp(power, -255, 255);
    
    if(power > 0) {
        pwm0 = 0;
        pwm1 = power;
    } else {
        pwm0 = -power;
        pwm1 = 0;
    }
}

BluetoothSerial SerialBT;

void setup() {
    Serial.begin(115200);
    print(Serial, "\n\nMickoflus BT control test\n\t{} {}\n\n", __DATE__, __TIME__);

    if (!SerialBT.begin("Mickoflus01")) { //Bluetooth device name
        print(Serial, "!!! Bluetooth initialization failed!\n");
    }

    const int channels = 16;
    // After uncomment get exception in terminal from ESP32 
    SerialPCM pwm {channels, {2}, 0, 12};
    // int pwmi = 0;
    // for (int i = 0; i != channels; ++i)
    //     pwm[i] = 0;
    // pwm.update();

    Joystick joy;
    int lmot, rmot;
    int axe[2];

    for (;;) {
        micros(); // update overflow
        if (SerialBT.available()) {
            char c = SerialBT.read();
            //Serial.write(c);
            
            if(joy.onByte(c)) {         
                axe[0] = joy.axe(0) >> 7;
                axe[1] = joy.axe(1) >> 7; 
                lmot = axe[0] + axe[1];
                rmot = axe[0] - axe[1];

                motorPwmSet(pwm[12], pwm[13], lmot);
                motorPwmSet(pwm[2], pwm[3], rmot);
                pwm.update();

                print(Serial, "{:3} {:3}\n", lmot, rmot);
            }
        }
    }
}

void loop() {}