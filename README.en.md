# arduinoUno_ATmega328P_ESP8266_AnalogicRead

*Read this in other languages: [Português](README.md), [English](README.en.md),

![image](https://user-images.githubusercontent.com/794140/141704531-d30f2368-764e-4000-9b72-83ba1a1f7cce.png)


## Project

This project reads analogic values of A0, A1, A2 and publish it in an MQTT topic. Arduino uno is responsible for reading port's value, serialize them in json and write on serial. So then ESP8622 read from Serial, deserializes and publish on MQTT topic.

### Project Itens

Libs
- ArduinoJson V6 - https://arduinojson.org/
- ESP8266WiFi - https://github.com/knolleary/pubsubclient
- PubSubClient - https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi

Hardware
- Arduino Uno board ATmega328p ESP8266 - [Datasheet](https://robotdyn.com/pub/media/0G-00005215==UNO+WiFi-R3-AT328-ESP8266-CH340G/DOCS/PINOUT==0G-00005215==UNO+WiFi-R3-AT328-ESP8266-CH340G.pdf)
- Potentiometer b10k - [Datasheet](https://datasheetgo.com/potentiometer-pinout-10k/)

## How to run

selectors table

![image](https://user-images.githubusercontent.com/794140/141705563-367e69da-84a6-4c70-b313-9de74851f65c.png)


|       | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| Connect on ESP8266 (upload sketch)      | OFF | OFF | OFF | OFF | ON | ON | ON | OFF |
| Connect on ESP8266 (connect)            | OFF | OFF | OFF | OFF | ON | ON | OFF | OFF |
| Connect on ATmega328 (upload sketch)    | OFF | OFF | ON | ON | OFF | OFF | OFF | OFF |
| ATmega328+ESP8266                       | ON | ON | OFF | OFF | OFF | OFF | OFF | OFF |
| Works them all independent              | OFF | OFF | OFF | OFF | OFF | OFF | OFF | OFF |


- Setup connector as table above to connect in Arduino Uno (ATmega)
- Upload code [uno-atmega-analogic-read.ino](uno-atmega-analogic-read/uno-atmega-analogic-read.ino) in Arduino Uno
- Fill on file [uno-esp-analogic-read.ino](uno-esp-analogic-read/uno-esp-analogic-read.ino) your wifi on line 9 e 10 and MQTT address server on line 21
- Setup connector as table above to connect in ESP8266
- Upload code [uno-esp-analogic-read.ino](uno-esp-analogic-read/uno-esp-analogic-read.ino) in ESP8266
- Setup connectors to enable ATmega e ESP8622

## Links Úteis
- https://youtu.be/82oDbLTiFoI
- https://www.cybertice.com/article/390/%E0%B8%AA%E0%B8%AD%E0%B8%99%E0%B9%83%E0%B8%8A%E0%B9%89%E0%B8%87%E0%B8%B2%E0%B8%99-arduino-unowifi-r3-atmega328pesp8266-web-server-wifi
