#include <Arduino.h>

static const int IO25 = 25;
static const int IO32 = 32;
static const int IO33 = 33;
static const int IO34 = 34;
static const int IO35 = 35;

static const int ENC7A = IO25;
static const int ENC7B = IO33;

static const int power_off = IO32;
static const int batt_ref = IO34;
// 6 V - 0,646 V = 666
// 6,5 V - 0,7 V = 732
// 7 V - 0,752 V = 800
// 7,5 V - 0,79 V = 866
// 8 V - 0,85 V = 934
// 8,5 V - 0,9 V = 1008
// 9 V - 0,97 V = 1080
// 9,5 V - 1,013 V = 1136
// 10 V - 1,076 V = 1215

static const int piezoA = ENC7A;
static const int piezoB = ENC7B;
static const int piezoLedcChannel = 0;

void piezoInit() {
    pinMode(piezoA, OUTPUT);
    pinMode(piezoB, OUTPUT);

    digitalWrite(piezoB, HIGH);
    ledcAttachPin(piezoA, piezoLedcChannel);
}

void piezoWriteTone(double freq) {
    ledcWriteTone(piezoLedcChannel, freq);
}

void powerManagementInit() {
    digitalWrite(power_off, HIGH);
    pinMode(power_off, OUTPUT);

    piezoInit();
}

void powerOff() {
    digitalWrite(power_off, LOW);
}

void setup() {
    Serial.begin(115200);
    Serial.printf("\n\tRB3201 - power management arduino test");

    delay(500);
    powerManagementInit();
    piezoWriteTone(444);
}

void loop() {
    delay(200);
    Serial.print("batt_ref: ");
    Serial.print(analogRead(batt_ref));
    Serial.print("\n");
}