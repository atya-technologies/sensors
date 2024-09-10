
/*** Atya Technologies - 1 Channel Relay - Flame Detection Sensor Code ***/

// Variables declaration:

int flameSensorPin = A1;  // Pin where the flame sensor is connected
int relayPin = 3;         // Pin where the relay module is connected

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  pinMode(flameSensorPin, INPUT);  // Initialize the flame sensor pin as input
  pinMode(relayPin, OUTPUT);       // Initialize the relay pin as output
}

// the loop routine runs over and over again forever:

void loop() {
  Serial.print("1 Channel Relay - Flame Detection Sensor:");
  int flameState = analogRead(flameSensorPin);  // Read the state of the flame sensor
  if (flameState <= 700) {         // Flame detected (assuming the sensor outputs LOW when a flame is detected)
    digitalWrite(relayPin, HIGH);  // Activate the relay
    Serial.println("Fire detected");
    delay(500);
  } else {
    digitalWrite(relayPin, LOW);  // Deactivate the relay
    Serial.println("No Fire detected");
    delay(500);  //add delay in milliseconds
  }
  Serial.println();
}