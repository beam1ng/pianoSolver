#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
float initialSpeed;
int lightValue1;
int lightValue2;
int lightValue3;
int lightValue4;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initialSpeed = 3.176;
  servo1.attach(12);
  servo2.attach(11);
  servo3.attach(10);
  servo4.attach(9);
}

void loop() {
  LogReadings();
  
  lightValue1 = analogRead(4);
  lightValue2 = analogRead(1);
  lightValue3 = analogRead(2);
  lightValue4 = analogRead(3);
  checkArmCondition(servo1,lightValue1,180,-10);
  checkArmCondition(servo2,lightValue2,180,-10);
  checkArmCondition(servo3,lightValue3,0,10);
  checkArmCondition(servo4,lightValue4,0,10);
  float speed = initialSpeed + (float)millis()/16000;
  delay(float(1)/speed*1000);
}

void LogReadings(){
  Serial.print(analogRead(4),DEC);
  Serial.write("\n");
  Serial.print(analogRead(1),DEC);
  Serial.write("\n");
  Serial.print(analogRead(2),DEC);
  Serial.write("\n");
  Serial.print(analogRead(3),DEC);
  Serial.write("\n");
  Serial.write("\n");
}


void checkArmCondition(Servo servo,int lightValue,int defaultAngle,int deltaAngle){
  if(lightValue<5){
    moveArmDown(servo,defaultAngle,deltaAngle);
  }
}

void moveArmDown(Servo servo,int defaultAngle,int deltaAngle){
  servo.write(defaultAngle+deltaAngle);
  delay(50);
  servo.write(defaultAngle);
  delay(50);
}
