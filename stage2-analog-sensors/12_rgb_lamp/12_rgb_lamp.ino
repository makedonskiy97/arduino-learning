// C++ code
//
int pinR = 10;
int pinG = 11;
int pinB = 9;
int interval = 500;
int pinP = A0;

int red = 0;
int green = 0;
int blue = 0;
void setup()
{
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //rgb(255, 0, 0);
  //rgb(0, 255, 0);
  //rgb(0, 0, 255);
  //rgb(255, 255, 0);
  int val = analogRead(pinP);
  Serial.println(val);
  rgb(val, green, blue);
}

void rgb(int red, int green, int blue)
{
  analogWrite(pinR, red);
  analogWrite(pinG, green);
  analogWrite(pinB, blue);
  delay(interval);
}