#define STEPPER_OX_PIN_1 5
#define STEPPER_OX_PIN_2 6
#define STEPPER_OX_PIN_3 7
#define STEPPER_OX_PIN_4 8

#define STEPPER_OY_PIN_1 10
#define STEPPER_OY_PIN_2 11
#define STEPPER_OY_PIN_3 12
#define STEPPER_OY_PIN_4 13

#define OX A4
#define OY A5
#define BTN 4

#define clockWise true
#define aClockWise false

double x = 0;
double y = 0;

void setMotors() {
    pinMode(STEPPER_OX_PIN_1, OUTPUT);
    pinMode(STEPPER_OX_PIN_2, OUTPUT);
    pinMode(STEPPER_OX_PIN_3, OUTPUT);
    pinMode(STEPPER_OX_PIN_4, OUTPUT);

    pinMode(STEPPER_OY_PIN_1, OUTPUT);
    pinMode(STEPPER_OY_PIN_2, OUTPUT);
    pinMode(STEPPER_OY_PIN_3, OUTPUT);
    pinMode(STEPPER_OY_PIN_4, OUTPUT);
}

int step_OX_number = 0;
void OneStepOX(bool dir) {
    if (dir) {
        switch (step_OX_number) {
        case 0:
            digitalWrite(STEPPER_OX_PIN_1, HIGH);
            digitalWrite(STEPPER_OX_PIN_2, LOW);
            digitalWrite(STEPPER_OX_PIN_3, LOW);
            digitalWrite(STEPPER_OX_PIN_4, LOW);
            break;
        case 1:
            digitalWrite(STEPPER_OX_PIN_1, LOW);
            digitalWrite(STEPPER_OX_PIN_2, HIGH);
            digitalWrite(STEPPER_OX_PIN_3, LOW);
            digitalWrite(STEPPER_OX_PIN_4, LOW);
            break;
        case 2:
            digitalWrite(STEPPER_OX_PIN_1, LOW);
            digitalWrite(STEPPER_OX_PIN_2, LOW);
            digitalWrite(STEPPER_OX_PIN_3, HIGH);
            digitalWrite(STEPPER_OX_PIN_4, LOW);
            break;
        case 3:
            digitalWrite(STEPPER_OX_PIN_1, LOW);
            digitalWrite(STEPPER_OX_PIN_2, LOW);
            digitalWrite(STEPPER_OX_PIN_3, LOW);
            digitalWrite(STEPPER_OX_PIN_4, HIGH);
            break;
        }
    } else {
        switch (step_OX_number) {
        case 0:
            digitalWrite(STEPPER_OX_PIN_1, LOW);
            digitalWrite(STEPPER_OX_PIN_2, LOW);
            digitalWrite(STEPPER_OX_PIN_3, LOW);
            digitalWrite(STEPPER_OX_PIN_4, HIGH);
            break;
        case 1:
            digitalWrite(STEPPER_OX_PIN_1, LOW);
            digitalWrite(STEPPER_OX_PIN_2, LOW);
            digitalWrite(STEPPER_OX_PIN_3, HIGH);
            digitalWrite(STEPPER_OX_PIN_4, LOW);
            break;
        case 2:
            digitalWrite(STEPPER_OX_PIN_1, LOW);
            digitalWrite(STEPPER_OX_PIN_2, HIGH);
            digitalWrite(STEPPER_OX_PIN_3, LOW);
            digitalWrite(STEPPER_OX_PIN_4, LOW);
            break;
        case 3:
            digitalWrite(STEPPER_OX_PIN_1, HIGH);
            digitalWrite(STEPPER_OX_PIN_2, LOW);
            digitalWrite(STEPPER_OX_PIN_3, LOW);
            digitalWrite(STEPPER_OX_PIN_4, LOW);
        }
    }
    step_OX_number++;
    if (step_OX_number > 3) {
        step_OX_number = 0;
    }
}

int step_OY_number = 0;
void OneStepOY(bool OY) {
    if (OY) {
        switch (step_OY_number) {
        case 0:
            digitalWrite(STEPPER_OY_PIN_1, HIGH);
            digitalWrite(STEPPER_OY_PIN_2, LOW);
            digitalWrite(STEPPER_OY_PIN_3, LOW);
            digitalWrite(STEPPER_OY_PIN_4, LOW);
            break;
        case 1:
            digitalWrite(STEPPER_OY_PIN_1, LOW);
            digitalWrite(STEPPER_OY_PIN_2, HIGH);
            digitalWrite(STEPPER_OY_PIN_3, LOW);
            digitalWrite(STEPPER_OY_PIN_4, LOW);
            break;
        case 2:
            digitalWrite(STEPPER_OY_PIN_1, LOW);
            digitalWrite(STEPPER_OY_PIN_2, LOW);
            digitalWrite(STEPPER_OY_PIN_3, HIGH);
            digitalWrite(STEPPER_OY_PIN_4, LOW);
            break;
        case 3:
            digitalWrite(STEPPER_OY_PIN_1, LOW);
            digitalWrite(STEPPER_OY_PIN_2, LOW);
            digitalWrite(STEPPER_OY_PIN_3, LOW);
            digitalWrite(STEPPER_OY_PIN_4, HIGH);
            break;
        }
    } else {
        switch (step_OY_number) {
        case 0:
            digitalWrite(STEPPER_OY_PIN_1, LOW);
            digitalWrite(STEPPER_OY_PIN_2, LOW);
            digitalWrite(STEPPER_OY_PIN_3, LOW);
            digitalWrite(STEPPER_OY_PIN_4, HIGH);
            break;
        case 1:
            digitalWrite(STEPPER_OY_PIN_1, LOW);
            digitalWrite(STEPPER_OY_PIN_2, LOW);
            digitalWrite(STEPPER_OY_PIN_3, HIGH);
            digitalWrite(STEPPER_OY_PIN_4, LOW);
            break;
        case 2:
            digitalWrite(STEPPER_OY_PIN_1, LOW);
            digitalWrite(STEPPER_OY_PIN_2, HIGH);
            digitalWrite(STEPPER_OY_PIN_3, LOW);
            digitalWrite(STEPPER_OY_PIN_4, LOW);
            break;
        case 3:
            digitalWrite(STEPPER_OY_PIN_1, HIGH);
            digitalWrite(STEPPER_OY_PIN_2, LOW);
            digitalWrite(STEPPER_OY_PIN_3, LOW);
            digitalWrite(STEPPER_OY_PIN_4, LOW);
        }
    }

    if (step_OY_number == 3) {
        step_OY_number = 0;
    } else {
        step_OY_number++;
    }
}

void dreapta() {
    OneStepOX(aClockWise);
    OneStepOY(aClockWise);
    delay(2);
    x += 0.1;
}

void stanga() {
    OneStepOX(clockWise);
    OneStepOY(clockWise);
    delay(2);
    x -= 0.1;
}

void sus() {
    OneStepOX(clockWise);
    OneStepOY(aClockWise);
    delay(2);
    y += 0.1;
}

void jos() {
    OneStepOX(aClockWise);
    OneStepOY(clockWise);
    delay(2);
    y -= 0.1;
}
