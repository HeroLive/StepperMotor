#include <math.h>
#include "StepperMotor.h"
#define PUL1_PIN 2
#define DIR1_PIN 5
StepperMotor motor_01(PUL1_PIN, DIR1_PIN);

bool M1 = false;
long D200 = 8000;  //motor 2 frequency
long D204 = 10000;  //motor 2 interval time
long D1 = D200;    //currency frequency
long _t = millis();


void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  if (millis() - _t > D204) {
    _t = millis();
    M1 = true;
    if (D1 > 0) {
      D1 = -D200;
      Serial.println("CW");
    } else {
      D1 = D200;
      Serial.println("CCW");
    }
    delay(1000);
  }
  if (M1) {
    motor_01.PLSV(D1);
  }
}
