
/*** Atya Technologies - BMP180 Sensor Code ***/

#include <Wire.h>
#include <Adafruit_BMP085.h>
#define seaLevelPressure_hPa 1013.25

Adafruit_BMP085 bmp;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  if (!bmp.begin()) {
    //Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    //Uncomment the below line to check the sensor is correctly connected
    while (1) {}
  }
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("BMP180 Sensor:{Temperature:");
  Serial.print(bmp.readTemperature());  //Read Temperature
  Serial.print("°C");
  Serial.print(",Pressure:");  //Read Pressure
  Serial.print(bmp.readPressure());
  Serial.println("Pa}");
  Serial.println();
  delay(1000);  // delay in milliseconds
}
