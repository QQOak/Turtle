#include <Adafruit_NeoPixel.h>
#include "Animations.h"
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
  // put your main code here, to run repeatedly:



  circulate();
  
}



void loopColour()
{
  for(int i=0; i<4; i++)
  {
    loopColour2(ColourCycle[i]);  
  }
}

void loopColour2(uint32_t colour)
{
  for(uint32_t i=0; i<strip.numPixels(); i++) {
    animation.Clear();
    strip.setPixelColor(i, colour);
    strip.show();
    delay(200);
  }
}




void circulate()
{
  int colourIndex = 0;

  
  for(uint32_t i=0; i<strip.numPixels(); i++) {
    animation.Clear();
    strip.setPixelColor(i, ColourCycle[colourIndex]);
    colourIndex = nextColourIndex(colourIndex);
    strip.show();
    delay(500);
  }
  
}

uint32_t nextColourIndex(uint32_t current)
{
  uint32_t index = current;
  Serial.print("Input: ");
  Serial.print(current);
  
  
  index = (++current % 4);

  Serial.println();
  return (index);
}


void sparkle()
{
  
}

