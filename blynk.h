

#include <BlynkSimpleEsp8266.h>

void blynk_init() {
  Serial.println("Starting blynk");
  Blynk.config(token);
  Blynk.connect(5000);
  
  if(Blynk.connected()) {
    Serial.println("Blynk connected");
  } else {
    Serial.println("Blynk can't be connected");
  }
}


static inline void blynk_run() {
  if(Blynk.connected()) {
    Blynk.run();
  }else{
    Serial.println("Offline");
    delay(100);
  }
}
