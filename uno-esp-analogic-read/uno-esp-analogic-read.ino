
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

/* ------------------------ */
/* -------- WIFI ---------- */

#define SSID "TYPE YOUR WIFI NAME HERE"
#define PWD  "TYPE YOUR WIFI PASSWORD HERE"

/* ------------------------ */
/* -------- MQTT ---------- */

#define TOPICO_PUBLISH_VALUE_1 "device/uno/analogic/value_1"
#define TOPICO_PUBLISH_VALUE_2 "device/uno/analogic/value_2"
#define TOPICO_PUBLISH_VALUE_3 "device/uno/analogic/value_3"
#define TOPICO_PUBLISH_DEVICE_IP "device/uno/on/ip"

#define ID_MQTT "uno"
#define BROKER_IP_MQTT "<TYPE YOUR MQTT IP ADDRESS>"
int BROKER_PORT_MQTT = 1883;


WiFiClient client;
PubSubClient MQTT(client);

float value1,value2,value3;

void setup() {
  Serial.begin(9600);
  while (!Serial) continue;

  WiFiConnect(SSID,PWD);
  MQTTConfigure();
}

void loop() {
  MQTTReconnect();
  MQTTPublish(TOPICO_PUBLISH_DEVICE_IP, GetIP());
  StaticJsonDocument<1000> doc;
  DeserializationError error = deserializeJson(doc, Serial);

  if (error) return;

  value1 = doc["A0"];
  value2 = doc["A1"];
  value3 = doc["A2"];

  if (value1 > 0)  MQTTPublish(TOPICO_PUBLISH_VALUE_1, (String)value1);
  if (value2 > 0)  MQTTPublish(TOPICO_PUBLISH_VALUE_2, (String)value2);
  if (value3 > 0)  MQTTPublish(TOPICO_PUBLISH_VALUE_3, (String)value3);
}
