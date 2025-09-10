
/*** Atya Technologies Pvt.Ltd. - Touch Sensor***/

//Variable declarations
int touchPin = 2;  // Connected to digital Pin D2
int ledPin = 7;    //Onboard led connected to D7 pin

// the loop routine runs over and over again forever:
void setup() 
{
  pinMode(touchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:
void loop() 
{
  Serial.print("Touch Sensor:");
  int touchState = digitalRead(touchPin);
  if (touchState == HIGH) {     // When the touch sensor is not touched
    digitalWrite(ledPin, LOW);  // Turn off LED
    Serial.println("Touch not Detected");
    delay(500);
  } else {                       // When the touch sensor is touched
    digitalWrite(ledPin, HIGH);  // Turn on LED
    Serial.println("Touch Detected");
    delay(500); 		// delay in milliseconds
  }
  Serial.println();
}