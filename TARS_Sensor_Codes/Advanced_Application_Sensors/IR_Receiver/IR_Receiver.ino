
/*** Atya Technologies Pvt.Ltd. - IR Receiver Sensor ***/

#include <IRremote.h>

const int RECV_PIN = 12;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){

  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("Welcome to Atya Technologies Pvt. Ltd.");
}

void loop(){
  Serial.print("IR Receiver:");
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
  Serial.println();
}