#include <KAL_ESP_NOW.h>

KAL_ESP_NOW KalNow;

void setup() {
  Serial.begin(115200);
  KalNow.Setup_Esp_Now();
}

void loop() {
  KalNow.Get_MAC_Address();
  delay(1000);
}
