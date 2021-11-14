void WiFiConnect(String ssid, String password)
{
  client.stop();
  delay(5000);
  WiFi.begin(ssid, password);
  WiFi.mode(WIFI_STA);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());

  delay(1000);
}

String GetIP()
{
  IPAddress ipAddress = WiFi.localIP();
  return String(ipAddress[0]) + String(".") +  String(ipAddress[1]) + String(".") +  String(ipAddress[2]) + String(".") +  String(ipAddress[3]);
}