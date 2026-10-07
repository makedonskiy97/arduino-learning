// Project 5: siren + melody on a passive buzzer
// Wiring: buzzer + -> pin 8, buzzer - -> GND
//         button between pin 2 and GND (INPUT_PULLUP)
// Button press cycles: off -> siren -> melody -> off
#include "melody.h"

const uint8_t BUZZER = 8;
const uint8_t BUTTON = 2;

uint8_t mode = 0;             // 0 off, 1 melody, 2 siren
uint8_t lastBtn = HIGH;
uint16_t melodyIdx = 0;
unsigned long noteEnd = 0;
int sirenFreq = 600, sirenStep = 8;
unsigned long lastSiren = 0;

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void startMode(uint8_t m) {
  noTone(BUZZER);
  mode = m;
  melodyIdx = 0;
  noteEnd = 0;
  sirenFreq = 600; sirenStep = 8;
}

void loop() {
  // button with simple debounce
  uint8_t b = digitalRead(BUTTON);
  if (b == LOW && lastBtn == HIGH) {
    startMode((mode + 1) % 3);
    delay(30);
  }
  lastBtn = b;

  unsigned long now = millis();

  if (mode == 2) {                       // siren 600..1200 Hz up and down
    if (now - lastSiren >= 5) {
      lastSiren = now;
      sirenFreq += sirenStep;
      if (sirenFreq >= 1200 || sirenFreq <= 600) sirenStep = -sirenStep;
      tone(BUZZER, sirenFreq);
    }
  } else if (mode == 1) {                // melody from melody.h, loops
    if (now >= noteEnd) {
      if (melodyIdx >= MELODY_LEN) melodyIdx = 0;
      uint16_t f = pgm_read_word(&melodyFreq[melodyIdx]);
      uint16_t d = pgm_read_word(&melodyDur[melodyIdx]);
      if (f) tone(BUZZER, f); else noTone(BUZZER);
      noteEnd = now + d;
      melodyIdx++;
    }
  }
}
