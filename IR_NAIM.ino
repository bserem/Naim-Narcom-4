#include "IRremote.h"

IRsend irsend;

int redLED = 6;
int orangeLED = 5;
int greenLED = 4;
int blueLED = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(orangeLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

int khz=38; //NB Change this default value as neccessary to the correct modulation frequency

void loop() {
  digitalWrite(redLED, HIGH);

  for (int i = 0; i < 3; i++) {
    irsend.sendRC5(0x411, 12);
    delay(40);
    irsend.sendRC5(0xC11, 12);
    delay(40);
  }
  digitalWrite(redLED, LOW);
  digitalWrite(orangeLED, HIGH);
  delay(5000); //5 second delay between each signal burst
  digitalWrite(orangeLED, LOW);
}

