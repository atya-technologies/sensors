
/*** Atya Technologies - IR Transceiver Code ***/

// Variables declaration:

int IR_SENSOR_PIN = 2;
int ledPin = 7;  //Onboard led connected to D7 pin

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  pinMode(IR_SENSOR_PIN, INPUT);  // Set sensor pin as input
}

// the loop routine runs over and over again forever:

void loop() {
  Serial.print("IR Transceiver:");
  // Read the sensor value
  int sensorValue = digitalRead(IR_SENSOR_PIN);

  // Check if object is detected or not
  if (sensorValue == HIGH) {
    Serial.println("No Object Detected");
    digitalWrite(ledPin, LOW);
    delay(500);  //add delay in milliseconds
  } else {
    Serial.println("Object Detected");
    digitalWrite(ledPin, HIGH);
    delay(500);
  }
  Serial.println();
}
