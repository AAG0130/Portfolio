#ifndef TimerMEF_h
#define TimerMEF_h

#include "Arduino.h"

class Timer
{
  public:
    Timer(double time);
    double set(double time);
    double get();
  private:
    unsigned long _time;
};

#endif
