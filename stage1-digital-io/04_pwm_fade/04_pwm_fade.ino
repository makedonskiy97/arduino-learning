// C++ code
//
int ledPin = 9;
int upDelay = 10;
int downDelay = 3;
void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  for (int i=0; i<255; i++) {
    analogWrite(ledPin, i);
    delay(upDelay);
  }
  
  for (int i=255; i>=0; i--) {
    analogWrite(ledPin, i);
    delay(downDelay);
  }
}