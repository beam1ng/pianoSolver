#include <Servo.h>
Servo servo;
float initialSpeed;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    initialSpeed = 3.176;
}

void loop() {
    // put your main code here, to run repeatedly:
    float speed = initialSpeed + (float)millis()/16000;
    Serial.print(speed);
    Serial.print("\n");
    delay(float(1)/speed*1000);
}