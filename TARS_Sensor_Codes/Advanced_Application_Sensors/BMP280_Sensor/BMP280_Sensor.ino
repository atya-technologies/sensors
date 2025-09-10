
/*** Atya Technologies Pvt. Ltd. - BMP280 Sensor ***/       

#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp; // I2C Interface
void setup() 

{
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd. - BMP280 Sensor");

  if (!bmp.begin(0x76)) {
    //Uncomment the below line if you are 
    //Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  // Default settings from datasheet.
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     // Operating Mode
                  Adafruit_BMP280::SAMPLING_X2,     // Temp. oversampling
                  Adafruit_BMP280::SAMPLING_X16,    // Pressure oversampling
                  Adafruit_BMP280::FILTER_X16,      // Filtering
                  Adafruit_BMP280::STANDBY_MS_500); // Standby time
}

void loop() 
{
  Serial.print("BMP280 Sensor:{");
  Serial.print("Temperature:");
  Serial.print(bmp.readTemperature());
  Serial.print("°C");
  Serial.print(",Pressure:");
  Serial.print(bmp.readPressure() / 100);  // Display pressure in hPa
  Serial.println("hPa}");
  Serial.println();
  delay(1000);
}

