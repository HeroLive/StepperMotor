#include <math.h>
#include "StepperMotor.h"
#define PUL1_PIN 2
#define DIR1_PIN 5
StepperMotor motor_01(PUL1_PIN, DIR1_PIN);

bool M1 = false;
long D200 = 8000;   //motor 2 frequency
long D202 = 64000;  //motor 2 pulse value
long D204 = 5000;  //motor 2 interval time
long D0 = 0;        //target position
long _t = millis();


void setup() {
  Serial.begin(115200);
  delay(1000);
  D0 = D202;
}

void loop() {
  if (millis() - _t > D204 && !M1) {
    D0 = D0 == D202 ? 0 : D202;
    M1 = true;
  }
  if (M1) {
    motor_01.DRVA(D0, D200);
    if (motor_01.getExeCompleteFlag()) {
      M1 = false;
      Serial.println(D0);      
      _t = millis();
    }
  }
}