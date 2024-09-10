
/*** Atya Technologies - Ambient Light Sensor Code ***/

// Variables declaration:
int temt6000Pin = A1;
float light;
int light_value;

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  pinMode(temt6000Pin, INPUT);  //data pin for ambient light sensor
}

// the loop routine runs over and over again forever:

void loop() {
  Serial.print("Ambient Light Sensor:");
  int light_value = analogRead(temt6000Pin);
  light = light_value * 0.0976;  // percentage calculation
  Serial.print(light);
  Serial.println("%");
  Serial.println();
  delay(1000);  //add delay in milliseconds
}