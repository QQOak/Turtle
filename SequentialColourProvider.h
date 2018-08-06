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
     
     // Set the current index to the maximum bound of the array so that we start with the fist colour.
     // Nextcolour increments and modals the number as part of it's call and it makes sense to prepare the variable here once rather than complicate the logic in the loop later.
     _currentIndex = coloursCount-1;
     
    }

    inline uint32_t NextColour()
    { 
      return _colours[_currentIndex = (++_currentIndex% _coloursCount)];
    }
    
  private:
    uint32_t* _colours;
    uint32_t _currentIndex;
    uint32_t _coloursCount;

};

#endif

