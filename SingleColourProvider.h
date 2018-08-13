#ifndef SingleColourProvider_h
#define SingleColourProvider_h

#include "Arduino.h"
#include "ColourProvider.h"

class SingleColourProvider : public ColourProvider
{

  private:
    uint32_t _colour;
    
  public:
    inline SingleColourProvider(uint32_t colour) : _colour(colour)
    {
    }
    
    inline uint32_t NextColour()
    {
      return _colour;
    }
    
};

#endif



