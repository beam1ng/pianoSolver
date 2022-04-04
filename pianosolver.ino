#include <Servo.h>
Servo servo;
float initialSpeed;
int lightValue;


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    initialSpeed = 3.176;
}

void loop() {
    // put your main code here, to run repeatedly:
    lightValue = analogRead(0);
    checkArmDown(servo,lightValue);
    float speed = initialSpeed + (float)millis()/16000;
    delay(float(1)/speed*1000);
}

void checkArmCondition(Servo servo,int lightValue){
    if(lightValue<5){
        moveArmDown(servo);
    }
}

void moveArmDown(Servo servo){
    servo.write(defalutAngle+deltaAngle);
    delay(50);
    servo.write(defaultAngle);
    delay(50);
}
