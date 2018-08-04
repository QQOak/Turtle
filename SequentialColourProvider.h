#ifndef SequentialColourProvider_h
#define SequentialColourProvider_h

#include "Arduino.h"
#include "ColourProvider.h"

class SequentialColourProvider : public ColourProvider
{

  public:
    inline SequentialColourProvider(uint32_t colours[], uint32_t coloursCount)
    {
      _colours = colours;
      _coloursCount = coloursCount;
    }

    inline uint32_t NextColour()
    { 
      return _colours[_currentIndex = (++_currentIndex% _coloursCount)];
    }
    
  private:
    uint32_t* _colours;
    uint32_t _currentIndex = 0;
    uint32_t _coloursCount;

};

#endif

