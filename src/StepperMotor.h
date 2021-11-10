#ifndef StepperMotor_h
#define StepperMotor_h

class StepperMotor {
    private:
        int pin_pul;
        int pin_dir;
        bool direction;
        bool startDirection;
        long stepsPerUnit;
        long positon;
        unsigned long step_delay;

    public:
        StepperMotor(int p, int d);
        void setSpeed(long whatSpeed);
        void setStepsPerUnit(long ppu);
        void setStartDirection(bool dir);
        void moveTo(long absolute);        
};

#endif