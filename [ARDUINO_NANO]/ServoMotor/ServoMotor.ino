#include <Servo.h>
Servo d9;
Servo d10;

int x = 0;

void setup() {
  d9.attach(9);
  d10.attach(10);
}

void loop() {
  for (x = 0; x <= 180; x += 1) {
    d9.write(x);
    d10.write(x);

    delay(15);
  }
  
  for (x = 180; x >= 0; x -= 1) {
    d9.write(x);
    d10.write(x);

    delay(15);
  }
}