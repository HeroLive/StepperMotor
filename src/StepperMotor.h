#ifndef StepperMotor_h
#define StepperMotor_h

class StepperMotor {
    private:
        int pin_pul;
        int pin_dir;
        bool direction;
        bool startDirection;
        float stepsPerUnit;
        long positon;
        unsigned long last_step_time;
        unsigned long step_delay;

    public:
        StepperMotor(int p, int d);
        void setSpeed(float whatSpeed);
        void setStepsPerUnit(float ppu);
        void setStartDirection(bool dir);
        void moveTo(float absolute);        
};

#endif