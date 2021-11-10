#include <StepperMotor.h>
#define pul 10
#define dir 11

StepperMotor stepper(pul, dir);
float disPerRound = 0.025; //round/mm
int microStep = 16;
float angleStep = 1.8;
float stepsPerUnit = disPerRound * 360.0 * microStep / angleStep;
long target = 0;
void setup() {
  // put your setup code here, to run once:
  stepper.setSpeed(500);
  stepper.setStepsPerUnit(stepsPerUnit);
  stepper.setStartDirection(LOW);
  delay(3000);
}

void loop() {
  target = 200;
  stepper.moveTo(target);
  delay(1000);
  target = 0;
  stepper.moveTo(target);
  delay(3000);
}
