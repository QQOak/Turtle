#ifndef SpinnerAnimation_h
#define SpinnerAnimation_h

#include "Arduino.h"
#include "Animation.h"

class SpinnerAnimation : public Animation
{

  public:
  
    inline SpinnerAnimation(ColourProvider* colourProvider, uint32_t pixelCount) : _colourProvider(colourProvider), pixelCount(pixelCount)
    {
      Serial.println("SpinnerAnimation Constructor");
    }
    
    inline ~SpinnerAnimation()
    {
      Serial.println("SpinnerAnimation Destructor");
    }

    inline void NextFrame(uint32_t pixels[])
    {
      //Serial.println("SpinnerAnimation NextFrame()");
      
      // Only make a change to the pixels if enough milliseconds have elapsed.
      uint32_t currentMillis = millis();
      if( currentMillis >= lastMillis+delayMillis )
      {
        lastMillis = currentMillis;
        for(uint32_t i = 0; i<pixelCount; i++)
        {
          if(i == pixelIndex)
          {
            pixels[i] = _colourProvider->NextColour();
          }
          else
          {
            pixels[i] = 0; // off
          }
          
        }
        pixelIndex = (++pixelIndex % pixelCount);
        Serial.println("Animation");
      } 
      else
      {
        //Serial.println("No action taken");
      }
      
      
    }

    inline void SetDelay(uint32_t millisecondsDelay)
    {
      delayMillis = millisecondsDelay;
    }
  
  private:
    uint32_t lastMillis = 0;
    uint32_t pixelCount;
    uint32_t pixelIndex = 0;
  
  
  private:
    ColourProvider* _colourProvider;
    uint32_t delayMillis = 30;
    
};

#endif




/*

Animation::SpinnerAnimation(Adafruit_NeoPixel strip) : _strip(strip)
{
}

void Animations::Clear()
{
  // Doesn't call show.
  for(uint16_t i=0; i<_strip.numPixels(); i++) {
      _strip.setPixelColor (i, 0, 0, 0);
  }
}


void Animations::SinglePixelSpin(ColourProvider* colourProvider)
{

  // Don't forget, with pointers, we're using object->method syntax rather than object.method
  _currentPixelIndex = 0;
  _colourProvider = colourProvider; 
}

void Animations::NextFrame()
{
  Serial.println("Cleared");

  uint32_t currentMillis = millis();
  if(currentMillis >= _lastAnimationMillis + _delayMillis)
  {
    // Reset the clock
    _lastAnimationMillis = currentMillis;  

    // Set the pixels
    //Clear();


    Serial.print("NEXTCOLOUR ");
    Serial.println(_colourProvider->NextColour());
    _strip.setPixelColor(_currentPixelIndex, _colourProvider->NextColour());
    //_strip.show();

    // increment the index.
    _currentPixelIndex = (++_currentPixelIndex % _strip.numPixels());
  }
    
}

*/
