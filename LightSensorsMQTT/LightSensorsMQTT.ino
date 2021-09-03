

#include <Wire.h>
#include <BH1750.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid= "FAMILIA MARTINEZ ";
const char* password= "22528561mvl";
const char* mqtt_server = "192.168.1.72";

#define mqtt_port 1883

#define MQTT_SERIAL_PUBLISH_CH_1 "oficina/ESP32/luz1"
#define MQTT_SERIAL_RECEIVER_CH_1 "oficina/ESP32/luz1"
#define MQTT_SERIAL_PUBLISH_CH_2 "oficina/ESP32/luz2"
#define MQTT_SERIAL_RECEIVER_CH_2 "oficina/ESP32/luz2"
double lux1 =0;
double lux2 =0;

BH1750 bh1750_a;
BH1750 bh1750_b;

/* Conexión Wifi y MQTT */ 
WiFiClient wifiClient;
PubSubClient client(wifiClient); // WiFiClient espClient; PubSubClient client(espClient);

// conexión a WiFi
void setup_wifi() {
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
    randomSeed(micros());
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}
// conexion a MQTT
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      //Once connected, publish an announcement...
      client.publish(MQTT_SERIAL_PUBLISH_CH_1, "00");
      client.publish(MQTT_SERIAL_PUBLISH_CH_2, "00");
      // ... and resubscribe
      client.subscribe(MQTT_SERIAL_RECEIVER_CH_1);
      client.subscribe(MQTT_SERIAL_RECEIVER_CH_2);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte *payload, unsigned int length) {
    Serial.println("-------new message from broker-----");
    Serial.print("channel:");
    Serial.println(topic);
    Serial.print("data:");  
    Serial.write(payload, length);
    Serial.println();
}



void setup(){

  Serial.begin(115200);

 
  Wire.begin(18, 19);
  Wire1.begin(21, 22);
  bh1750_a.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x23, &Wire);
  bh1750_b.begin(BH1750::CONTINUOUS_HIGH_RES_MODE, 0x23, &Wire1);
 
   setup_wifi();
   client.setServer(mqtt_server, mqtt_port);
   client.setCallback(callback);
   reconnect();






void loop() {
  
  
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  //float light_level_a;
  if (bh1750_a.measurementReady()) { 
    lux1 = bh1750_a.readLightLevel();
    char luz1[8];
    dtostrf(lux1,5,2,luz1);
    client.publish(MQTT_SERIAL_PUBLISH_CH_1,luz1);
  }
  float light_level_b; 
  if (bh1750_b.measurementReady()) { 
    lux2 = bh1750_b.readLightLevel();
    char luz2[8];
    dtostrf(lux2,5,2,luz2);
    client.publish(MQTT_SERIAL_PUBLISH_CH_2,luz2); 
  }
  
  
   
  

  
  


}
