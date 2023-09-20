#include <SoftwareSerial.h>
char c;
long baud_rate = 115200;
SoftwareSerial myserial(10,11); //Rx:Tx
void setup(){
  Serial.begin(baud_rate);
  myserial.begin(baud_rate);
  pinMode(13, OUTPUT);
}

void loop(){
  if(Serial.available()){
    c= Serial.read();
    myserial.write(c);
  }
  if(myserial.available()){
    c= myserial.read();
    Serial.println(c);
  }

}