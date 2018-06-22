#include <Servo.h>

static const int servosPins[] = {32, 33, 25, 26, 27, 14, 12, 13, 15, 16, 17, 5, 18, 19, 21};
static const int servosCnt = sizeof(servosPins)/sizeof(int);

Servo servos[servosCnt];

void setServos(int degrees) {
    for(int i = 0; i < servosCnt; ++i) {
        servos[i].write((degrees + ((180/servosCnt) * i)) % 180);
    }
}

void setup() {
    Serial.begin(115200);

    Serial.print("\n\tServo test - add pins: ");
    Serial.println(servosCnt);

    for(int i = 0; i < servosCnt; ++i) {
        if(!servos[i].attach(servosPins[i])) {
            Serial.print("Servo ");
            Serial.print(i);
            Serial.println("attach error");
        }
    }
}

void loop() {
    for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
        setServos(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }

    for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
        setServos(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }
}