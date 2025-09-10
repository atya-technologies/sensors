
/*** Atya Technologies Pvt.Ltd. - Push Button ***/

int BUTTON_PIN = 2;  //connect to digital pin D4

void setup() 
{
  Serial.begin(9600);  // Initialize serial communication at 9600 baud
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}
void loop() 
{
  byte buttonState = digitalRead(BUTTON_PIN);
  Serial.print("Push Button:");
  if (buttonState == LOW) 
  {
    Serial.println("Button is pressed");
  } 
  else 
  {
    Serial.println("Button is not pressed");
  }
  Serial.println();
  delay(100);		 // add delay in milliseconds
}