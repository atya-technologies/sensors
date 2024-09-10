
/*** Atya Technologies - Soil Moisture Sensor Code ***/

// Variables declaration:

int soilSensorPin = A1;  // Define the analog input pin for the soil moisture sensor
int ledPin = 7;          //Onboard led connected to D7 pin

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  // Set led pin as output
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:

void loop() {
  Serial.print("Soil Moisture Sensor:");
  int AnalogValue = analogRead(soilSensorPin);  // Read the analog value from the sensor
  // Serial.print(AnalogValue);
  // Serial.print(",Status:");
  if (AnalogValue <= 500) {  // Adjust the threshold as needed
    Serial.println("Soil Moisture Detected");
    digitalWrite(ledPin, HIGH);
    delay(500);
  } else {
    Serial.println("Soil Moisture not Detected");
    digitalWrite(ledPin, LOW);
    delay(500);        //add delay in milliseconds
  }
  Serial.println();
}
