#include <Arduino.h>
#include <i2s_parallel.h>
//#include <format.h>
//using fmt::print;

#include "hexdump.h"
#include "serialpcm.hpp"

 void printPwm(int pwmi, const SerialPCM::value_type & pwm) {
     printf("pwm[%i] = %3i \n", pwmi, pwm);
 }

void setup() {
    Serial.begin(115200);
    //////print(Serial, "\n\nESP32 serial PWM test\n\t{} {}\n\n", __DATE__, __TIME__);
    printf("\n\nESP32 serial PWM test\n\t%s %s\n\n", __DATE__, __TIME__);
    const int channels = 16;
    SerialPCM pwm {channels, {2}, 0, 4};
    int pwmi = 0;
    for (int i = 0; i != channels; ++i)
        pwm[i] = i + 1;
    pwm.update();
    for (;;) {
        micros(); // update overflow
        if (Serial.available()) {
            char c = Serial.read();
            switch(c) {
            case '\r':
                Serial.write('\n');
                break;
            case '0' ... '9':
				// set pwm of selected channel:  0 = 0%, ... ,9 = 90% 
                pwm[pwmi] = (c - '0') * pwm.resolution() / 10;
                //print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                //printf("pwm[%i] = %3i \n", pwmi, pwm[pwmi]);
                printPwm(pwmi, pwm[pwmi]);
                pwm.update();
                break;
            case '*':
				// set pwm of selected channel: 100% 
                pwm[pwmi] = pwm.resolution();
                //print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                printPwm(pwmi, pwm[pwmi]);
                pwm.update();
                break;
            case '+':
                // increment pwm of selected channel: +1
                if (pwm[pwmi] < pwm.resolution())
                    ++pwm[pwmi];
                //print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                printPwm(pwmi, pwm[pwmi]);
                pwm.update();
                break;
            case '-':
                // decrement pwm of selected channel: -1
                if (pwm[pwmi] > 0)
                    --pwm[pwmi];
                //print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                printPwm(pwmi, pwm[pwmi]);
                pwm.update();
                break;
            case '<':
                // decrement index of channel
                if (pwmi > 0)
                    --pwmi;
                //print("channel {}\n", pwmi);
                printf("channel %2i\n", pwmi);
                //print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                printPwm(pwmi, pwm[pwmi]);
                break;
            case '>':
                // increment index of channel
                if (pwmi < (channels - 1))
                    ++pwmi;
                //print("channel {}\n", pwmi);
                printf("channel %2i\n", pwmi);
                //print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                printPwm(pwmi, pwm[pwmi]);
                break;
            case ' ':
                // set all channels to 0
                for(int i = 0; i < channels; ++i) {
                    pwm[i] = 0;  
                }
                pwm.update();
                //print(Serial, "all pwm[] = 0\n");
                printf("all pwm[] = 0\n");
                break;
            }
        }
    }
}

void loop() {}