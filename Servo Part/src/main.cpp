#include "main.h"

Servo myServo;

void setup() {
  Serial.begin(115200);
  PS4.begin("A8:E2:91:4F:12:FC");
  Serial.println("Waiting for PS4 controller...");
  myServo.attach(18);
}

void loop() {
  if (PS4.isConnected()) {

    if (abs(PS4.LStickX()) >= 10){
      Serial.print("LX:"); Serial.print(PS4.LStickX()); Serial.print(" ");
      myServo.write(90+40*PS4.LStickX()/128);
    }

    else{
      Serial.print("LX:0 ");
      myServo.write(90);
    }
    
    delay(20);
  }
}
