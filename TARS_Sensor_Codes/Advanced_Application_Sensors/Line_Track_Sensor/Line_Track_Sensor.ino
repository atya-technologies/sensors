
/*** Atya Technologies - Line Track Sensor ***/

//Pin Declaration:
int sensorPin = 3;
int ledPin = 7;  //Onboard LED connected to D7 pin

// Variables declaration:
int val;  // variable to store sensor reading

// the setup routine runs once when you press reset:

void setup() {
  pinMode(ledPin, OUTPUT);
  // Set led pin as output
  pinMode(sensorPin, INPUT);  // define sensor as input
  Serial.begin(9600);         // initialize serial communication with PC
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:

void loop() {
  Serial.print("Line Track Sensor:");
  val = digitalRead(sensorPin);  // read value from sensor
  if (val == LOW) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Line Not detected");
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Line detected");
    delay(500);
  }
  Serial.println();
}
