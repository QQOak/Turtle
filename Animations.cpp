#include "Arduino.h"
#include "Animations.h"

#include <Adafruit_NeoPixel.h>

Animations::Animations(Adafruit_NeoPixel strip)
{
  _strip = strip;
}

void Animations::Clear()
{
  for(uint16_t i=0; i<_strip.numPixels (); i++) {
      _strip.setPixelColor (i, 0, 0, 0);
  }
  _strip.show();
}


void Animations::SinglePixelSpin(uint32_t colour)
{

  for(uint32_t i=0; i<_strip.numPixels(); i++) {
    Clear();
    _strip.setPixelColor(i, colour);
    _strip.show();
    delay(200);
  }
  
}

void Animations::SinglePixelSpin(uint32_t colours[])
{
  
}

