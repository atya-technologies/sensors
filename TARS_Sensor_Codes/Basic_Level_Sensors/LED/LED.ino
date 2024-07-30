
/*** Atya Technologies Pvt.Ltd. - LED ***/

//Variable Declaration
int ledPin = 2;

// the setup routine runs once when you press reset:
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("LED:");
  // read the state of the LED input pin
  digitalWrite(ledPin, HIGH);
  Serial.println("LED is ON");
  Serial.println();
  delay(500);
  digitalWrite(ledPin, LOW);
  Serial.print("LED:");
  Serial.println("LED is OFF");
  Serial.println();
  delay(1000);  // add delay 1 sec
}
