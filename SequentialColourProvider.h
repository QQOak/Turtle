#ifndef SequentialColourProvider_h
#define SequentialColourProvider_h

#include "Arduino.h"
#include "ColourProvider.h"

class SequentialColourProvider : public ColourProvider
{

  public:
    uint32_t NextColour();
    
  private:

};

#endif

