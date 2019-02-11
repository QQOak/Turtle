#ifndef Animation_h
#define Animation_h

#include "Arduino.h"
#include "ColourProvider.h"

class Animation
{

  public:
    virtual void NextFrame(uint32_t pixels[]);
    virtual void SetDelay(uint32_t millisecondsDelay);
    virtual void SetColourProvider(ColourProvider* colorProvider);

  protected:

  private:
    
};

#endif
