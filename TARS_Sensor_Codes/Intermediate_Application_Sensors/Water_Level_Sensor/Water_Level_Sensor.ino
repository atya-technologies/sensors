
/*** Atya Technologies - Water Level Sensor Code ***/

//Pin Declaration:
int ledPin = 13;     //Onboard led connected to D13 pin
int sensorPin = A1;  // Value for storing water level

//Variable declaration
int val = 0;

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  // Set led pin as output
  pinMode(ledPin, OUTPUT);
  // Set to LOW so no power flows through the sensor
  digitalWrite(ledPin, LOW);
}

// the loop routine runs over and over again forever:

void loop() {
  // get the reading from the function below and print it
  int level = readSensor();
  Serial.print("Water Level Sensor:");
  Serial.println(level);
  Serial.println();
  delay(1000);  //add delay on milliseconds
}

// This is a function used to get the sensor reading
int readSensor() {
  digitalWrite(ledPin, HIGH);  // Turn the sensor ON
  delay(500);
  val = analogRead(sensorPin);  // Read the analog value form sensor
  digitalWrite(ledPin, LOW);    // Turn the sensor OFF
  delay(500);
  return val;  // send present reading
}
