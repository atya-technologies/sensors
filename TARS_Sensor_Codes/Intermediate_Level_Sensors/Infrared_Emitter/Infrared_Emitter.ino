
/*** Atya Technologies Pvt.Ltd. - Infrared Emitter ***/

//Pin Declaration:
int irLedPin = 3;

// Duration in microseconds for high and low states
int pulseHigh = 500;  // ~38kHz (1/38,000)/2 = 13 microseconds for high state
int pulseLow = 500;   // ~38kHz (1/38,000)/2 = 13 microseconds for low state

void setup() {
  // Set the IR LED pin as an output
  pinMode(irLedPin, OUTPUT);
  Serial.begin(9600);  // initialize serial communication at 9600 bits per second
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

void loop() {
  // Send an IR signal
  Serial.print("Infrared Emitter:");
  digitalWrite(irLedPin, HIGH);
  delay(pulseHigh);
  Serial.println("ON");
  digitalWrite(irLedPin, LOW);
  Serial.println("OFF");  
  delay(pulseLow);
  Serial.println();
}
