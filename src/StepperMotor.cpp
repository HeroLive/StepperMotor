#include "Arduino.h"
#include "StepperMotor.h"

StepperMotor::StepperMotor(int p, int d) : pin_pul(p), pin_dir(d)
{
    stepsPerUnit = 1;
    direction = 0;
    startDirection = LOW;
    positon = 0;
    pinMode(pin_pul, OUTPUT);
    pinMode(pin_dir, OUTPUT);
}

void StepperMotor::setSpeed(long whatSpeed)
{
    step_delay = whatSpeed;
}
void StepperMotor::setStepsPerUnit(long ppu)
{
    stepsPerUnit = ppu;
}
void StepperMotor::setStartDirection(bool dir)
{
    startDirection = dir;
}
void StepperMotor::moveTo(long absolute)
{
    long target = absolute * stepsPerUnit;
    if (positon == target)
    {
        return;
    }
    else
    {
        if (positon < target)
        {
            direction = HIGH;
        }
        else
        {
            direction = LOW;
        }
    }

    digitalWrite(pin_dir, startDirection ? direction : !direction);

    while (positon != target)
    {
        digitalWrite(pin_pul, HIGH);
        delayMicroseconds(step_delay);
        digitalWrite(pin_pul, LOW);
        delayMicroseconds(step_delay);
        positon = (positon < target) ? positon + 1 : positon - 1;
    }
}