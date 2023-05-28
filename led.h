#define GREEN A0
#define RED A1
#define BLUE A2

void setLed(int r, int g, int b) {
    analogWrite(RED, r);
    analogWrite(GREEN, g);
    analogWrite(BLUE, b);
}

void setupLed() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    setLed(0,0,0);
}
