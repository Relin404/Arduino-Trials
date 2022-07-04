#include <Wire.h>

// Assigning left motor pins
int motorL1 = 6;
int motorL2 = 5;

// Assigning right motor pins
int motorR1 = 9;
int motorR2 = 10;

// Assigning IR sensors pins
int IR1 = 3;
int IR2 = 2;

// Declaring two commonly used variables
int sensorRight = 0;
int sensorLeft = 0;

void setup() {
    pinMode(motorL1, OUTPUT);
    pinMode(motorL2, OUTPUT);
    pinMode(motorR1, OUTPUT);
    pinMode(motorR2, OUTPUT);
    
    pinMode(IR1, INPUT);
    pinMode(IR2, INPUT);

    digitalWrite(IR1, LOW);
    digitalWrite(IR2, LOW);

    Serial.begin(9600);
}

void loop() {
    sensorLeft = digitalRead(IR1);
    sensorRight = digitalRead(IR2);
    // Low -> No Reflection -> IR Sensors on White
    // High -> Reflection -> IR Sensors on Black
    if (sensorLeft == 0 && sensorRight == 0) {
        Serial.println("Moving forward");
        analogWrite(motorL1, 255);
        analogWrite(motorL2, 0);
        analogWrite(motorR1, 255);
        analogWrite(motorR2, 0);
    } else if (sensorLeft == 1 && sensorRight == 0) {
        Serial.println("Turning left");
        analogWrite(motorL1, 0);
        analogWrite(motorL2, 192);
        analogWrite(motorR1, 192);
        analogWrite(motorR2, 0);
    } else if (sensorLeft == 0 && sensorRight == 1) {
        Serial.println("Turning right");
        analogWrite(motorL1, 192);
        analogWrite(motorL2, 0);
        analogWrite(motorR1, 0);
        analogWrite(motorR2, 192);
    } else if (sensorLeft == 1 && sensorRight == 1) {
        Serial.println("Stopping");
        analogWrite(motorL1, 0);
        analogWrite(motorL2, 0);
        analogWrite(motorR1, 0);
        analogWrite(motorR2, 0);
    }
}
