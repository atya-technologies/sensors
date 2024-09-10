
/*** Atya Technologies Pvt.Ltd. - DHT22 Sensor***/

#include <DHT.h>

#define DHTPIN 2  //Defining DHT22-Data Pin
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

//Variable Declaration:
const int thresholdTemperature = 15;
const int numSamples = 10;

// the setup routine runs once when you press reset:
void setup() 
{
  Serial.begin(9600);  // initialize serial communication at 9600 bits per second
  dht.begin();
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:
void loop() 
{
  // read the state of the DHT22 input pin
  float sumHumidity = 0;
  float sumTemperature = 0;
  for (int i = 0; i < numSamples; i++) {
    float humidity = dht.readHumidity();
    float temperatureCelsius = dht.readTemperature();
    if (!isnan(humidity) && !isnan(temperatureCelsius)) {
      sumHumidity += humidity;
      sumTemperature += temperatureCelsius;
    }
    delay(200);
  }
  float avgHumidity = sumHumidity / numSamples;
  float avgTemperatureCelsius = sumTemperature / numSamples;
  Serial.print("DHT22 Sensor:{Temperature:");
  Serial.print(avgTemperatureCelsius);
  Serial.print("°C");
  Serial.print(",Humidity:");
  Serial.print(avgHumidity);
  Serial.println("%RH}");
  Serial.println();
  delay(1000);  // delay in between reads for stability in milliseconds
}