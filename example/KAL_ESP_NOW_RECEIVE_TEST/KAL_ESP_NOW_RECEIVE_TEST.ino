#include <KAL_ESP_NOW.h>

KAL_ESP_NOW espnow;

void setup() {
  Serial.begin(115200);
  delay(1000);

  espnow.Setup_Esp_Now();
  espnow.Get_MAC_Address();

  Serial.println("Setting up finish Waiting for ESP-NOW data...");
}

void loop() {
  espnow.Register_Receive_Callback();
  delay(1000);
}