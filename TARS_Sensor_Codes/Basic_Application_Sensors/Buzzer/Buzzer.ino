
/*** Atya Technologies Pvt.Ltd. - Buzzer ***/

//Variable Declaration
int buzzerPin = 2;	//connect to digital pin D2

// the setup routine runs once when you press reset:
void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);  // initialise serial monitor communication
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:
void loop() 
{
  Serial.print("Buzzer:");
  // read the state of the BUZZER input pin
  digitalWrite(buzzerPin, HIGH);
  Serial.println("Buzzer is ON");
  Serial.println();
  delay(1000);  // add delay 1 sec
  Serial.print("Buzzer:");
  digitalWrite(buzzerPin, LOW);
  Serial.println("Buzzer is OFF");
  Serial.println();
  delay(3000);  // add delay in milliseconds
}
