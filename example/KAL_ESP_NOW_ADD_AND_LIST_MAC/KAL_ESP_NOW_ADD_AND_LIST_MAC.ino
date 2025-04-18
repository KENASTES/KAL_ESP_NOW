#include <KAL_ESP_NOW.h>

KAL_ESP_NOW KalNow;

uint8_t Controller_Mac[] = { 0xF4, 0x65, 0x0B, 0x56, 0x9C, 0x8C };
uint8_t Own_Mac[] = { 0x55, 0x65, 0x0B, 0x56, 0x9C, 0x8C };

void setup() {
  Serial.begin(115200);
  KalNow.Setup_Esp_Now();
  KalNow.Register_Receive_Callback();
  KalNow.Add_Peer(Controller_Mac);
  KalNow.Add_Peer(Own_Mac);
}

void loop() {
  KalNow.PrintPeers();
  delay(1000);
}
