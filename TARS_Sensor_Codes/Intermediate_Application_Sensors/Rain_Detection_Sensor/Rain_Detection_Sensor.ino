
/*** Atya Technologies - Rain Detection Sensor Code ***/

// Variables declaration:

int rainSensorPin = 2;
int ledPin = 7;  //Onboard led connected to D7 pin

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  //Set rainSensorPin pin as an input
  pinMode(rainSensorPin, INPUT);
  // Set ledPin as output
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  delay(1000);
  Serial.print("Rain Detection Sensor:");
  if (digitalRead(rainSensorPin) == 1) {
    Serial.println("No Rain Detected");
    digitalWrite(ledPin, LOW);
    delay(500);
  } else {
    Serial.println("Rain Detected");
    digitalWrite(ledPin, HIGH);
    delay(500);  //add delay in milliseconds
  }
  Serial.println();
}
