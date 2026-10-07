// C++ code
//
int pinLed = 9;
int pinP = A0;
int intervalLed = 0;
void setup()
{
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int v = analogRead(pinP);
  intervalLed = map(v, 0, 1023, 0, 255);
  if (v > 0) {
    digitalWrite(pinLed, HIGH);
    delay(intervalLed);
    digitalWrite(pinLed, LOW);
    delay(intervalLed);
  } else {
    digitalWrite(pinLed, HIGH);
  }
  
  Serial.println(v);
}

void light()
{
  int v = analogRead(pinP);
  analogWrite(pinLed, map(v, 0, 1023, 0, 255));
  Serial.println(v);
  delay(50);
}