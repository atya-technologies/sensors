
/*** Atya Technologies Pvt.Ltd. - LM35 Sensor ***/

//Variable Declaration
int temperaturePin = A0;
int numSamples = 10;
int thresholdTemperature = 30;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("LM35 Sensor:");
  // read the state of the TEMP LM 35 input pin
  float averageVoltage = 0;
  for (int i = 0; i < numSamples; i++) {
    int sensorValue = analogRead(temperaturePin);
    float voltage = sensorValue * (5.0 / 1023.0);  // Fix typo: float voltage instead of floatVoltage
    averageVoltage += voltage;
    delay(10);
  }
  averageVoltage /= numSamples;
  float temperatureCelsius = averageVoltage * 100;
  Serial.print(temperatureCelsius);
  Serial.println("°C");
  Serial.println();
  delay(1000);      // delay in milliseconds
}