/** Atya Technologies Pvt. Ltd. - Slide Switch **/

// Define switch pins
const int switchPin1 = 9;
const int switchPin2 = 12;
const int switchPin3 = 11;

// Define LED pins
const int ledPin1 = 7;
const int ledPin2 = 13;
const int ledPin3 = 2;

// the setup routine runs once when you press reset:

void setup() {
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");

  // Initialize switch pins as inputs with internal pull-up resistors
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);
  pinMode(switchPin3, INPUT_PULLUP);

  // Initialize LED pins as outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

// the loop routine runs over and over again forever:

void loop() {
  // Read the state of each switch
  int switchState1 = digitalRead(switchPin1);
  int switchState2 = digitalRead(switchPin2);
  int switchState3 = digitalRead(switchPin3);

  // Print switch states to the serial monitor
  Serial.print("Slide Switch:{");
  // Check if each switch is ON or OFF and print the status
  if (switchState1 == LOW) {
    digitalWrite(ledPin1,HIGH);
    Serial.print("Switch1:ON,");
  } else {
    digitalWrite(ledPin1,LOW);
    Serial.print("Switch1:OFF,");
  }

  if (switchState2 == LOW) {
    digitalWrite(ledPin2,HIGH);
    Serial.print("Switch2:ON,");
  } else {
    digitalWrite(ledPin2,LOW);
    Serial.print("Switch2:OFF,");
  }

  if (switchState3 == LOW) {
    digitalWrite(ledPin3,HIGH);
    Serial.println("Switch3:ON}");
  } else {
    digitalWrite(ledPin3,LOW);
    Serial.println("Switch3:OFF}");
  }
  Serial.println();
  // Small delay to debounce switches
  delay(1000);
}