
/*** Atya Technologies Pvt.Ltd. - RGB LED ***/

// Pin definitions for RGB LED (common cathode)
int redPin = 9;			//connect to digital pin D9
int greenPin = 12;		//connect to digital pin D12
int bluePin = 11;		//connect to digital pin D11

// the setup routine runs once when you press reset:
void setup() 
{
  // Set RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  delay(1000);
}

// the loop routine runs over and over again forever:
void loop() 
{
  // To Glow Red LED
  setColor(255, 0, 0);
  Serial.println("RGB LED:LED turns to Red Colour");
  Serial.println();
  delay(2000);  	// add delay in milliseconds

  //  To Glow Green LED
  setColor(0, 255, 0);
  Serial.println("RGB LED:LED turns to Green Colour");
  Serial.println();
  delay(2000);  	// add delay in milliseconds

  // To Glow Blue LED
  setColor(0, 0, 255);
  Serial.println("RGB LED:LED turns to Blue Colour");
  Serial.println();
  delay(2000);  	// add delay in milliseconds
}

//Function to analog write to the pin to get required colours
void setColor(int redValue, int greenValue, int blueValue) {
  // For common cathode RGB LED (0-255)
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
