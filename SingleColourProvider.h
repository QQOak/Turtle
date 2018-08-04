#ifndef SingleColourProvider_h
#define SingleColourProvider_h

#include "Arduino.h"
#include "ColourProvider.h"

class SingleColourProvider : public ColourProvider
{

  public:
    uint32_t NextColour();
    
  private:

};

#endif



