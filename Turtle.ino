#include <Adafruit_NeoPixel.h>


#include "ColourProvider.h"
#include "SingleColourProvider.h"
#include "RandomColourProvider.h"
#include "Animation.h"
#include "SpinnerAnimation.h"



#define PIN 12
#define NUMPIXELS 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
ColourProvider* colourProvider;
Animation* animation;


void setup() {  

  Serial.begin(9600);

  strip.begin();
  for(uint32_t i=0; i<NUMPIXELS; i++)
  {
    strip.setPixelColor(i, 0);
  }
  strip.show();
  //SingleColourSpinner();
  RandomColourSpinner();
}

void loop() {

  // Get an array containing all of the values for the pixels
  uint32_t pixels[NUMPIXELS];  
  animation->NextFrame(pixels);

  // put those values into the neopixels and show them.
  for(uint32_t i=0; i<NUMPIXELS; i++)
  {
    strip.setPixelColor(i, pixels[i]);
  }
  strip.show();
  
  
  
}


void SingleColourSpinner()
{
  colourProvider = new SingleColourProvider(strip.Color(32, 0, 0));
  animation = new SpinnerAnimation(colourProvider, NUMPIXELS);
  animation->SetDelay(100);
}

void RandomColourSpinner()
{
    const uint32_t *colours = new uint32_t[4] {
      strip.Color(5, 0, 0),
      strip.Color(0, 5, 0),
      strip.Color(0, 0, 5),
      strip.Color(2, 2, 2)
    };
    colourProvider = new RandomColourProvider(colours, 4, 1);
    static_cast<RandomColourProvider*>(colourProvider)->setTimesToRepeatColour(48); 
    //static_cast<RandomColourProvider*>(colourProvider)->AllowRepeats = false;
    
    animation = new SpinnerAnimation(colourProvider, NUMPIXELS);
    animation->SetDelay(1000);
    
    
}

