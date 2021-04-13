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
      void readSoil();
      void setLED();
      void sense();
      
    private:
      static int _digitalInputPin;
      static int _powerPin;
      static int _dryPin;
      static int _normalPin;
      static int _wetPin;
      static String _name;
      static int _dryLow;
      static int _mediumHigh;
      static int _mediumLow;
      int _lastValue;
};

#endif
