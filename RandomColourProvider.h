#ifndef RandomColourProvider_h
#define RandomColourProvider_h

#include "Arduino.h"
#include "ColourProvider.h"

class RandomColourProvider : public ColourProvider
{

  public:
    uint32_t NextColour();
    
  private:

};

#endif



