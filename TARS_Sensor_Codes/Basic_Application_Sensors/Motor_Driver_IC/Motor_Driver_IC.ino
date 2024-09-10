
/*** Atya Technologies Pvt.Ltd. - Motor Driver IC***/

//Motor A Pin declaration:
int motorPin1 = 2;		//connect to digital pin D2
int motorPin2 = 3;		//connect to digital pin D3

//Motor B Pin declaration:
int motorPin3 = 4;		//connect to digital pin D4
int motorPin4 = 5;		//connect to digital pin D5

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);  // initialize serial communication at 9600 bits per second
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  //Set pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4
  //This code  will turn Motor A clockwise.
  Serial.println("Motor Driver IC:Motor-A turns Clockwise");
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  Serial.println();
  delay(3000);
  //This code will turn Motor A counter-clockwise.
  Serial.println("Motor Driver IC:Motor-A turns counter-clockwise");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  Serial.println();
  delay(3000);

  //This code will turn Motor B clockwise
  Serial.println("Motor Driver IC: Motor-B turns Clockwise");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  Serial.println();
  delay(3000);

  //This code will turn Motor B counter-clockwise
  Serial.println("Motor Driver IC:Motor-B turns counter-clockwise");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  Serial.println();
  delay(3000);

  //And this code will stop motors
  Serial.println("Motor Driver IC:Motor-A and B turns OFF");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  Serial.println();
  delay(2000);  		// delay in milliseconds
}
