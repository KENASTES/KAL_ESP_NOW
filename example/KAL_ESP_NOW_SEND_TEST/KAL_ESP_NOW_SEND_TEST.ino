#include <KAL_ESP_NOW.h>

uint8_t Address[6] ={ 0xF4, 0x65, 0x0B, 0x56, 0x9C, 0x8C};
KAL_ESP_NOW KalNow(Address);

int num = 1;

void setup() {
  Serial.begin(115200);
  KalNow.Setup_Esp_Now();
}

void loop() {
  KalNow.Esp_Now_Data_Sent(1,&num);
  delay(100);
}
