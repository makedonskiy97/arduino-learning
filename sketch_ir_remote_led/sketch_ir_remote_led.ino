#include <IRremote.h>

// C++ code
//
const int pinIR = 11;
const int pinRelay = 7;
const uint8_t TOGGLE_CODE = 0x0;
bool relayOn = false;

void setup()
{
  Serial.begin(9600);
  IrReceiver.begin(pinIR);
  pinMode(pinRelay, OUTPUT);
  digitalWrite(pinRelay, LOW);
}

void loop()
{
  if (IrReceiver.decode()) {
    uint8_t cmd = IrReceiver.decodedIRData.command;
    Serial.print("DEC: ");
    Serial.print(cmd);
    Serial.print(" HEX: 0x");
    Serial.println(cmd, HEX);

    if (cmd == TOGGLE_CODE) {
      relayOn = !relayOn;
      digitalWrite(pinRelay, relayOn ? HIGH : LOW);
    }
    IrReceiver.resume();
  }
}