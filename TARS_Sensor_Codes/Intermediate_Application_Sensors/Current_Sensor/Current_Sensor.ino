
/*** Atya Technologies Pvt.Ltd. - Current Sensor ***/

//Variable declaration:
int analogPin = A0;  // Pin connected to the OUT pin of ACS712
int sensorOffset = 512; // Midpoint of analog reading (0A current)
float sensitivity = 185.0;  // mV per A for ACS712-05B
// Number of samples for RMS calculation
int numSamples = 2000;
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Serial.println(“Welcome to Atya Technologies Pvt. Ltd.”);
  pinMode(analogPin, INPUT);
}
// the loop routine runs over and over again forever:
void loop() {
  float currentRMS = calculateRMS();
  // Print the RMS current value
  Serial.print("Current Sensor:");
  Serial.print(currentRMS);
  Serial.println(" A");
  Serial.println();
  delay(1000);  // Wait for 1 second before the next reading
}
// Function to calculate RMS current
float calculateRMS() {
  long sumOfSquares = 0;
  for (int i = 0; i < numSamples; i++) {
    int analogValue = analogRead(analogPin);
    int voltage = analogValue - sensorOffset;
    sumOfSquares += voltage * voltage;
    delayMicroseconds(1000);
  }
  float meanSquare = sumOfSquares / (float)numSamples;
  float rootMeanSquare = sqrt(meanSquare);
  // Convert to current (in Amperes)
  float current = rootMeanSquare * 5.0 / 1023.0 * 1000.0 / sensitivity;
  return current;
}
