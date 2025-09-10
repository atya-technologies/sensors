
/*** Atya Technologies Pvt. Ltd. - Tilt Sensor Code ***/


// Variables declaration:
int tiltsensorPin = 3;  //Tilt sensor digital pin
int ledPin = 7;         //Onboard led connected to D7 pin

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  // Set tiltsensor pin as input
  pinMode(tiltsensorPin, INPUT);
  // Set led pin as output
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("Tilt Sensor:");
  if (digitalRead(tiltsensorPin)) {
    digitalWrite(ledPin, LOW);
    Serial.println("Tilt not detected");
    delay(500);
  } else {
    digitalWrite(ledPin, HIGH);
    Serial.println("Tilt detected");
    delay(500);  //add delay in milliseconds
  }
  Serial.println();
}