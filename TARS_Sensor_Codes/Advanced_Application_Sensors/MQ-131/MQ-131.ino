// MQ-131 Gas Sensor - Print PPM Value Only

const int mq131Pin = A1;       // Analog pin connected to sensor
float R0 = 9.21;            // Replace with your calibrated R0 value
float RL = 10000;            // Load resistance in ohms (usually 10k)

void setup() {
  Serial.begin(9600);
  pinMode(mq131Pin, INPUT);
}

void loop() {
  int adcValue = analogRead(mq131Pin);
  float voltage = adcValue * (5.0 / 1023.0); // Convert to voltage

  float RS = (5.0 - voltage) * RL / voltage; // Sensor resistance
  float ratio = RS / R0;                     // Ratio RS/R0

  // Estimate PPM using sensor's curve (approximation)
  float ppm = pow(10, ((log10(ratio) - 0.40) / -0.45));

  // Print only the PPM value followed by " ppm"
  Serial.print("MQ-131 Gas Sensor: ");
  Serial.print(ppm);
  Serial.println(" ppm");

  delay(2000); // Wait 2 seconds between readings
}