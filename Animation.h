#ifndef Animation_h
#define Animation_h

#include "Arduino.h"

class Animation
{

  public:
    virtual void NextFrame(uint32_t pixels[]);
    virtual void SetDelay(uint32_t millisecondsDelay);
        
  private:
    
};

#endif



