#ifndef Animations_h
#define Animations_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "ColourProvider.h"

class Animations
{

  public:
    Animations(Adafruit_NeoPixel strip);
    void Clear();
    void SinglePixelSpin(ColourProvider *colourProvider);
    
  private:
    Adafruit_NeoPixel _strip;

};

#endif



