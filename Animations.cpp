#include "Arduino.h"
#include "Animations.h"

#include <Adafruit_NeoPixel.h>
#include "ColourProvider.h"

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


void Animations::SinglePixelSpin(ColourProvider *colourProvider)
{

  // Don't forget, with pointers, we're using object->method syntax rather than object.method

  for(uint32_t i=0; i<_strip.numPixels(); i++) {
    Clear();
    Serial.println("Asking for Colour");
    _strip.setPixelColor(i, colourProvider->NextColour());
    _strip.show();
    delay(2000);
  }
  
}



