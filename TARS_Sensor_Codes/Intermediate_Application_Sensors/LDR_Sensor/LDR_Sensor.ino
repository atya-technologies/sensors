
/*** Atya Technologies - LDR Sensor Code ***/

// Variables declaration:

int ledPin = 7;   //Onboard led connected to D7 pin
int ldrPin = A1;  //the number of the LDR pin

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  // Set ledPin as output
  pinMode(ledPin, OUTPUT);
  //Set LDR pin as an input
  pinMode(ldrPin, INPUT);
}

// the loop routine runs over and over again forever:

void loop() {
  Serial.print("LDR Sensor:");
  int AnalogValue = analogRead(ldrPin);  //read the status of the LDR value

  if (AnalogValue <= 80) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Light Detected");
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("Light not Detected");
    delay(500);  //add delay in milliseconds
  }
  Serial.println();
}
