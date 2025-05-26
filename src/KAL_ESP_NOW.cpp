#include <KAL_ESP_NOW.h>

void *KAL_ESP_NOW::Tranfering_Struct = nullptr;
size_t KAL_ESP_NOW::Tranfering_StructSize = 0;

void KAL_ESP_NOW::Print_Peers_List()
{
    for (int i = 0; i < Memorized_Peers.size(); ++i) {
        const auto& ESP_NOW_MAC_ADDR = Memorized_Peers[i];
        Serial.printf("[%d] %02X:%02X:%02X:%02X:%02X:%02X\n", i,
                      ESP_NOW_MAC_ADDR[0], ESP_NOW_MAC_ADDR[1], ESP_NOW_MAC_ADDR[2], ESP_NOW_MAC_ADDR[3], ESP_NOW_MAC_ADDR[4], ESP_NOW_MAC_ADDR[5]);
    }
}

void KAL_ESP_NOW::Setup_Esp_Now()
{
    WiFi.mode(WIFI_MODE_STA);
    WiFi.mode(WIFI_STA);
    esp_err_t result = esp_now_init();
    EspNow_Initialized = (result == ESP_OK);
    if (EspNow_Initialized == false)
    {
        WiFi.disconnect(true);
        delay(100);
        WiFi.mode(WIFI_STA);
    }
    else
    {
        Serial.println("ESP-NOW initialized successfully.");
    }
}

void KAL_ESP_NOW::Get_MAC_Address()
{
    if (esp_now_init() == ESP_OK)
    {
        Serial.print("MAC Address : ");
        Serial.println(WiFi.macAddress());
    }
    else
    {
        Serial.println("ESP-NOW init failed, MAC Address not available.");
    }
}

bool KAL_ESP_NOW::Get_Esp_Now_Init_Status()
{
    return EspNow_Initialized;
}

void KAL_ESP_NOW::Add_Peer(const uint8_t *Mac_Address)
{
    std::array<uint8_t, 6> Adding_Address;
    memcpy(Adding_Address.data(), Mac_Address, 6);

    if (Is_Peer_Exists(Mac_Address))
    {
        Serial.println("This peer is already exists.");
        return;
    }

    esp_now_peer_info_t Peer_Info = {};
    memcpy(Peer_Info.peer_addr, Mac_Address, 6);
    Peer_Info.channel = 0;
    Peer_Info.encrypt = false;
    Peer_Info.ifidx = WIFI_IF_STA;

    esp_err_t result = esp_now_add_peer(&Peer_Info);
    if (result == ESP_OK)
    {
        Serial.println("Peer added successfully.");
    }
    else if (result == ESP_ERR_ESPNOW_NOT_INIT)
    {
        Serial.println("ESP-NOW not initialized.");
    }
    else if (result == ESP_ERR_ESPNOW_ARG)
    {
        Serial.println("Invalid argument.");
    }
    else if (result == ESP_ERR_ESPNOW_FULL)
    {
        Serial.println("Peer list full.");
    }
    else if (result == ESP_ERR_ESPNOW_NO_MEM)
    {
        Serial.println("Out of memory.");
    }
    else if (result == ESP_ERR_ESPNOW_EXIST)
    {
        Serial.println("Peer already exists.");
    }
    else
    {
        Serial.println("Failed to add peer.");
    }
}

bool KAL_ESP_NOW::Select_Peer(const uint8_t index)
{
    if (index >= 0 && index < Memorized_Peers.size()) {
        Selected_Peer_Index = index;
        return true;
    }
    return false;
}

void KAL_ESP_NOW::Esp_Now_Data_Sent(size_t length, const void *data)
{
    esp_err_t result = esp_now_send(Address, (const uint8_t *)data, length);
    if (result == ESP_OK)
    {
        Serial.println("Data sent successfully.");
    }
    else
    {
        Serial.printf("Data send failed. Error code: %d\n", result);
    }
}

void KAL_ESP_NOW::Esp_Now_Data_Receieve(const uint8_t *Mac_Address, const uint8_t *Received_Data, int length)
{
    if (Tranfering_Struct && Tranfering_StructSize > 0 && length >= Tranfering_StructSize) {
    memcpy(Tranfering_Struct, Received_Data, Tranfering_StructSize);
  }
}

void KAL_ESP_NOW::Register_Receive_Callback()
{
    esp_now_register_recv_cb(Esp_Now_Data_Receieve);
}

void KAL_ESP_NOW::Esp_Now_Struct_Tranfer(void *Tranfer_target, size_t Tranfer_targetsize){
    KAL_ESP_NOW::Tranfering_Struct = Tranfer_target;
    KAL_ESP_NOW::Tranfering_StructSize = Tranfer_targetsize;
}