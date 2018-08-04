#ifndef ColourProvider_h
#define ColourProvider_h

#include "Arduino.h"

class ColourProvider
{

  public:
    virtual uint32_t NextColour();
    
  private:

};

#endif



