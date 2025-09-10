
/*** Atya Technologies -  Flame Sensor Code ***/

// Variables declaration:

int ledPin = 7;     //Onboard led connected to D7 pin
int sensorPin = 3;  //Flame sensor digital pin

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  // Set sensorPin pin as input
  pinMode(sensorPin, INPUT);
  // Set led pin as output
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:

void loop() {
  Serial.print("Flame Sensor:");
  if (digitalRead(sensorPin) == 0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Fire detected");
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("No Fire detected");
    delay(500);  //delay in milliseconds
  }
  Serial.println();
}