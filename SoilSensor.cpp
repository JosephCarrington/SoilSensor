#include "Arduino.h"
#include "SoilSensor.h"
SoilSensor::SoilSensor(String name, int dryLow, int mediumHigh, int mediumLow, int digitalInputPin, int powerPin, int dryPin, int normalPin, int wetPin)
{
  _name = name;
  _dryLow = dryLow;
  _mediumHigh = mediumHigh;
  _mediumLow = mediumLow;
  _digitalInputPin = digitalInputPin;
  _powerPin = powerPin;
  _dryPin = dryPin;
  _normalPin = normalPin;
  _wetPin = wetPin;
  _lastValue = 0;
}

void SoilSensor::begin()
{  
  pinMode(_digitalInputPin, INPUT);
  pinMode(_powerPin, OUTPUT);
  pinMode(_dryPin, OUTPUT);
  pinMode(_normalPin, OUTPUT);
  pinMode(_wetPin, OUTPUT);
  
  digitalWrite(_powerPin, LOW);
  digitalWrite(_dryPin, LOW);
  digitalWrite(_normalPin, LOW);
  digitalWrite(_wetPin, LOW);
}

void SoilSensor::readSoil()
{
  digitalWrite(_powerPin, HIGH);
  delay(10);
  _lastValue = analogRead(_digitalInputPin);
  digitalWrite(_powerPin, LOW);
}

void SoilSensor::setLED()
{
  if(_lastValue >= _dryLow) {
    digitalWrite(_dryPin, HIGH);
    digitalWrite(_normalPin, LOW);
    digitalWrite(_wetPin, LOW);
  }
  else if (_lastValue <= _mediumHigh && _lastValue >= _mediumLow) {
    digitalWrite(_dryPin, LOW);
    digitalWrite(_normalPin, HIGH);
    digitalWrite(_wetPin, LOW);
  }
  else if (_lastValue < _mediumLow) {
    digitalWrite(_dryPin, LOW);
    digitalWrite(_normalPin, LOW);
    digitalWrite(_wetPin, HIGH);
  }
};

void SoilSensor::sense() {
  this->readSoil();
  this->setLED();
}
