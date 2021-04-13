#include <MsTimer2.h>
#include "SoilSensor.h"
// Measurements
int dryLow = 600;
int mediumHigh = 550;
int mediumLow = 200;

// H1 Pins
int h1 = 23;
int h1Power = 0;
int h1Dry = 22;
int h1Medium = 21;
int h1Ocean = 20;

// H2 Pins
int h2 = 19;
int h2Power = 1;
int h2Dry = 18;
int h2Medium = 17;
int h2Ocean = 16;

// h3 Pins
int h3 =15;
int h3Power = 2;
int h3Dry = 9;
int h3Medium = 10;
int h3Ocean = 8;

// h4 Pins
int h4 = 14;
int h4Power = 3;
int h4Dry = 4;
int h4Medium = 5;
int h4Ocean = 6;

// Control Pins
int senseButtonPin = 7;
int buttonState = 0;

SoilSensor s1("stringOfPearls", dryLow, mediumHigh, mediumLow, h1, h1Power, h1Dry, h1Medium, h1Ocean);
SoilSensor s2("basil", dryLow, mediumHigh, mediumLow, h2, h2Power, h2Dry, h2Medium, h2Ocean);
SoilSensor s3("succBricc", dryLow, mediumHigh, mediumLow, h3, h3Power, h3Dry, h3Medium, h3Ocean);
SoilSensor s4("theBastard", dryLow, mediumHigh, mediumLow, h4, h4Power, h4Dry, h4Medium, h4Ocean);
void setup() {
  pinMode(senseButtonPin, INPUT_PULLUP);
  
  s1.begin();
  s2.begin();
  s3.begin();
  s4.begin();
  Serial.begin(9600);
  senseAll();
  MsTimer2::set(1000 * 60 * 60, senseAll);
  MsTimer2::start();
}

void loop() {
  buttonState = digitalRead(senseButtonPin);
  if(buttonState == LOW) {
    senseAll();
    delay(1000);
  }
}

void senseAll() {
  s1.sense();
  s2.sense();
  s3.sense();
  s4.sense();
  Serial.println();
}
