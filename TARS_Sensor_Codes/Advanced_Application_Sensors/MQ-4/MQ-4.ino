#include <math.h>

// Pin Definitions
const int analogPin = A1;  // Analog output from MQ-4
const int ledPin = 7;      // LED to indicate gas detection

// Constants
const float V_REF = 5.0;                 // Reference voltage
const int ADC_RESOLUTION = 1023;        // 10-bit ADC
const float RL_VALUE = 10.0;            // Load resistor (kΩ)
const float RO_CLEAN_AIR_FACTOR = 9.83; // From MQ-4 datasheet
float Ro;  // Sensor resistance in clean air

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  Serial.println("Calibrating MQ-4 in clean air...");
  delay(6000);  // Let sensor warm up for 6 seconds
  Ro = calibrateSensor();
  Serial.print("Calibration complete. Ro = ");
  Serial.println(Ro);
}

void loop() {
  int analogValue = analogRead(analogPin);
  float voltage = analogValue * (V_REF / ADC_RESOLUTION);
  float Rs = (V_REF - voltage) * RL_VALUE / voltage;  // Sensor resistance
  float ratio = Rs / Ro;

  float ppm = getMethanePPM(ratio);

  Serial.print("MQ-4 Gas Sensor: ");
  Serial.print(ppm);
  Serial.print(" ppm ");
  if (ppm >= 1000) {
    digitalWrite(ledPin, HIGH);  // Turn on LED for any detection
  } else {
    digitalWrite(ledPin, LOW);   // No gas
  }

  // Classification based on PPM
  if (ppm >= 50 && ppm < 200) {
    Serial.println("Methane (CH₄)");
  }
  else if (ppm >= 200 && ppm < 400) {
    Serial.println("Methane (CH₄); Natural Gas (CH₄ mix)");
  }
  else if (ppm >= 400 && ppm < 1000) {
    Serial.println("Methane (CH₄); Natural Gas (CH₄ mix); Butane; Propane");
  } 
  else if (ppm >= 1000) {
    Serial.println("Methane (CH₄); Natural Gas (CH₄ mix); Butane; Propane; Hydrogen (H₂)");
  }

  Serial.println("");
  delay(2000);
}

float calibrateSensor() {
  int readings = 50;
  float total = 0;

  for (int i = 0; i < readings; i++) {
    int analogVal = analogRead(analogPin);
    float voltage = analogVal * (V_REF / ADC_RESOLUTION);
    float Rs = (V_REF - voltage) * RL_VALUE / voltage;
    total += Rs;
    delay(100);
  }

  float avgRs = total / readings;
  return avgRs / RO_CLEAN_AIR_FACTOR;
}

float getMethanePPM(float ratio) {
  // From MQ-4 datasheet curve: y = a * (x)^b
  // where y = ppm, x = Rs/Ro
  float a = 612.5;     // ppm constant
  float b = -2.074;    // slope (from datasheet log-log curve)

  return a * pow(ratio, b);
}
