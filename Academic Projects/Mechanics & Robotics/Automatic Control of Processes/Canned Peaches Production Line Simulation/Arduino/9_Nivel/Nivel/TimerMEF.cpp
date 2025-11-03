#include "Arduino.h"
#include "TimerMEF.h"

Timer::Timer(double time)
{
  unsigned long ms = (long) millis();
  _time = ms - time*1000;
}

double Timer::get()
{
  unsigned long ms = (long) millis();
  return ((double)(ms - _time))/1000;
}

double Timer::set(double time)
{
  unsigned long ms = (long) millis();
  _time = ms - time*1000;
  return ((double)(ms - _time))/1000;
}
