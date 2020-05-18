//Oakys L293D Motor Driver library
// copyright Erich Eichinger, 2020
// this code is public domain, enjoy!

#include "L293Drv.h"

const int PIN_MOTOR_EN = 6;
const int PIN_MOTOR_IN1 = 7;
const int PIN_MOTOR_IN2 = 8;

L293Drv motor = L293Drv(PIN_MOTOR_EN, PIN_MOTOR_IN1, PIN_MOTOR_IN2);

void setup() {
  motor.begin();
  Serial.begin(115200);
}

void cycle() {
  for (int i = 0; i < 255; i++) {
    motor.setSpeed(i);
    Serial.println(i);
    delay(50);
  }
  for (int i = 255; i > 0; i--) {
    motor.setSpeed(i);
    delay(50);
  }
}

void loop() {
  motor.setDirection(-1);
  cycle();
  motor.halt();
  motor.setDirection(1);
  cycle();
  motor.halt();
}
