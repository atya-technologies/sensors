
/*** Atya Technologies - SHTC3 Sensor Code ***/

#include "Adafruit_SHTC3.h"

Adafruit_SHTC3 shtc3 = Adafruit_SHTC3();

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");

  while (!Serial)
    delay(10);
  if (!shtc3.begin()) {
    //Uncomment the below print statement, to check the sensor connection status in Arduino IDE Serial monitor
    //Serial.println("SHTC3 Sensor not Connected");
  } else {
    //Uncomment the below print statement, to check the sensor connection status in Arduino IDE Serial monitor
    //Serial.println("SHTC3 Sensor Connected");
  }
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("SHTC3 Sensor:{Temperature:");
  sensors_event_t humidity, temp;
  shtc3.getEvent(&humidity, &temp);  // populate temp and humidity objects with fresh data
  Serial.print(temp.temperature);
  Serial.print("°C");
  Serial.print(",Humidity:");
  Serial.print(humidity.relative_humidity);
  Serial.println("%RH}");
  Serial.println();
  delay(1000);  //add delay on milliseconds
}