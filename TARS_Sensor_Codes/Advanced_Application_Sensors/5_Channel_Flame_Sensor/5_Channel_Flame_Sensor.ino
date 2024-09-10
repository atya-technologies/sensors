
/*** Atya Technologies Pvt.Ltd. - 5 Channel Flame Sensor ***/

//Variable Declaration:

 int flameSensorPin1 = 5; 
 int flameSensorPin2 = 11;
 int flameSensorPin3 = 2;
 int flameSensorPin4 = 3;
 int flameSensorPin5 = 4;
// Pin connected to the flame sensor

// the setup routine runs once when you press reset:
void setup() {
  pinMode(flameSensorPin1, INPUT);
  pinMode(flameSensorPin2, INPUT);
  pinMode(flameSensorPin3, INPUT);
  pinMode(flameSensorPin4, INPUT);
  pinMode(flameSensorPin5, INPUT); // Initialize flame sensor pin as input
  Serial.begin(9600);  // Initialize serial communication at 9600 baud
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("5 Channel Flame Sensor:");
  if (digitalRead(flameSensorPin1) == LOW) { // Flame detected if sensor pin reads LOW
    Serial.println("Fire detected by 1");
  } else {
    Serial.println("No Fire detected by 1");
  }
  Serial.println();
  Serial.print("5 Channel Flame Sensor:");
  if (digitalRead(flameSensorPin2) == LOW) { // Flame detected if sensor pin reads LOW
    Serial.println("Fire detected by 2");
  } else {
    Serial.println("No Fire detected by 2");
  }
  Serial.println();
  Serial.print("5 Channel Flame Sensor:");
  if (digitalRead(flameSensorPin3) == LOW) { // Flame detected if sensor pin reads LOW
    Serial.println("Fire detected by 3");
  } else {
    Serial.println("No Fire detected by 3");
  }
  Serial.println();
  Serial.print("5 Channel Flame Sensor:");
  if (digitalRead(flameSensorPin4) == LOW) { // Flame detected if sensor pin reads LOW
    Serial.println("Fire detected by 4");
  } else {
    Serial.println("No Fire detected by 4");
  }
  Serial.println();
  Serial.print("5 Channel Flame Sensor:");
  if (digitalRead(flameSensorPin5) == LOW) { // Flame detected if sensor pin reads LOW
    Serial.println("Fire detected by 5");
  } else {
    Serial.println("No Fire detected by 5");
  }
  Serial.println();
  delay(2000);
}
    