#include <Arduino.h>

void setup () {
  Serial.begin(115200);
  Serial.println("ESP 32 Start");
  delay(1000);
}
void loop () {
  Serial.println("Status: ");
  Serial.print("ESP32 active");
  delay(1000);
}
