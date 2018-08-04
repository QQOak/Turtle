#ifndef Animations_h
#define Animations_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class Animations
{

  public:
    Animations(Adafruit_NeoPixel strip);
    void Clear();
    void SinglePixelSpin(uint32_t colour);
    void SinglePixelSpin(uint32_t colours[]);
    
  private:
    Adafruit_NeoPixel _strip;

};

#endif



