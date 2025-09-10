
/*** Atya Technologies - Hall Effect Sensor Code ***/

// Variables declaration:
int hallPin = 3;
int ledPin = 7;	//Onboard led connected to D7 pin

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  //Set hallPin pin as an input
  pinMode(hallPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:

void loop() {
  Serial.print("Hall Effect Sensor:");
  // Read the state of the Hall sensor
  int sensorValue = digitalRead(hallPin);
  if (sensorValue == 0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Hall Effect Detected");
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Hall Effect not Detected");
    delay(500);  //add delay in milliseconds
  }
  Serial.println();
}
