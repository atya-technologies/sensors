
/*** Atya Technologies Pvt.Ltd. - Capacitive Touch Sensor ***/

//Variable Declaration:
int sensorPin = A1;  // Pin for capacitive touch sensor (analog pin)
int ledPin = 7;      // Built-in LED connected to D7 pin.

// the setup routine runs once when you press reset:
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("Capacitive Touch Sensor:{");
  // read the state of the Capactive Touchinput pin
  int AnalogValue = analogRead(sensorPin);  // Read the analog value from the sensor
  Serial.print("Analog Value:");
  Serial.print(AnalogValue);
  Serial.print(",");
  Serial.print("Status:");
  if (AnalogValue > 300)  // Threshold value to detect touch (adjust as needed)
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("Touch Detected}");
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Touch not Detected}");
    delay(500);  // delay in between reads for stability in milliseconds
  }
  Serial.println();
}