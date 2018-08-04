#include <Adafruit_NeoPixel.h>
#include "Animations.h"
#include "SingleColourProvider.h"
#include "SequentialColourProvider.h"
#include "RandomColourProvider.h"
#define PIN 6
#define NUMPIXELS 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Animations animation = Animations(strip);

const uint32_t ColourCycle[] = {
  strip.Color(64, 64, 64), // white
  strip.Color(128, 0, 0), // red
  strip.Color(0, 128, 0), // green
  strip.Color(0, 0, 128) // blue
};

void setup() {
  // put your setup code here, to run once:

  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  Serial.begin(9600);

}

int count = 0;

void loop() {

  //SingleColourSpinner();
  //SequentialColourSpinner();
  RandomColourSpinner();
}


void SingleColourSpinner()
{
  SingleColourProvider colourProvider = SingleColourProvider(strip.Color(32, 32, 32));
  animation.SinglePixelSpin(&colourProvider);
}

void SequentialColourSpinner()
{
  uint32_t colours[] = {
    strip.Color(32, 32, 32),
    strip.Color(32, 0, 0),
    strip.Color(0, 32, 0),
    strip.Color(0, 0, 32)
  };
  SequentialColourProvider colourProvider = SequentialColourProvider(colours, 4);
  animation.SinglePixelSpin(&colourProvider);  
}

void RandomColourSpinner()
{
uint32_t colours[] = {
    strip.Color(32, 32, 32),
    strip.Color(32, 0, 0),
    strip.Color(0, 32, 0),
    strip.Color(0, 0, 32)
  };
  RandomColourProvider colourProvider = RandomColourProvider(colours, 4);
  animation.SinglePixelSpin(&colourProvider);  
}

