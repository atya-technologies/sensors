
/*** Atya Technologies Pvt.Ltd. - 1 Channel Relay ***/

//Pin Declaration
int RelayPin = 2;	// Connected to digital Pin D2

// the setup routine runs once when you press reset:
void setup() 
{
  // Set RelayPin as an output pin
  pinMode(RelayPin, OUTPUT);
  Serial.begin(9600);  // initialize serial communication at 9600 bits per second
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:
void loop() 
{
  // Let's turn off the relay
  digitalWrite(RelayPin, LOW);
  Serial.println("1 Channel Relay:Relay is OFF");
  Serial.println();
  delay(1000);

  // Let's turn on the relay
  digitalWrite(RelayPin, HIGH);
  Serial.println("1 Channel Relay:Relay is ON");
  Serial.println();
  delay(1000);		// delay in milliseconds
}
