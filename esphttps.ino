#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

/*  ESP8266 LDR ArduinoIDE https example code
 * 
 *  Based on: https://vaasa.hacklab.fi/2016/02/06/esp8266-on-nodemcu-board-ds18b20-arduinoide-thingspeak/
 *  ESP8266 Witty: http://www.schatenseite.de/en/2016/04/22/esp8266-witty-cloud-module/
 */

#include "conf.h"

void setup() {
  delay(5000);

  Serial.begin(115200);
  Serial.println("");
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if(WiFi.status() != WL_CONNECTED) {
    Serial.println("Error: not connected to WiFi");
    delay(5000);
    return;
  }

  HTTPClient http;
  http.begin(url, httpsFingerprint);
  http.addHeader("Content-Type", "application/json");

  int httpCode = http.POST("Hello");
  String payload = http.getString();

  Serial.println(http.errorToString(httpCode));
  http.end();

  delay(10000);
}