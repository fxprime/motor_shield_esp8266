#include "config.h"
#include "wifi.h"
#include "blynk.h"
#include "motor.h"



BLYNK_WRITE(V0) {
  control[0] = param[0].asInt();
  control[1] = param[1].asInt();

  Serial.print(control[0]);
  Serial.print(",");
  Serial.println(control[1]);
}

void setup() {
  
  Serial.begin(115200);

  wifi_init();

  blynk_init();
  
  motor_init();
  
  Serial.println("Start program by arduinona.com");

}



void loop() {
  blynk_run();



  float yf = mapf(control[1], 0, 1023, -1.0, 1.0); 
  float xf = mapf(control[0], 0, 1023, -0.3, 0.3);  //ความเร็วเลี้ยวกำหนดตรงนี้ เริ่มต้นที่ 0.3 เร็วกว่านี้จะคุมไม่ทันเอานา


  float norm = sqrtf(xf*xf + yf*yf);
  if(norm<1.0) norm = 1.0;
  float dir[2] = { xf/norm, yf/norm };
  

  float left = dir[1] + dir[0];
  float right = dir[1] - dir[0];


  float force = sqrtf( left*left + right*right );
  if(force<1.0) force = 1.0;
  float wheel[2] = { left/force, right/force };

  motor_cmd(left,right);
}
