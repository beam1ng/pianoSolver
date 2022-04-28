#include <Servo.h>
Servo servo1,servo2,servo3,servo4;
float initialSpeed;
int lightValue1,lightValue2,lightValue3,lightValue4;

int defaultAngle1 = 180;
int defaultAngle2 = 0;
int deltaAngle = 10;
int lightActivationThreshold = 10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo1.attach(12);
  servo2.attach(11);
  servo3.attach(10);
  servo4.attach(9);

  initialSpeed = 3.176;
}

void loop() {
  ReadLightValues();
  PlotReadings();
  CheckArmsActivationConditions();

  float speed = initialSpeed + (float)millis()/16000;
  delay(float(1)/speed*1000);
}

void ReadLightValues(){
  lightValue1 = analogRead(4);
  lightValue2 = analogRead(1);
  lightValue3 = analogRead(2);
  lightValue4 = analogRead(3);
}

void PlotReadings(){
  Serial.print(lightValue1);
  Serial.print(",");
  Serial.print(lightValue2);
  Serial.print(",");
  Serial.print(lightValue3);
  Serial.print(",");
  Serial.println(lightValue4);
}

void CheckArmsActivationConditions(){
  checkArmCondition(servo1,lightValue1,defaultAngle1,-1*deltaAngle);
  checkArmCondition(servo2,lightValue2,defaultAngle1,-1*deltaAngle);
  checkArmCondition(servo3,lightValue3,defaultAngle2,deltaAngle);
  checkArmCondition(servo4,lightValue4,defaultAngle2,deltaAngle);
}

void checkArmCondition(Servo servo,int lightValue,int defaultAngle,int deltaAngle){
  if(lightValue<lightActivationThreshold){
    moveArmDown(servo,defaultAngle,deltaAngle);
  }
}

void moveArmDown(Servo servo,int defaultAngle,int deltaAngle){
  servo.write(defaultAngle+deltaAngle);
  delay(50);
  servo.write(defaultAngle);
  delay(50);
}
