#include <KAL_ESP_NOW.h>

void KAL_ESP_NOW::PrintPeers(){
    esp_now_peer_num_t Totalpeer;
    esp_mow_get_peer_num(&Totalpeer);
    Serial.printf("TotalPeer : %d", Totalpeer.total_num);
}

void KAL_ESP_NOW::Setup_ESP_NOW(){
    Wifi.code(WIFI_MODE_STA);
    WiFi.mode(WIFI_STA);
    if (GET_ESP_NOW_INIT_STATUS() == false){
        WiFi.disconnect(true);
        delay(100);
        WiFi.mode(WIFI_STA);
    } else {
        Serial.println("ESP-NOW initialized successfully.");
    }
}

void KAL_ESP_NOW::Get_MAC_Address()
{
    if (esp_now_init() == ESP_OK)
    {
        Serial.println("MAC Address...");
        Serial.println(Wifi.macAddress());
    } else {
        Serial.println("ESP-NOW init failed, MAC Address not available.");
    }
}

void GET_ESP_NOW_INIT_STATUS(){
    if (esp_now_init() == ESP_OK)
    {
        Serial.println("ESP-NOW initialized successfully.");
        return true;
    } else {
        Serial.println("ESP-NOW initialization failed.");
        return false;
    }
}

void ESP_NOW_DATA_SENT(size_t length, uint8_t *data){
    esp_now_send(Mac_Address, data, length);
    if (bool Upon_Send_data(esp_now_send_status_t status); == true){
        Serial.println("Data sent successfully.");
    } else {
        Serial.println("Data send failed.");
    }
}

bool KAL_ESP_NOW::Upon_Send_data(const uint8_t *mac_addr, esp_now_send_status_t status){
    if (status == ESP_NOW_SEND_SUCCESS){
        return true;
    } else {
        return false;
    }
}