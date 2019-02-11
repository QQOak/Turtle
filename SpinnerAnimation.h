#ifndef SpinnerAnimation_h
#define SpinnerAnimation_h

#include "Arduino.h"
#include "Animation.h"

// Spinner Animation that 
class SpinnerAnimation : public Animation
{

  public:
  
    inline SpinnerAnimation(ColourProvider* colourProvider, uint32_t pixelCount) : _colourProvider(colourProvider), pixelCount(pixelCount)
    {
    }
    
    inline ~SpinnerAnimation()
    {
    }

    inline void NextFrame(uint32_t pixels[])
    {
     
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
      } 
      
      
    }

    inline void SetDelay(uint32_t millisecondsDelay)
    {
      delayMillis = millisecondsDelay;
    }

    inline void SetColourProvider(ColourProvider* colorProvider)
    {
      _colourProvider = colorProvider;
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
