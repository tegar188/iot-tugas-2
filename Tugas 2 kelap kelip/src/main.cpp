#include <Arduino.h>

#define RED_LED 12
#define YELLOW_LED 14
#define GREEN_LED 13
#define BTN1 22
#define BTN2 21
#define BTN3 19

void setup() {
    pinMode(RED_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(BTN1, INPUT_PULLUP);
    pinMode(BTN2, INPUT_PULLUP);
    pinMode(BTN3, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(BTN1) == LOW) {
        while (digitalRead(BTN2) == HIGH && digitalRead(BTN3) == HIGH) {
            digitalWrite(RED_LED, HIGH);
            delay(500);
            digitalWrite(RED_LED, LOW);
            delay(500);
        }
    }
    
    if (digitalRead(BTN2) == LOW) {
        while (digitalRead(BTN1) == HIGH && digitalRead(BTN3) == HIGH) {
            digitalWrite(RED_LED, HIGH);
            digitalWrite(GREEN_LED, LOW);
            delay(500);
            digitalWrite(RED_LED, LOW);
            digitalWrite(GREEN_LED, HIGH);
            delay(500);
        }
        digitalWrite(GREEN_LED, LOW);
    }
    
    if (digitalRead(BTN3) == LOW) {
        while (digitalRead(BTN1) == HIGH && digitalRead(BTN2) == HIGH) {
            digitalWrite(RED_LED, HIGH);
            delay(500);
            digitalWrite(RED_LED, LOW);
            digitalWrite(YELLOW_LED, HIGH);
            delay(500);
            digitalWrite(YELLOW_LED, LOW);
            digitalWrite(GREEN_LED, HIGH);
            delay(500);
            digitalWrite(GREEN_LED, LOW);
        }
    }
}

