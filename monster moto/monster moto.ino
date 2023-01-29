//MOTOR 1
#define IN1 7
#define IN2 8

//MOTOR 2
#define IN3 4
#define IN4 9

#define PWM1 5
#define PWM2 6

#define CURRENT_SEN_1 A2
#define CURRENT_SEN_2 A3

#define EN1 A0
#define EN2 A1

void setup() {
  Serial.begin(9600);
  Serial.println("Serial is ready");
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  analogWrite(EN1, HIGH);
  analogWrite(EN2, HIGH);
}

void loop() {
  char input;
  if (Serial.available() > 0) {
    input = Serial.read();
  }
  switch (input) {
    case 'F':  //forward
      direction(1, 0, 1, 0);
      speed(255, 255);
      break;

    case 'B':  //Back
      direction(0, 1, 0, 1);
      speed(255, 255);
      break;

    default:
      direction(0, 0, 0, 0);
      speed(0, 0);
      break;
  }
}
void direction(int a, int b, int c, int d) {
  digitalWrite(IN1, a);
  digitalWrite(IN2, b);
  digitalWrite(IN3, c);
  digitalWrite(IN4, d);
}
void speed(int x, int y) {
digitalWrite(PWM1, x);
digitalWrite(PWM2, y);
}
