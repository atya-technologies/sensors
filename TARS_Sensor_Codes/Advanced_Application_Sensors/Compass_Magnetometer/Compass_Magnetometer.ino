
/*** Atya Technologies Pvt.Ltd. - Compass Magnetometer  ***/

#include <Wire.h>
// QMC5883L Compass Library
#include <QMC5883LCompass.h>

QMC5883LCompass compass;

// the setup routine runs once when you press reset:
void setup() {
  // Initialize the serial port.
  Serial.begin(9600);
  // Initialize I2C.
  Wire.begin();
  // Initialize the Compass.
  compass.init();
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

// the loop routine runs over and over again forever:
void loop() {
  Serial.print("Compass Magnetometer:");
  int x, y, z;

  // Read compass values
  compass.read();

  x = compass.getX();
  y = compass.getY();
  z = compass.getZ();

  Serial.print("{X:");
  Serial.print(x);
  Serial.print(",Y:");
  Serial.print(y);
  Serial.print(",Z:");
  Serial.print(z);
  Serial.println("}");
  Serial.println();

  delay(3000);
}
