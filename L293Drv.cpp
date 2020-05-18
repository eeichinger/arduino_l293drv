//Oakys L293D Motor Driver library
// copyright Erich Eichinger, 2020
// this code is public domain, enjoy!

#include "L293Drv.h"

L293Drv::L293Drv(uint8_t en, uint8_t in1, uint8_t in2) {
  _pin_en = en;
  _pin_in1 = in1;
  _pin_in2 = in2;

  pinMode(_pin_en, OUTPUT);
  pinMode(_pin_in1, OUTPUT);
  pinMode(_pin_in2, OUTPUT);

  halt();
}

void L293Drv::begin(void) {
  halt();
}

void L293Drv::halt(void) {
  analogWrite(_pin_en, 0);
  digitalWrite(_pin_in1, LOW);
  digitalWrite(_pin_in2, LOW);
}

void L293Drv::setSpeed(uint8_t v) {
  _v = v;
  analogWrite(_pin_en, _v);
}

void L293Drv::setDirection(int8_t dir) {
  if (dir == -1) {
    digitalWrite(_pin_in1, HIGH);
    digitalWrite(_pin_in2, LOW);
  } else if (dir == 1) {
    digitalWrite(_pin_in1, LOW);
    digitalWrite(_pin_in2, HIGH);
  } else {
    digitalWrite(_pin_in1, LOW);
    digitalWrite(_pin_in2, LOW);
  }
}
