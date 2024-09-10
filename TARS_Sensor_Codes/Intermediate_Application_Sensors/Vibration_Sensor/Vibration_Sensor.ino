
/*** Atya Technologies Pvt. Ltd. - Vibration Sensor Code ***/

//Variables declaration:

int analogPin = A2;  // Define the analog pin connected to the vibration sensor
int digitalPin = 7;  //Onboard led connected to D7 pin
// Define the threshold above which vibration is detected
int thresholdValue = 500;  // Adjust this value according to your sensor readings

void setup() {
  pinMode(digitalPin, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

void loop() {
  Serial.print("Vibration Sensor:");
  // Read the analog value from the sensor
  int sensorValue = analogRead(analogPin);
  //Check if sensor value exceeds the threshold
  if (sensorValue > thresholdValue) {
    // Print message to indicate vibration detected
    Serial.println("Vibration detected");
    digitalWrite(digitalPin, HIGH);
    delay(500);
    // You can also add additional actions here, like triggering an event or alarm
  } else {
    // Print message to indicate no vibration detected
    Serial.println("No Vibration detected");
    digitalWrite(digitalPin, LOW);
    delay(500);  //add delay in milliseconds
  }
  Serial.println();
}
