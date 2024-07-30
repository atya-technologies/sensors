
/*** Atya Technologies Pvt.Ltd. - 4 Digit 7 Segment Display***/

#include <Wire.h>
#include <TM1637Display.h>

// Define the pins for TM1637 display module
#define CLK A5  // Connect CLK pin of TM1637 to Arduino pin A5
#define DIO A4  // Connect DIO pin of TM1637 to Arduino pin A4

// Create a TM1637Display object
TM1637Display display(CLK, DIO);

// the setup routine runs once when you press reset:
void setup() {
  // Set brightness level (0-7)
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
  display.setBrightness(7);  // Adjust brightness as needed (0 is dimmest, 7 is brightest)
}

// the loop routine runs over and over again forever:
void loop() {
  int num=1234;
  display.showNumberDec(1234);
  Serial.print("4 Digit 7 Segment Display:");
  Serial.println(num);
  Serial.println();
  delay(500);
  display.showNumberDec(0);
  Serial.print("4 Digit 7 Segment Display:");
  Serial.println("0");
  Serial.println();
  delay(500);  // Delay for one second
}