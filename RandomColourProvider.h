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
    uint32_t _repeatCount;
    int32_t _previousColourIndex = -1;
    uint32_t _timesToRepeatColour = 1;
    
  public:
    inline RandomColourProvider(uint32_t* colours, uint32_t coloursCount, uint32_t timesToRepeatColour) : _colours(colours), _coloursCount(coloursCount), _timesToRepeatColour(timesToRepeatColour)
    {
      _repeatCount = _timesToRepeatColour;
      Serial.println(_repeatCount);
    }


    bool AllowRepeats = false;
    
    inline uint32_t NextColour()
    { 
      
      
      if(_repeatCount < _timesToRepeatColour)
      {
        _repeatCount++;
        Serial.println("less Than");
      }
      else
      {
        _returnColour = _colours[random(0, _coloursCount)];  // upper bound is exclusive!
        _repeatCount = 1;
        Serial.println("equal or greater");
      }
      return _returnColour;
    }

    inline void setTimesToRepeatColour(uint32_t timesToRepeatColour)
    {
      _timesToRepeatColour = timesToRepeatColour;
      _repeatCount = timesToRepeatColour;
    }

};

#endif

