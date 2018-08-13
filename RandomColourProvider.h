#ifndef RandomColourProvider_h
#define RandomColourProvider_h

#include "Arduino.h"
#include "ColourProvider.h"

class RandomColourProvider : public ColourProvider
{

  private:
    uint32_t* _colours;
    uint32_t _coloursCount;
    uint32_t _returnColour = 0;
    uint32_t _repeatCount = 1;
    uint32_t TimesToRepeatColour = 1;
    
  public:
    inline RandomColourProvider(uint32_t* colours, uint32_t coloursCount, uint32_t repeat) : _colours(colours), _coloursCount(coloursCount), TimesToRepeatColour(repeat)
    {
      Serial.println(_colours[1]);
    }

    inline uint32_t NextColour()
    { 
      if(_repeatCount < TimesToRepeatColour)
      {
        _repeatCount++;
      }
      else
      {
        _returnColour = _colours[random(0, _coloursCount)];  // upper bound is exclusive!
        _repeatCount = 1;
      }
      return _returnColour;
    }
    

};

#endif

