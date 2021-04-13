
  #include "SoilSensor.h"
// Measurements
int dryHigh = 1023;
int dryLow = 601;
int mediumHigh = 600;
int mediumLow = 51;

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

SoilSensor s1("String Of Pearls", dryLow, mediumHigh, mediumLow, h1, h1Power, h1Dry, h1Medium, h1Ocean);
SoilSensor s2("Basil", dryLow, mediumHigh, mediumLow, h2, h2Power, h2Dry, h2Medium, h2Ocean);
SoilSensor s3("Succ Bricc", dryLow, mediumHigh, mediumLow, h3, h3Power, h3Dry, h3Medium, h3Ocean);

void setup() {
  s1.begin();
  s2.begin();
  s3.begin();
  Serial.begin(9600);
}

void loop() {
  s1.sense();
  s2.sense();
  s3.sense();
  delay(1000 * 60 * 60);

}
