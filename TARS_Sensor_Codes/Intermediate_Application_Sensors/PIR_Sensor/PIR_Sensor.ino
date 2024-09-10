
/*** Atya Technologies - PIR Sensor Code ***/

// Variables declarations:

int pirPin = 2;  
int ledPin = 7; //Onboard led connected to D7 pin

int motionStatus = 0; // variable to store the PIR sensor's motion status (high or low)

// the setup routine runs once when you press reset:

void setup() {
  Serial.begin(9600); // initialize the serial monitor
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  pinMode(pirPin, INPUT); 
}
// the loop routine runs over and over again forever:

void loop() {
  Serial.print("PIR Sensor:");
  motionStatus = digitalRead(pirPin); // read the PIR pin's current output (is it high or low?)
   
    // if the motion status is HIGH
    if (motionStatus == HIGH) { 
      Serial.println("Movement Detected"); // print result to the serial monitor
      digitalWrite(7, HIGH);
      delay(100);
    }
    
    //or else if motion status is low
    else { 
      Serial.println("Movement not Detected"); //print result to the serial monitor
      digitalWrite(7, LOW);
      delay(100);
    }
     delay(100);  // add delay in milliseconds
     Serial.println();
}
    