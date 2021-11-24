# arduinoUno_ATmega328P_ESP8266_AnalogicRead

*Read this in other languages: [Português](README.md), [English](README.en.md),

![image](https://user-images.githubusercontent.com/794140/141704531-d30f2368-764e-4000-9b72-83ba1a1f7cce.png)


## Projeto

Este projeto lê os valores analógicos das portas A0, A1 e A2 e posta em um tópico MQTT. O Arduino Uno fica responsável por realizar a leitura das portas e serializadas em json, para então escrever no Serial. Logo o ESP8622 recebe o json da Serial, desserializa os valores e posta no MQTT.

### Itens do Projeto

Bibliotecas
- ArduinoJson V6 - https://arduinojson.org/
- ESP8266WiFi - https://github.com/knolleary/pubsubclient
- PubSubClient - https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WiFi

Hardware
- Placa Arduino Uno ATmega328p ESP8266 - [Datasheet](https://robotdyn.com/pub/media/0G-00005215==UNO+WiFi-R3-AT328-ESP8266-CH340G/DOCS/PINOUT==0G-00005215==UNO+WiFi-R3-AT328-ESP8266-CH340G.pdf)
- Potenciometro b10k - [Datasheet](https://datasheetgo.com/potentiometer-pinout-10k/)

## Como rodar o projeto

Tabela dos seletores

![image](https://user-images.githubusercontent.com/794140/141705563-367e69da-84a6-4c70-b313-9de74851f65c.png)


|       | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
| Conectar no ESP8266 (upload sketch)      | OFF | OFF | OFF | OFF | ON | ON | ON | OFF |
| Conectar no ESP8266 (connect)            | OFF | OFF | OFF | OFF | ON | ON | OFF | OFF |
| Conectar no ATmega328 (upload sketch)    | OFF | OFF | ON | ON | OFF | OFF | OFF | OFF |
| ATmega328+ESP8266                        | ON | ON | OFF | OFF | OFF | OFF | OFF | OFF |
| Funcionamento independentes de todos     | OFF | OFF | OFF | OFF | OFF | OFF | OFF | OFF |


- Ajustar os conectores conforme tabela acima, para se conectar no Arduino Uno (ATmega)
- Realizar o upload do código [uno-atmega-analogic-read.ino](uno-atmega-analogic-read/uno-atmega-analogic-read.ino) no Arduino Uno
- Ajustar no arquivo [uno-esp-analogic-read.ino](uno-esp-analogic-read/uno-esp-analogic-read.ino) o seu wifi na linha 9 e 10 e o endereço do MQTT server na linha 21
- Ajustar os conectores conforme tabela acima, para se conectar no ESP8266
- Realizar upload do código [uno-esp-analogic-read.ino](uno-esp-analogic-read/uno-esp-analogic-read.ino) no ESP8266
- Ajustar os conectores para habilitar o módulo ATmega e ESP8622

## Links Úteis
- https://youtu.be/82oDbLTiFoI
- https://www.cybertice.com/article/390/%E0%B8%AA%E0%B8%AD%E0%B8%99%E0%B9%83%E0%B8%8A%E0%B9%89%E0%B8%87%E0%B8%B2%E0%B8%99-arduino-unowifi-r3-atmega328pesp8266-web-server-wifi
