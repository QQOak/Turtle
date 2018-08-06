#include <Adafruit_NeoPixel.h>


#include "ColourProvider.h"
#include "SingleColourProvider.h"
#include "Animation.h"
#include "SpinnerAnimation.h"



#define PIN 10
#define NUMPIXELS 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
ColourProvider* colourProvider;
Animation* animation;


void setup() {

  Serial.begin(9600);
  Serial.println();
  Serial.println(" ********** ARDUINO STARTUP **********");
  Serial.println();
    
  
  strip.begin();
  for(uint32_t i=0; i<NUMPIXELS; i++)
  {
    strip.setPixelColor(i, 0);
  }
  strip.show();
  SingleColourSpinner();
  
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
  colourProvider = new SingleColourProvider(strip.Color(0, 0, 32));
  animation = new SpinnerAnimation(colourProvider, NUMPIXELS);
  animation->SetDelay(100);


  

  
  //animation.SinglePixelSpin(colourProvider);
}

