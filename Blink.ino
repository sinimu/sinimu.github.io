#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>

//const char* ssid = "Sinet";
//const char* password = "0000035007";

ESP8266WiFiMulti wifiMulti;

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(115200);

  wifiMulti.addAP("FozNet", "0000035007");
  wifiMulti.addAP("Sinet", "0000035007");
  
  connectWiFi();

  //t_httpUpdate_return ret = ESPhttpUpdate.update("http://savewater.blob.core.windows.net/sketch/blink.bin");
  
  //switch(ret) {
  //   case HTTP_UPDATE_FAILED:
  //        USE_SERIAL.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
  //   break;

  //   case HTTP_UPDATE_NO_UPDATES:
  //        USE_SERIAL.println("HTTP_UPDATE_NO_UPDATES");
  //   break;

  //   case HTTP_UPDATE_OK:
  //        USE_SERIAL.println("HTTP_UPDATE_OK");
  //   break;
 // }
}

void connectWiFi()
{
int i = 0;
  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(1000);
    wifiMulti.run();
    Serial.print(++i); Serial.print(' ');
  }
  
  Serial.println("...");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.printf(" connected to %s\n", WiFi.SSID().c_str());

}

void loop() {
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
  Serial.println("LOW");
  digitalWrite(LED_BUILTIN,HIGH);
  delay(5000);
  Serial.println("HIGH");
}
