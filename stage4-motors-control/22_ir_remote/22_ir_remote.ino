#include <IRremote.h>

// C++ code
//
int pinIR = 11;
int pinLed1 = 8;
int pinLed2 = 9;
int pinLed3 = 10;
bool led1Status = false;
bool led2Status = false;
bool led3Status = false;
void setup()
{
  Serial.begin(9600);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  IrReceiver.begin(pinIR);
}

void loop()
{
  if (IrReceiver.decode()) {
      uint8_t cmd = IrReceiver.decodedIRData.command;
      Serial.print("DEC: ");
      Serial.print(cmd);
      Serial.print(" HEX: 0x");
      Serial.println(cmd, HEX);
      if (cmd == 0x10) {
        led1Status = !led1Status;
        digitalWrite(pinLed1, led1Status);
      } else if (cmd == 0x11) {
        led2Status = !led2Status;
        digitalWrite(pinLed2, led2Status);
      } else if (cmd == 0x12) {
        led3Status = !led3Status;
        digitalWrite(pinLed3, led3Status);
      }
      IrReceiver.resume();
  }
}