// C++ code
//
int led_pin = 3;
int btn_pin = 2;
bool led_status = false;
bool btn_last_state = HIGH;

void setup()
{
  pinMode(led_pin, OUTPUT);
  pinMode(btn_pin, INPUT_PULLUP);
}

void loop()
{
  
  bool btn_state = digitalRead(btn_pin);
  
  if (btn_state == LOW && btn_last_state == HIGH) {
    led_status = !led_status;
    digitalWrite(led_pin, led_status);
    delay(500);
  }
  
  btn_last_state = btn_state;
}