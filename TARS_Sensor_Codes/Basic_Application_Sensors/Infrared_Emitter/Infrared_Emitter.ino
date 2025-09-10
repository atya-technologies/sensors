
/*** Atya Technologies Pvt.Ltd. - Infrared Emitter ***/

//Pin Declaration:
int irLedPin = 3;		//connect to digital pin D3

// Duration in microseconds for high and low states
int pulseHigh = 1000;  
int pulseLow = 1000;   

void setup() {
  // Set the IR LED pin as an output
  pinMode(irLedPin, OUTPUT);
  Serial.begin(9600);  // initialize serial communication at 9600 bits per second
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

void loop() {

  // Send an IR signal
  delay(1000);  // Send the signal for 1000 milliseconds (1 second)
  Serial.print("Infrared Emitter:");
  digitalWrite(irLedPin, HIGH);
  Serial.println("ON");
  delay(pulseHigh);
  Serial.println();
  Serial.print("Infrared Emitter:");
  digitalWrite(irLedPin, LOW);
  Serial.println("OFF");
  delay(pulseLow);
  Serial.println();			//delay in milliseconds

}