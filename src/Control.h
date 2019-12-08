#ifndef control_h
#define control_h

#include <Arduino.h>
#include <Bounce2.h>

class Control
{
    public: 
        Control();
        void AttachButtons();
        void UpdateButtons();
        bool PowerButtonPressed();
        bool L1ButtonPressed();
        bool L2ButtonPressed();
        bool L3ButtonPressed();

    private:
        Bounce PowerButton = Bounce();
        Bounce L1Button = Bounce();
        Bounce L2Button = Bounce();
        Bounce L3Button = Bounce();
};

#endif