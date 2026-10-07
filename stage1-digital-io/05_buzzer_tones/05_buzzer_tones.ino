// C++ code
//
int pinPiezo = 8;
int notes[] = {262,294,330,349};
void setup()
{
  pinMode(pinPiezo, OUTPUT);
}

void loop()
{
  //alarmSignal();
  piano();
}

void piano()
{
  for (int i=0;i<4;i++) {
    tone(pinPiezo, notes[i], 300);
    delay(350);
  }
  noTone(pinPiezo);
  delay(1000);
}

void alarmSignal() {
  for (int i=500; i<= 1500; i+=10) {
    tone(pinPiezo, i);
    delay(10);
  }
  
  for (int i=1500; i>= 500; i-=10) {
    tone(pinPiezo, i);
    delay(10);
  }
  
  noTone(pinPiezo);
  delay(500);
}