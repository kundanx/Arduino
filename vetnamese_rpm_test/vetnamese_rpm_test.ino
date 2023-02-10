/// ****** MOTOR DRIVER USED: MONSTER MOTO SHEILD *******
// //MOTOR 1
// #define IN1 7
// #define IN2 8
// #define PWM1 5
// #define EN1 A0
// #define CURRENT_SEN_1 A2

//MOTOR 2
#define IN3 4
#define IN4 9
#define PWM2 6
#define EN2 A1
#define CURRENT_SEN_2 A3

//encoder resoultion: 7 for rising or falling/ 14 for change
#define encoder_res 14

// potentiometer data input
#define pot_in A0
// encoder signal inputs
#define encoder_ch1 2
#define encoder_ch2 3

//interval in which encoder data is used for measurement
long interval = 1000;

volatile int counter_enc1 = 0;
volatile int counter_enc2 = 0;
int pwm_value = 0;
long current_time;
long previous_time;
int rpm;


void setup() {
  Serial.begin(9600);
  Serial.println("Serial is ready");
  pinMode(pot_in, INPUT);
  // pinMode(IN1, OUTPUT);
  // pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  // pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  //pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN2, 255);
  attachInterrupt(digitalPinToInterrupt(2), encoder_channel1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), encoder_channel2, CHANGE);
  previous_time = millis();
}

void loop() {
  current_time = millis();
  if((current_time - previous_time) >= interval)
   {
    rpm = ((counter_enc1 + counter_enc2) / (2 * encoder_res)) * 60;
    previous_time = current_time;
    counter_enc1 = 0;
    counter_enc2 = 0;
  }
  pwm_value = map(analogRead(pot_in), 0, 1025, 0, 255);
  
  analogWrite(PWM2, pwm_value);

  Serial.print("pot input: ");
  Serial.print(analogRead(pot_in));
  Serial.print("\t\t");

  Serial.print("pwm: ");
  Serial.print(pwm_value);
  Serial.print("\t\t");

  Serial.print("vout: ");
  Serial.print(map(pwm_value,0,255,0,12));
  Serial.print("\t\t");  

  Serial.print("rpm: ");
  Serial.println(rpm);
}

void encoder_channel1() {
  //counter to measure no. of signals for channel 1
  counter_enc1++;
}
void encoder_channel2() {
  //counter to measure no. of signals for channel 2
  counter_enc2++;
}
