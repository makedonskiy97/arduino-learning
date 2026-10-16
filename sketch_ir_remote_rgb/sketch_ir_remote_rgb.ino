#include <IRremote.h>

/**
CH- CH CH+
PREV NEXT PLAY/PAUSE
VOL- VOL+ EQ
0 100+ 200+
1 2 3
4 5 6
7 8 9

0x45 0x46 0x47
0x44 0x40 0x43
0x07 0x15 0x09
0x16 0x19 0xD
0xC 0x18 0x5E
0x8 0x1C 0x5A
0x42 0x5 0x4A
 */

int pinIR = 3;
int pinR = 11;
int pinG = 10;
int pinB = 9;
int interval = 500;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(pinIR);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (IrReceiver.decode()) {
    if (!(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT)) {
      uint8_t cmd = IrReceiver.decodedIRData.command;
      Serial.print("DEC: ");
      Serial.print(cmd);
      Serial.print(" HEX: 0x");
      Serial.println(cmd, HEX);
      decodeCommand(cmd);
    }
    IrReceiver.resume();
  }
}

void decodeCommand(uint8_t cmd) {
  switch (cmd) {
    case 0x45: // CH-
      rgb(255, 0, 0);
      break;
    case 0x46: // CH
      rgb(0, 255, 0);
      break;
    case 0x47: // CH+
      rgb(0, 0, 255);
      break;
    case 0x44: // PREV
      rgb(255, 255, 0);
      break;
    case 0x40: // NEXT
      rgb(0, 255, 255);
      break;
    case 0x43: // PLAY/PAUSE
      rgb(255, 0, 255);
      break;
    case 0x16: // 0
      rgb(0, 0, 0);
      break;
    case 0x19: // 100+ random color
      //rgb(random(0, 100), random(0, 100), random(0, 100));
      randomColor(100);
      break;
    case 0xD: // 200+ random color + blink
      //rgb(random(0, 200), random(0, 200), random(0, 200));
      randomColor(200);
      break;
    default:
      Serial.println("Unknown command");
      break;
  }
}

void randomColor(int blinkCount) {
  int red = 0;
  int green = 0;
  int blue = 0;
  for (int i = 0; i < 10; i++) {
    red = random(0, 255);
    green = random(0, 255);
    blue = random(0, 255);
    rgb(red, green, blue);
    Serial.print("Random Color: ");
    Serial.print(red);
    Serial.print(", ");
    Serial.print(green);
    Serial.print(", ");
    Serial.println(blue);
  }
}

void rgb(int red, int green, int blue)
{
  analogWrite(pinR, red);
  analogWrite(pinG, green);
  analogWrite(pinB, blue);
  delay(interval);
}