#include "motors.h"
#include "led.h"

int drawState = 0;
int origine = 0;
int pas = 0;

#define yLimUp(lim) if (y < lim) sus(); else pas += 1; break;
#define yLimDown(lim) if (y > lim) jos(); else pas += 1; break;

#define xLimRight(lim) if (x < lim) dreapta(); else pas += 1; break;
#define xLimLeft(lim) if (x > lim) stanga(); else pas += 1; break;

void desen2() {
    setLed(0, 255, 255);
    // prima oara ne transportam in origine
    if (x <= 0 && y <= 0 && origine == 0) {
        x = 0;
        y = 0;
        origine = 1;
        pas = 0;
    }

    if (origine == 0) {
        if (x > 0) {
            stanga();
        } else if (y > 0) {
            jos();
        } else if (x <= 0 && y <= 0) {
            origine = 1;
            pas = 0;
            x = 0;
            y = 0;
        }

    } else if (origine == 1) {
        Serial.println(pas);
        switch (pas) {
            
            case 0:
                yLimUp(350);
            case 1:
                xLimRight(300);
            case 2:
                yLimDown(0);
            case 3:
                xLimLeft(0);
            case 4:
                xLimRight(790);
            case 5:
                yLimUp(450);
            case 6:
                xLimLeft(0);
            case 7:
                yLimUp(600);
            case 8:
                xLimRight(300);
            case 9:
                yLimUp(700);
            case 10:
                xLimLeft(0);
            case 11:
                yLimUp(850);
            case 12:
                xLimRight(790);
            case 13:
                yLimUp(950);
            case 14:
                xLimLeft(0);
            case 15:
                yLimUp(1300);
            case 16:
                yLimDown(950);
            case 17:
                xLimRight(300);
            case 18:
                yLimUp(1125); 
            case 19:
                yLimDown(950);
            case 20:
                xLimRight(790);
            default:
                if (drawState == 2)
                    drawState = 0;
                else 
                    drawState += 1;
                origine = 0;
                pas = 0;
                break;
        }
    }
}

void desen1() {
    setLed(255, 0, 255);
    // prima oara ne transportam in origine
    if (x <= 0 && y <= 0) {
        x = 0;
        y = 0;
        origine = 1;
        pas = 0;
    }

    if (origine == 0) {
        if (x > 0) {
            stanga();
        } else if (y > 0) {
            jos();
        } else if (x <= 0 && y <= 0) {
            origine = 1;
            x = 0;
            y = 0;
        }

    } else if (origine == 1) {
        switch (pas) {
            case 0:
                xLimRight(790);
            case 1:
                yLimUp(50);
            case 2:
                xLimLeft(0);
            case 3:
                yLimUp(100);
            case 4:
                xLimRight(790);
            case 5:
                yLimUp(150);
            case 6:
                xLimLeft(0);
            case 7:
                yLimUp(200);
            case 8:
                xLimRight(790);
            case 9:
                yLimUp(250);
            case 10:
                xLimLeft(0);
            case 11:
                yLimUp(300);
            case 12:
                xLimRight(790);
            case 13:
                yLimUp(350);
            case 14:
                xLimLeft(0);
            case 15:
                yLimUp(400);
            case 16:
                xLimRight(790);
            case 17:
                yLimUp(450);
            case 18:
                xLimLeft(0);
            case 19:
                yLimUp(500);
            case 20:
                xLimRight(790);
            case 21:
                yLimUp(550);
            case 22:
                xLimLeft(0);
            case 23:
                yLimUp(600);
            case 24:
                xLimRight(790);
            case 25:
                yLimUp(650);
            case 26:
                xLimLeft(0);
            case 27:
                yLimUp(700);
            case 28:
                xLimRight(790);
            case 29:
                yLimUp(750);
            case 30:
                xLimLeft(0);
            case 31:
                yLimUp(800);
            case 32:
                xLimRight(790);
            case 33:
                yLimUp(850);
            case 34:
                xLimLeft(0);
            case 35:
                yLimUp(900);
            case 36:
                xLimRight(790);
            case 37:
                yLimUp(950);
            case 38:
                xLimLeft(0);
            case 39:
                yLimUp(1000);
            case 40:
                xLimRight(790);
            case 41:
                yLimUp(1050);
            case 42:
                xLimLeft(0);
            case 43:
                yLimUp(1100);
            case 44:
                xLimRight(790);
            case 45:
                yLimUp(1150);
            case 46:
                xLimLeft(0);
            case 47:
                yLimUp(1200);
            case 48:
                xLimRight(790);
            case 49:
                yLimUp(1250);
            case 50:
                xLimLeft(0);
            case 51:
                yLimUp(1300);
            case 52:
                xLimRight(790);
            case 53:
                yLimUp(1350);
            case 54:
                xLimLeft(0);
            case 55:
                yLimUp(1400);
            case 56:
                xLimRight(790);
            case 57:
                yLimUp(1450);
            case 58:
                xLimLeft(0);
            case 59:
                yLimUp(1500);
            case 60:
                xLimRight(790);
            case 61:
                yLimUp(1550);
            case 62:
                xLimLeft(0);
            case 63:
                yLimUp(1600);
            case 64:
                xLimRight(790);
            default:
                if (drawState == 2)
                    drawState = 0;
                else 
                    drawState += 1;
                origine = 0;
                pas = 0;
                break;
        }
    }
}

void joystick() {
    setLed(255,255,255);
  
    double xJoy = analogRead(OX);
    double yJoy = analogRead(OY);
    
    // diagonal jos-stanga
    if (xJoy < 100 && yJoy > 650) {}
    
    // diagonal sus-stanga
    else if (xJoy < 100 && yJoy < 100) {}
    
    // diagonal sus-dreapta
    else if (xJoy > 650 && yJoy < 100) {}
    
    // diagonal jos-dreapta
    else if (xJoy > 650 && yJoy > 650) {}

    else if (yJoy > 650){
        setLed(255,255,0);
        jos(); 
    }
        
        
    else if (yJoy < 100){
        setLed(255,255,0);
        sus(); 
    }

    else if (xJoy > 650){
        setLed(255,255,0);
        dreapta(); 
    }

    else if (xJoy < 100) {
        setLed(255,255,0);
        stanga(); 
    }
}
