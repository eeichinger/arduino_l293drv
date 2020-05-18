//Oakys L293D Motor Driver library
// copyright Erich Eichinger, 2020
// this code is public domain, enjoy!

#ifndef _L293Drv_h_
#define _L293Drv_h_

#include <Arduino.h>
#include <inttypes.h>

class L293Drv {
  public:
    L293Drv(uint8_t en, uint8_t in1, uint8_t in2);
    void begin(void);
    void halt(void);
    void setSpeed(uint8_t v);
    void setDirection(int8_t dir);

  private:
    int8_t _dir = 0; // -1, 0, 1
    int8_t _v = 0; // 0-255
    uint8_t _pin_en = -1;
    uint8_t _pin_in1 = -1;
    uint8_t _pin_in2 = -1;
};

#endif
