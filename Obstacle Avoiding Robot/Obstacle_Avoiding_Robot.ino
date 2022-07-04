#include <Wire.h>

int trig = 4;
int echo = 3;
int rightforward = 9;
int rightdown = 10;
int leftforward = 6;
int leftdown = 5;
float duration, distance;

void setup() {
    Serial.begin(9600);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(rightforward, OUTPUT);
    pinMode(rightdown, OUTPUT);
    pinMode(leftforward, OUTPUT);
    pinMode(leftdown, OUTPUT);
}

void loop() {
    digitalWrite(trig, 0);
    delayMicroseconds(2);
    digitalWrite(trig, 1);
    delayMicroseconds(10);
    digitalWrite(trig, 0);

    duration = pulseIn(echo, 1);
    distance = (duration / 2) * .0343;

    Serial.print("distance= ");
    Serial.print(distance);
    Serial.print(" cm");

    delay(100);

    if (distance < 30) {
        Serial.println("\t Turn right");
        digitalWrite(leftforward, 190);
        digitalWrite(rightforward, 0);
        digitalWrite(leftdown, 0);
        digitalWrite(rightdown, 190);
    } else {
        Serial.println("\t Move forward");
        digitalWrite(leftforward, 255);
        digitalWrite(rightforward, 255);
        digitalWrite(leftdown, 0);
        digitalWrite(rightdown, 0);
    }
}
