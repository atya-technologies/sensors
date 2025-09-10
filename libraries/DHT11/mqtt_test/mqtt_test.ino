#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHT11.h"

// DHT11 
DHT11 dht(12);

// Credentials for WiFi
const char* ssid = "Atya_2.4G";
const char* password = "Aty@12345";

// MQTT Server(eg 192.168.1.4)
const char* mqtt_server = "192.168.1.4";

// WiFi Client
WiFiClient nodeClient;
PubSubClient client(nodeClient);

// // DHT Sensor pin at GPIO 13(D7)
// const int DHTPin = 13;

// Initialize DHT sensor
//DHT dht(DHTPin, DHTTYPE);

// Function to connect NodeMCU to WiFi router
void wifiConfig(){
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("WiFi connected, NodeMCU IP address: ");
  Serial.println(WiFi.localIP());
}

// Function to reconnect NodeMCU with MQTT broker
void reconnect(){
    while (!client.connected()) {
      Serial.print("Attempting MQTT connection...");
  
      if (client.connect("MQTTClient")){
        Serial.println("connected");  
      } 
      else{
        Serial.print("failed, State: ");
        Serial.print(client.state());
        Serial.println("try again in 5 seconds...");
        delay(5000);
      }
    }
}

void setup(){
  //dht.begin();
  Serial.begin(115200);
  wifiConfig();
  client.setServer(mqtt_server, 1883);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("MQTTClient");
    
    // Read Humidity
    float H = dht.readHumidity();    
    // Read temperature as Celsius (the default)
    float T = dht.readTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(H) || isnan(T)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    } 

    //Convert float to string and store them in arrays
    static char humidity[7];
    dtostrf(H, 6, 2, humidity);
    static char temperature[7];
    dtostrf(T, 6, 2, temperature);

    // Publishes Temperature and Humidity values
    client.publish("dht11/temperature", temperature);
    client.publish("dht11/humidity", humidity);
    delay(5000);
} 