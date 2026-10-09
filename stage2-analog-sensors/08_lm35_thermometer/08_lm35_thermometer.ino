// C++ code
//
int pinTemp = A0;
int pinLed = 2;
float volt = 5.0;
float correct = 0.5; // TMP36 (0.5 V) TMP35 (0 V)
void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int raw = analogRead(pinTemp);
  float volts = raw * volt / 1023.0;
  float tempC = (volts - correct) * 100.0;
  Serial.println(raw);
  Serial.println(' ');
  Serial.println(tempC);
    
  digitalWrite(pinLed, (tempC >= 28));
  delay(1000);
}