#ifndef ColourProvider_h
#define ColourProvider_h

#include "Arduino.h"

class ColourProvider
{

  protected:

  private:

  public:
    inline virtual uint32_t NextColour() = 0;
    
};

#endif



