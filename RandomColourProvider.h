#ifndef RandomColourProvider_h
#define RandomColourProvider_h

#include "Arduino.h"
#include "ColourProvider.h"

class RandomColourProvider : public ColourProvider
{

  public:
    inline RandomColourProvider(uint32_t colours[], uint32_t coloursCount)
    {
      _colours = colours;
      _coloursCount = coloursCount;
    }

    inline uint32_t NextColour()
    { 
      return _colours[random(0, _coloursCount)]; // upper bound is exclusive!
    }
    
  private:
    uint32_t* _colours;
    uint32_t _coloursCount;

};

#endif

