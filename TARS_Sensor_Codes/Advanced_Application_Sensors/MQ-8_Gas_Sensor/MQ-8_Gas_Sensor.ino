
/**** Atya Technologies Pvt. Ltd. - MQ-8 Gas Sensor ****/

// Pin Declaration
int analogPin = A1;  // Pin connected to A1 
int digitalPin = 3;  // Pin connected to D3
int ledPin = 13;     // Onboard LED connected to D13 pin

// Constants Declaration
const float V_REF = 5.0; // Reference voltage of the Arduino
const int ADC_RESOLUTION = 1023; // ADC resolution (10-bit ADC)
const float RL_VALUE = 10; // Load resistance in kilo ohms
const float RO_CLEAN_AIR_FACTOR = 9.21; // Clean air factor (from datasheet)

// Variable Declaration
float Ro = 10; // Ro is the sensor resistance in clean air

void setup() {
  // initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  pinMode(digitalPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  Ro = calibrateSensor();
  //Serial.print("Calibrated Ro: ");
 // Serial.print(Ro);
  //Serial.println(" kohm");
}

void loop() 
{
  Serial.print("MQ-8 Gas Sensor:"); 
  // read digital and analog pin values
  int analogValue = analogRead(analogPin);
  int digitalValue = digitalRead(digitalPin);

  // Convert analog value to voltage
  float voltage = analogValue * (V_REF / ADC_RESOLUTION);
  
  // Calculate the sensor resistance
  float Rs = (V_REF / voltage - 1) * RL_VALUE;
  
  // Calculate the ratio of Rs/Ro
  float ratio = Rs / Ro;

  // Convert the ratio to ppm (using the MQ-8 characteristic curve)
  float ppm = getGasConcentration(ratio);

  //Serial.print("Analog Value:");
  //Serial.print(analogValue);
 // Serial.print(",");
  //Serial.print(", Digital Value: ");
  //Serial.print(digitalValue);

 // Serial.print("PPM:");
 // Serial.print(ppm);
 // Serial.print(",");
  //Serial.print("Status:");
  if (ppm > 100) 
  { 
    Serial.println("Gas detected");
    digitalWrite(ledPin, HIGH); // Turn on LED if gas detected
  } else {
    Serial.println("Gas not detected");
    digitalWrite(ledPin, LOW); // Turn off LED if gas not detected
  }
  Serial.println();
  
  delay(1000); // Delay for a second before the next reading
}

// Function to calibrate the sensor
float calibrateSensor() {
  int totalReadings = 50;
  float sensorValue = 0;
  for (int i = 0; i < totalReadings; i++) {
    sensorValue += analogRead(analogPin);
    delay(50);
  }
  sensorValue /= totalReadings;
  float sensorVoltage = sensorValue * (V_REF / ADC_RESOLUTION);
  float sensorResistance = (V_REF / sensorVoltage - 1) * RL_VALUE;
  return sensorResistance / RO_CLEAN_AIR_FACTOR;
}

// Function to convert the Rs/Ro ratio to ppm
float getGasConcentration(float ratio) {
  // Approximate curve: log(PPM) = log(A) + B * log(Rs/Ro)
  // For MQ-8: log(PPM) = log(1000) - 2.3 * log(Rs/Ro)
  // PPM = A * (Rs/Ro)^B
  float A = 1000.0;
  float B = -2.3;
  return A * pow(ratio, B);
}
