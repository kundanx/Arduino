//measure direction and value using rotary encoder

//led pin config
#define ledCW 10
#define ledCCW 11

//encoder pin inputs
#define inputCLK 6
#define inputDT 5
#define inputSW 4

int presentStateCLK;
int previousStateCLK;
int counter = 0, i;
String dir = "";

void setup() {
  Serial.begin(9600);
  pinMode(ledCW, OUTPUT);
  pinMode(ledCCW, OUTPUT);
  pinMode(inputCLK, INPUT);
  pinMode(inputDT, INPUT);
  pinMode(inputSW, INPUT);
  previousStateCLK = digitalRead(inputCLK);
}

void loop() {
  presentStateCLK = digitalRead(inputCLK);

  //checks wheather the encoder is moving
  if (presentStateCLK != previousStateCLK) {
    //encoder is rotating clockwise
    if (digitalRead(inputDT) != presentStateCLK) {

      counter++;
      dir = "clockwise";
      digitalWrite(ledCCW, LOW);
      digitalWrite(ledCW, HIGH);

    }
    //encoder is rotating counter clockwise
    else {
      counter--;
      dir = "counter clockwise";
      digitalWrite(ledCCW, HIGH);
      digitalWrite(ledCW, LOW);
    }
    Serial.print("Direction: ");
    Serial.print(dir);
    Serial.print("   ");
    Serial.print("counter: ");
    Serial.println(counter);
  }

  //switch is used as reset button
  if (!digitalRead(inputSW)) {
    counter = 0;
    for (i = 255; i >= 0; i--) {
      analogWrite(ledCCW, i);
      analogWrite(ledCW, i);
    }

    Serial.println("RESET!! COUNT = 0");
  }
  previousStateCLK = presentStateCLK;
}