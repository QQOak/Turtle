#include "Control.h"
#include <Arduino.h>
#include <Bounce2.h>

#define Power_Button 2
#define L1_Button 3
#define L2_Button 4
#define L3_Button 5

Control::Control()
{
}

void Control::AttachButtons()
{
  pinMode(Power_Button, INPUT_PULLUP);
  PowerButton.attach(Power_Button);
  PowerButton.interval(5);
  
  pinMode(L1_Button, INPUT_PULLUP);
  L1Button.attach(L1_Button);
  L1Button.interval(5);

  pinMode(L2_Button, INPUT_PULLUP);
  L2Button.attach(L2_Button);
  L2Button.interval(5);

  pinMode(L3_Button, INPUT_PULLUP);
  L3Button.attach(L3_Button);
  L3Button.interval(5);
}

void Control::UpdateButtons()
{
  PowerButton.update();
  L1Button.update();
  L2Button.update();
  L3Button.update();
}

bool Control::PowerButtonPressed()
{
    return PowerButton.fell();
}

bool Control::L1ButtonPressed()
{
    return L1Button.fell();
}

bool Control::L2ButtonPressed()
{
    return L2Button.fell();
}

bool Control::L3ButtonPressed()
{
    return L3Button.fell();
}
