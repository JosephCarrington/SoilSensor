/**
 * SoilSensor.h - Library to read some cheapass soil sensors
 * Created by joseph Carrington, April 12, 2021
 * Released into the public domain
 */

#ifndef SoilSensor_h
#define SoilSensor_h

#include "Arduino.h"

class SoilSensor {
    public:
      SoilSensor(String name, int digitalInputPin, int dryLow, int mediumHigh, int mediumLow, int powerPin, int dryPin, int normalPin, int wetPin);
      void begin();
      void readSoil();
      void setLED();
      void sense();
      
    private:
      int _digitalInputPin;
      int _powerPin;
      int _dryPin;
      int _normalPin;
      int _wetPin;
      String _name;
      int _dryLow;
      int _mediumHigh;
      int _mediumLow;
      int _lastValue;
};

#endif
