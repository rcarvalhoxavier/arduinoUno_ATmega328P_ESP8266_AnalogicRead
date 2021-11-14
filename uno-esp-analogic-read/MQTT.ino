void MQTTReconnect(void)
{
    while (!MQTT.connected()) {
        if (!MQTT.connect(ID_MQTT)) {
            delay(2000);
        }
    }
}

void MQTTConfigure(void)
{
    MQTT.setServer(BROKER_IP_MQTT, BROKER_PORT_MQTT);
}


void MQTTPublish(char* topic, String text)
{
    int length = text.length() + 1;
    char charText[length];
    text.toCharArray(charText, length);
    MQTT.publish(topic, charText);
}
