int us_trig = 3, us_echo = 4;
float times, distance;
void setup() {
  Serial.begin(9600);
  pinMode(us_trig, OUTPUT);
  pinMode(us_echo, INPUT);
}

void loop() {

  digitalWrite(us_trig, HIGH);
  delayMicroseconds(10);     //keeping trig pin high for 10 mircoseconds to send us signal
  digitalWrite(us_trig, LOW);

//reading the time taken for the echo pin to become high 
  times = pulseIn(us_echo, HIGH);

  distance = times / 2 / 29;

  Serial.println(distance);
}