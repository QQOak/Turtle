#ifndef ColourProvider_h
#define ColourProvider_h

#include "Arduino.h"

class ColourProvider
{

  public:
    inline virtual uint32_t NextColour() = 0;
    
  private:

};

#endif



