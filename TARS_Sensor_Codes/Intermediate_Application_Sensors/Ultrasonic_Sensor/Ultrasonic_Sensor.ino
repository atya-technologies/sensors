
/*** Atya Technologies - Ultrasonic Sensor Code ***/

// Variables declarations:

const int trigPin = 9;
const int echoPin = 10;


float duration, distance;

// the setup routine runs once when you press reset:

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");

}

// the loop routine runs over and over again forever:

void loop() {
  Serial.print("Ultrasonic Sensor:");
  digitalWrite(trigPin, LOW);
  delayMicroseconds(200);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(200);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.println(distance);
  Serial.println();
  delay(1000);    		// add delay in milliseconds
  
}