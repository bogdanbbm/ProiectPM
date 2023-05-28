#include "desene.h"

int btn;
int lastbtn;

void setup() {
    setMotors();

    pinMode(OX, INPUT_PULLUP);
    pinMode(OY, INPUT_PULLUP);
    pinMode(BTN, INPUT_PULLUP);

    setupLed();
    
    Serial.begin(115200);
}

void loop() {  
    
    Serial.print("x = ");
    Serial.println(x);
    Serial.print("y = ");
    Serial.println(y);
    Serial.println();
    
    btn = !digitalRead(BTN);
    if (btn == 1) {
        if (drawState == 2)
            drawState = 0;
        else 
            drawState += 1;
        origine = 0;
        Serial.println(drawState);
        delay(500);
    }

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
