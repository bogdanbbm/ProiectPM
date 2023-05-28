#include "desene.h"

int btn;
int lastbtn;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 500; // Adjust debounce delay as needed

void setup() {
    setMotors();
    setupLed();
    
    attachInterrupt(digitalPinToInterrupt(BTN), buttonInterrupt, CHANGE);
    Serial.begin(115200);
}

void buttonInterrupt() {
    if (millis() - lastDebounceTime >= debounceDelay) {
        if (drawState == 2)
            drawState = 0;
        else 
            drawState += 1;
        origine = 0;
        lastDebounceTime = millis();
    }
}

void loop() {

    Serial.print("x = ");
    Serial.println(x);
    Serial.print("y = ");
    Serial.println(y);
    Serial.println();
    
    switch(drawState) {
        case 0:
            joystick();
            break;
        case 1:
            desen1();
            break;
        case 2:
            desen2();
            break;
    }
}
