#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char *ssid = "Wokwi-GUEST";
const char *password = "";
const char *mqtt_server = "broker.hivemq.com";
const char *topic = "mesin/tetas";


WiFiClient espClient;
PubSubClient client(espClient);

void connect_WiFi()
{
  WiFi.begin(ssid, password) ;
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WIfi berhasil terhubung");
}

void connect_mqtt()
{
  while (!client.connected())
  {
    Serial.print("menghubungkan ke mqtt server");
    if (client.connect("ESP32_MesinTetas"))
    {
      Serial.println("berhasil terhubung");
    }
    else
    {
      Serial.print("Gagal, rc= ");
      Serial.print(client.state());
      Serial.println("coba lagi beberapa detik");
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  connect_WiFi();
  client.setServer(mqtt_server, 1883);
}

void loop () {
  if (!client.connected()) {
    connect_mqtt();
  }
  client.loop();;
  int suhu = 20 ;
  String data = "ini adalah suhu mesin tetas : " + String(suhu);
  client.publish(topic, data.c_str());
  Serial.print("test: ");
  Serial.println(" data berhasil terkirim");
 delay(1000);
}