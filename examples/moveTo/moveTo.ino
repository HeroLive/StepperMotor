#include <StepperMotor.h>
#define pul 10
#define dir 11

StepperMotor stepper(pul, dir);

float disPerRound = 1.0 ;// only round: 1.0 round, vitme T8-4mm: 4.0 mm, GT2 Pulley 16 Teeth: 16x2 = 32.0 mm
int microStep = 1; //1: full step, 2: haft step, ...
float angleStep = 1.8; //a step angle of 1.8 degrees with 200 steps per revolution
float stepsPerUnit = (1/disPerRound) * 360.0 * microStep / angleStep; //steps/round or steps/mm ...
long target = 0;

void setup() {
  stepper.setStepsPerUnit(stepsPerUnit);
  stepper.setSpeed(2);  //set 2 round/s
  stepper.setStartDirection(LOW);
  delay(3000);
}

void loop() {
  target = 1;
  stepper.moveTo(target);
  delay(1000);
  target = 0;
  stepper.moveTo(target);
  delay(2000);
}
