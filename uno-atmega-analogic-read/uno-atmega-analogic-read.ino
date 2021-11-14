#include <ArduinoJson.h>

int value = 1;

void setup()
{
    Serial.begin(9600);
    Serial.println("started");
}

StaticJsonDocument<1000> doc;

void loop()
{

    doc["A0"] = analogRead(A0);
    doc["A1"] = analogRead(A1);
    doc["A2"] = analogRead(A2);;


    if (Serial.available() > 0) {
        serializeJson(doc, Serial);
    } else {
        Serial.println("unavailable");
    }
    value = value + 1;
    delay(1000);
}
