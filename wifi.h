#include <ESP8266WiFi.h>

void wifi_init() {
  WiFi.begin(ssid, pwd);

  while( WiFi.status() != WL_CONNECTED ) {
    Serial.println(".");
    delay(100);
  }

  Serial.println("WiFi connected");
}
