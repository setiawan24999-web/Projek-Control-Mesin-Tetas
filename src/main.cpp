#include <Arduino.h>
#include <WiFi.h> 

// identitas WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

void setup()
{
  Serial.begin(115200);
  // mulai proses koneksi
  WiFi.begin(ssid, password);
  Serial.print("Menghubungkan WIFi");
  
  // ulangi selama belum terhubung 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi terhubung");
  Serial.print("Alamat IP: ");
  Serial.println(WiFi.localIP());

}
void loop()
{
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Gagal terkoneksi");
    WiFi.reconnect();
  }
  delay(1000);
}