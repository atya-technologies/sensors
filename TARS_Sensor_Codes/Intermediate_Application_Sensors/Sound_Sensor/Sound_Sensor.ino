
/*** Atya Technologies - Sound Sensor Code ***/

// Variables declaration:

int ledPin = 7;     //Onboard led connected to D7 pin
int sensorPin = 3;  //Sound sensor digital pin
boolean val = 0;

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  // Set led pin as output
  pinMode(ledPin, OUTPUT);
  // Set sensorPin pin as input
  pinMode(sensorPin, INPUT);
}

// the loop routine runs over and over again forever:

void loop() {
  Serial.print("Sound Sensor:");
  val = digitalRead(sensorPin);
  // when the sensor detects a signal above the threshold value, LED flashes
  if (val == HIGH) {
    digitalWrite(ledPin, LOW);
    Serial.println("Sound not detected");
    delay(500);
  } else {
    digitalWrite(ledPin, HIGH);
    Serial.println("Sound detected");
    delay(500);
  }
  Serial.println();  //add delay in milliseconds
}
