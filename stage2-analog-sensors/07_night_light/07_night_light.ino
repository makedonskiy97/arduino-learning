// C++ code
//
int pinLed = 2;
int pinPhoto = A0;
int lightLimit = 400;

void setup()
{
  pinMode(pinLed, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int light = analogRead(pinPhoto);
  Serial.println(light);
  digitalWrite(pinLed, light < lightLimit ? HIGH : LOW);
  delay(100);
}