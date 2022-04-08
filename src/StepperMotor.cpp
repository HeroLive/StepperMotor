#include "Arduino.h"
#include "StepperMotor.h"

StepperMotor::StepperMotor(int p, int d) : pin_pul(p), pin_dir(d)
{
    stepsPerUnit = 1;
    direction = 0;
    startDirection = LOW;
    positon = 0;
    last_step_time = 0;
    pinMode(pin_pul, OUTPUT);
    pinMode(pin_dir, OUTPUT);
}

void StepperMotor::setSpeed(float whatSpeed)
{
    // step_delay = whatSpeed;
    step_delay = 1000L * 1000L / stepsPerUnit / whatSpeed;
}
void StepperMotor::setStepsPerUnit(float ppu)
{
    stepsPerUnit = ppu;
}
void StepperMotor::setStartDirection(bool dir)
{
    startDirection = dir;
}
void StepperMotor::moveTo(float absolute)
{
    long target = absolute * stepsPerUnit;
    long _delay = 0.5 * step_delay - 5;
    boolean pul_status = LOW;
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
        delayMicroseconds(_delay);
        digitalWrite(pin_pul, LOW);
        delayMicroseconds(_delay);
        positon = (positon < target) ? positon + 1 : positon - 1;
        yield();
        /*
        unsigned long now = micros();
        if (now - last_step_time >= _delay)
        {
            last_step_time = now;
            pul_status = !pul_status;
            digitalWrite(pin_pul, pul_status);
            if(!pul_status) {
                positon = (positon < target) ? positon + 1 : positon - 1;
            }
        }
        */
    }
}
