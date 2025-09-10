
/*** Atya Technologies Pvt.Ltd. - Mini Reed Switch ***/

//Variable Declaration
int reedPin = A1;
int ledPin = 7;  //Onboard led connected to D7 pin

// the setup routine runs once when you press reset:
void setup() {
  pinMode(reedPin, INPUT);
  pinMode(ledPin, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}
// the loop routine runs over and over again forever:
void loop() {
  Serial.print("Mini Reed Switch:");
  // read the state of the REED Switch input pin
  int analogValue = analogRead(reedPin);  // Read the state of the reed switch
  if (analogValue == 0) 
  {
    digitalWrite(ledPin, HIGH);  // Turn off LED
    Serial.println("Mini Reed Switch is CLOSED");
  } 
  else 
  {
    digitalWrite(ledPin, LOW);  // Turn on LED
    Serial.println("Mini Reed Switch is OPEN");
  }
  Serial.println();
  delay(500);  			// delay in millilseconds
}
