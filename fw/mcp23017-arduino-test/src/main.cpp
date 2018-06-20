#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_MCP23017.h"

// Basic pin reading and pullup test for the MCP23017 I/O expander
// public domain!

// Connect pin #12 of the expander to Analog 5 (i2c clock)
// Connect pin #13 of the expander to Analog 4 (i2c data)
// Connect pins #15, 16 and 17 of the expander to ground (address selection)
// Connect pin #9 of the expander to 5V (power)
// Connect pin #10 of the expander to ground (common ground)
// Connect pin #18 through a ~10kohm resistor to 5V (reset pin, active low)

// Input #0 is on pin 21 so connect a button or switch from there to ground

Adafruit_MCP23017 mcp;
  
static const int i2c_addr = 1;
static const int i2c_sda = 23;
static const int i2c_scl = 22;

static const int ea0 = 0;
static const int ea1 = 1;
static const int ea2 = 2;
static const int ea3 = 3;
static const int ea4 = 4;
static const int ea5 = 5;
static const int ea6 = 6;
static const int ea7 = 7;

static const int eb0 = 8;
static const int eb1 = 9;
static const int eb2 = 10;
static const int eb3 = 11;
static const int eb4 = 12;
static const int eb5 = 13;
static const int eb6 = 14;
static const int eb7 = 15;

static const int sw1 = eb0;
static const int sw2 = eb1;
static const int sw3 = eb2;
static const int led1 = eb3;
static const int led2 = eb4;
static const int led3 = eb5;
static const int led4 = eb6;
static const int esp_shutdown = eb7;

static const int delay_change = 500;

void setup() {  
    // Init
    mcp.begin(i2c_addr, i2c_sda, i2c_scl);

    mcp.pinMode(ea0, OUTPUT);
    mcp.pinMode(ea1, OUTPUT);
    mcp.pinMode(ea2, OUTPUT);
    mcp.pinMode(ea3, OUTPUT);
    mcp.pinMode(ea4, OUTPUT);
    mcp.pinMode(ea5, OUTPUT);
    mcp.pinMode(ea6, OUTPUT);
    mcp.pinMode(ea7, OUTPUT);

    mcp.pinMode(sw1, INPUT);
    mcp.pullUp(sw1, HIGH);
    mcp.pinMode(sw2, INPUT);
    mcp.pullUp(sw2, HIGH);
    mcp.pinMode(sw3, INPUT);
    mcp.pullUp(sw3, HIGH);
    mcp.pinMode(led1, OUTPUT);
    mcp.pinMode(led2, OUTPUT);
    mcp.pinMode(led3, OUTPUT);
    mcp.pinMode(led4, OUTPUT);

    Serial.begin(115200);

    // Setup test
    Serial.println("\n\n\tMCP23017 test\n");
    Serial.println("Led1");
    mcp.digitalWrite(led1, HIGH);
    delay(delay_change);
    mcp.digitalWrite(led1, LOW);
    delay(delay_change);

    Serial.println("Led2");  
    mcp.digitalWrite(led2, HIGH);
    delay(delay_change);
    mcp.digitalWrite(led2, LOW);
    delay(delay_change);

    Serial.println("Led3");
    mcp.digitalWrite(led3, HIGH);
    delay(delay_change);
    mcp.digitalWrite(led3, LOW);
    delay(delay_change);

    Serial.println("Led4");
    mcp.digitalWrite(led4, HIGH);
    delay(delay_change);
    mcp.digitalWrite(led4, LOW);
    delay(delay_change);
}

void loop() {
    mcp.digitalWrite(led2, LOW);
    mcp.digitalWrite(led3, LOW);
    mcp.digitalWrite(led4, LOW);
    if(mcp.digitalRead(sw1) == false) {
        mcp.digitalWrite(led4, HIGH);
    }
    if(mcp.digitalRead(sw2) == false) {
        mcp.digitalWrite(led3, HIGH);
    }
    if(mcp.digitalRead(sw3) == false) {
        mcp.digitalWrite(led2, HIGH);
    }

    delay(100);

    Serial.println("High");
    mcp.digitalWrite(ea0, HIGH);
    mcp.digitalWrite(ea1, HIGH);
    mcp.digitalWrite(ea2, HIGH);
    mcp.digitalWrite(ea3, HIGH);
    mcp.digitalWrite(ea4, HIGH);
    mcp.digitalWrite(ea5, HIGH);
    mcp.digitalWrite(ea6, HIGH);
    mcp.digitalWrite(ea7, HIGH);
    
    mcp.digitalWrite(led1, HIGH);

    delay(100);

    Serial.println("Low");
    mcp.digitalWrite(ea0, LOW);
    mcp.digitalWrite(ea1, LOW);
    mcp.digitalWrite(ea2, LOW);
    mcp.digitalWrite(ea3, LOW);
    mcp.digitalWrite(ea4, LOW);
    mcp.digitalWrite(ea5, LOW);
    mcp.digitalWrite(ea6, LOW);
    mcp.digitalWrite(ea7, LOW);

    mcp.digitalWrite(led1, LOW);
}