#include <Arduino.h>
#include <i2s_parallel.h>
#include <format.h>
using fmt::print;

#include "hexdump.h"
#include "serialpcm.hpp"

void setup() {
    Serial.begin(115200);
    print(Serial, "\n\nESP32 serial PWM test\n\t{} {}\n\n", __DATE__, __TIME__);
    const int channels = 8;
    SerialPCM pwm {channels, {21}, 23, 22, 19};
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
                pwm[pwmi] = (c - '0') * pwm.resolution() / 10;
                print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                pwm.update();
                break;
            case '*':
                pwm[pwmi] = pwm.resolution();
                print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                pwm.update();
                break;
            case '+':
                if (pwm[pwmi] < pwm.resolution())
                    ++pwm[pwmi];
                print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                pwm.update();
                break;
            case '-':
                if (pwm[pwmi] > 0)
                    --pwm[pwmi];
                print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                pwm.update();
                break;

            case '<':
                if (pwmi > 0)
                    --pwmi;
                print("channel {}\n", pwmi);
                print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                break;
            case '>':
                if (pwmi < (channels - 1))
                    ++pwmi;
                print("channel {}\n", pwmi);
                print(Serial, "pwm[{}] = {:3}\n", pwmi, pwm[pwmi]);
                break;
            }
        }
    }
}

void loop() {}