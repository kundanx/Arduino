#define encoder_ch1 2
#define encoder_ch2 3

volatile int counter_enc1 = 0;
volatile int counter_enc2 = 0;

void setup() {
    Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), encoder_channel1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), encoder_channel2, CHANGE);
}

void loop(){

  Serial.print("channel 1: ");
  Serial.print(counter_enc1);
  Serial.print("\t\t");
  Serial.print("channel 2: ");
  Serial.println(counter_enc2);
}
void encoder_channel1() {
  //counter to measure no. of signals for channel 1
  counter_enc1++;
}
void encoder_channel2() {
  //counter to measure no. of signals for channel 2
  counter_enc2++;
}