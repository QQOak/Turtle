#ifndef SingleColourProvider_h
#define SingleColourProvider_h

#include "Arduino.h"
#include "ColourProvider.h"

class SingleColourProvider : public ColourProvider
{

  public:
    inline SingleColourProvider(uint32_t colour) : _colour(colour)
    {
    }
    
    inline uint32_t NextColour()
    {
      return _colour;
    }
    
  private:
    uint32_t _colour;
    
};

#endif



