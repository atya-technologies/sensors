
/*** Atya Technologies Pvt.Ltd.- Variable Potentiometer ***/

//Variable Declaration:
int AnalogPin = A1;

// the setup routine runs once when you press reset:
void setup() 
{
  // initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:
void loop() 
{
  Serial.print("Variable Potentiometer:");
  int AnalogValue = analogRead(AnalogPin);  // read the input on analog pin:
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = AnalogValue * (5.0 / 1023.0);
  Serial.println(voltage);       // print the voltage
  Serial.println();
  delay(1000);  				 // add delay in milliseconds
}
