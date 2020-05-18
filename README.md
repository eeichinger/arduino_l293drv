Oakys L293D Motor Driver library
copyright Erich Eichinger, 2020
this code is public domain, enjoy!

I couldn't find a simple L293D driver library, so I wrote my own. Usage is simple:

```
#include <L293Drv.h>

L293Drv motor = L293Drv(PIN_MOTOR_EN, PIN_MOTOR_IN1, PIN_MOTOR_IN2);

void setup() {
  motor.begin(); // initialise pins and motor
}

void loop() {
  motor.setDirection(-1); // -1=left, 0=halt, 1=right
  motor.setSpeed(128);
  motor.halt();
}

```
