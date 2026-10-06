// C++ code
//
int led_red = 2;
int led_yellow = 3;
int led_green = 4;
int delay_interval = 3000;
int delay_blink = 500;

void setup()
{
  pinMode(led_red, OUTPUT); // Red
  pinMode(led_yellow, OUTPUT); // Yellow
  pinMode(led_green, OUTPUT); // GREEN
}

void loop()
{
  digitalWrite(led_red, HIGH);
  delay(delay_interval);
  digitalWrite(led_yellow, HIGH);
  delay(delay_interval/2);
  
  digitalWrite(led_red, LOW);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_green, HIGH);
  delay(delay_interval);
  
  blinkGreen();
  
  digitalWrite(led_yellow, HIGH);
  delay(delay_interval);  
  digitalWrite(led_yellow, LOW);
  
}

void blinkGreen()
{
  for (int i=0; i<3; i++)
  {
    digitalWrite(led_green, LOW);
    delay(delay_blink);
  	digitalWrite(led_green, HIGH);
    delay(delay_blink);
  }
  digitalWrite(led_green, LOW);
}
  