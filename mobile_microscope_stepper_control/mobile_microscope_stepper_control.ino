// #include <Stepper.h>
// Stepper mystepper = Stepper(2038, 8, 9, 10, 11);
int late = 1500;
int control = 1;
void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  if (control == 1) {
    control = 1;
    for (int i = 0; i < 2038 / 4; i++) {
      rotate1(0, 1, 1, 0);
      rotate2(0, 1, 1, 0);
      delayMicroseconds(late);
      rotate1(0, 0, 1, 1);
      rotate2(0, 0, 1, 1);
      delayMicroseconds(late);
      rotate1(1, 0, 0, 1);
      rotate2(1, 0, 0, 1);
      delayMicroseconds(late);
      rotate1(1, 1, 0, 0);
      rotate2(1, 1, 0, 0);
      delayMicroseconds(late);
    }
    delay(500);

    for (int i = 0; i < 2038 / 4; i++) {
      rotate1(0, 1, 1, 0);
      rotate2(0, 1, 1, 0);
      delayMicroseconds(late);
      rotate1(1, 1, 0, 0);
      rotate2(1, 1, 0, 0);
      delayMicroseconds(late);
      rotate1(1, 0, 0, 1);
      rotate2(1, 0, 0, 1);
      delayMicroseconds(late);
      rotate1(0, 0, 1, 1);
      rotate2(0, 0, 1, 1);
      delayMicroseconds(late);
    }
    delay(500);
  }


  //////////////////////////////////////////////////////
  // rotate(0, 1, 1, 0);
  // delayMicroseconds(late);
  // rotate(0, 1, 1, 1);
  // delayMicroseconds(late);
  // rotate(1, 1, 0, 1);
  // delayMicroseconds(late);
  // rotate(1, 1, 1, 0);
  // delayMicroseconds(late);
}


void rotate1(int a, int b, int c, int d) {
  digitalWrite(8, a);
  digitalWrite(9, b);
  digitalWrite(10, c);
  digitalWrite(11, d);
}
void rotate2(int a, int b, int c, int d) {
  digitalWrite(4, a);
  digitalWrite(5, b);
  digitalWrite(6, c);
  digitalWrite(7, d);
}