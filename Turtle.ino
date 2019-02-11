#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>

#include "ColourProvider.h"
#include "SingleColourProvider.h"
#include "RandomColourProvider.h"
#include "Animation.h"
#include "SpinnerAnimation.h"



#define NEOPIXEL_PIN 16
#define NUMPIXELS 16

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
//ColourProvider* colourProvider;
//Animation* animation;


const int BUTTON_COUNT = 4;
const int BUTTON_PINS [BUTTON_COUNT] { 2, 3, 4, 5 };
Bounce buttons[BUTTON_COUNT];


bool ledOn = false;


void setup() {  

  Serial.begin(9600);

  setupButtons();

  strip.begin();
  for(uint32_t i=0; i<NUMPIXELS; i++)
  {
    strip.setPixelColor(i, 0);
  }
  strip.show();
  //SingleColourSpinner();
  //RandomColourSpinner();
}

void loop() {

  processButtons();
/*
  // Get an array containing all of the values for the pixels
  uint32_t pixels[NUMPIXELS];  
  animation->NextFrame(pixels);

  // put those values into the neopixels and show them.
  for(uint32_t i=0; i<NUMPIXELS; i++)
  {
    strip.setPixelColor(i, pixels[i]);
  }
  strip.show();
  */
}



void setupButtons()
{
  for(int i=0; i<BUTTON_COUNT; i++)
  {
    pinMode(BUTTON_PINS[i], INPUT_PULLUP);
    buttons[i] = Bounce();
    buttons[i].attach(BUTTON_PINS[i]);
    buttons[i].interval(5);
  }
}

void processButtons()
{
  for(int i = 0; i<BUTTON_COUNT; i++)
  {
    buttons[i].update();   
    if(buttons[i].fell())
    {
      switch(i)
      {
        case 0: powerButtonPressed(); break;
        case 1: speedButtonPressed(); break;
        case 2: colourButtonPressed(); break;
        case 3: patternButtonPressed(); break;          
      }
    }
  }
}






void powerButtonPressed()
{
  Serial.println("Power Button Pressed");
  toggleLed();
}

void speedButtonPressed()
{
  Serial.println("Speed Button Pressed");
  toggleLed();
}

void colourButtonPressed()
{
  Serial.println("Colour Button Pressed");
  toggleLed();
}

void patternButtonPressed()
{
  Serial.println("Pattern Button Pressed");
  toggleLed();
}


void toggleLed()
{
  ledOn = !ledOn;
  digitalWrite(LED_BUILTIN, ledOn);
}



/*


void SingleColourSpinner()
{
  colourProvider = new SingleColourProvider(strip.Color(32, 0, 0));
  animation = new SpinnerAnimation(colourProvider, NUMPIXELS);
  animation->SetDelay(100);
}

void RandomColourSpinner()
{
    const uint32_t *colours = new uint32_t[4] {
      strip.Color(64, 0, 0),
      strip.Color(0, 64, 0),
      strip.Color(0, 0, 64),
      strip.Color(32, 32, 32)
    };
    colourProvider = new RandomColourProvider(colours, 4, 1);
    static_cast<RandomColourProvider*>(colourProvider)->setTimesToRepeatColour(1); 
    //static_cast<RandomColourProvider*>(colourProvider)->AllowRepeats = false;
    
    animation = new SpinnerAnimation(colourProvider, NUMPIXELS);
    animation->SetDelay(180);
    
    
}

*/
