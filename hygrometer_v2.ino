
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
// h1 Val
int h1Value = 0;

// H2 Pins
int h2 = 19;
int h2Power = 1;
int h2Dry = 18;
int h2Medium = 17;
int h2Ocean = 16;
// h2 Value
int h2Value = 0;

// h3 Pins
int h3 =15;
int h3Power = 2;
int h3Dry = 9;
int h3Medium = 10;
int h3Ocean = 8;
// h2 Value
int h3Value = 0;

SoilSensor s1 = SoilSensor("String Of Pearls", dryLow, mediumHigh, mediumLow, h1, h1Power, h1Dry, h1Medium, h1Ocean);

void setup() {
  s1.begin();
  Serial.begin(9600);
}

void loop() {
  s1.sense();
//  s2.sense();
//  s3.sense();
  delay(1000 * 60 * 60);

}
