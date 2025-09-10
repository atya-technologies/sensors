/*** Atya Technologies Pvt. Ltd.- OLED_Display ***/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>


#define i2c_Address 0x3C //initialize with the I2C addr 0x3C
#define SCREEN_WIDTH 128 // OLED display width, in pixels 
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

//Variable Declaration
int temperaturePin = A0;
int numSamples = 50;
int thresholdTemperature = 30;

// the setup routine runs once when you press reset:
void setup()   {
  Serial.begin(9600);
  delay(250); // wait for the OLED to power up
  // Display initialization
  display.begin(i2c_Address, true); // Address 0x3C default
  // Clear the buffer.
  display.clearDisplay();
 // text display tests
  display.setTextSize(3);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  display.println("  Atya"); 
  display.setTextSize(1.3);
  display.setTextColor(SH110X_WHITE);
  display.println("      Technologies"); 
  display.println("        Pvt. Ltd.");
  Serial.println("Welcome to Atya Technologies Pvt Ltd.");
  display.display();
  delay(1000);
  display.clearDisplay();
}

// the loop routine runs over and over again forever:
void loop() {
 
  Serial.print("OLED Display:");
  Serial.println("Hello World");
  Serial.println();

  //To display temperature on OLED display
  display.clearDisplay();
  display.setTextSize(1.5);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0, 0);
  //Insert the required text/variables to be printed in display.println/display.print
  display.println("OLED Display:");
  display.print("Hello World");    
  display.display();
  delay(2000);    // delay in between reads for stability in milliseconds
  display.clearDisplay();
  display.display();
}
