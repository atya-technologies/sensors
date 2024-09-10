
/*** Atya Technologies Pvt.Ltd. - LM35 Sensor ***/


// Define the analog pin, the LM35's Vout pin is connected to
int sensorPin=A0;
//Variable Declaration
long int aref_voltage_millivolts = 5000;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("LM35 Sensor:");
  float analogValue=0;
  // Get the voltage reading from the LM35
   analogValue = analogRead(sensorPin);
  //Convert the analogValue into the temperature in Celsius
  float temperatureC = (500.0-((analogValue * aref_voltage_millivolts) / 1024.0)) / 10.0 ;

  // Print the temperature in Celsius
  Serial.print(temperatureC);
  Serial.println("°C"); // shows degree symbol
  Serial.println();
  delay(1000); 		// delay in millisecond
}