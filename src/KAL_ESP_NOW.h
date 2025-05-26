#ifndef KAL_ESP_NOW_H
#define KAL_ESP_NOW_H

#define HEADER_VERSION 1.1.0
#define HEADER_DATE "20/4/2025"

#define MAX_RECEIVE_LEN 250

#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#include <stdint.h>
#include <cstdio>
#include <vector>
#include <array>

class KAL_ESP_NOW
{
public:
    std::vector<std::array<uint8_t, 6>> Memorized_Peers;
    uint8_t Selected_Peer_Index = -1;
    bool EspNow_Initialized = false;
    static void *Tranfering_Struct;
    static size_t Tranfering_StructSize;
    esp_now_peer_info_t Peer_Info;
    uint8_t Peer_number = 0;
    uint8_t Address[6];

    KAL_ESP_NOW()
    {
    }

    KAL_ESP_NOW(const uint8_t *address)
    {
        for (int i = 0; i < 6; i++)
        {
            Address[i] = address[i];
        }
    }

    ~KAL_ESP_NOW()
    {
        for (int i = 0; i < 6; i++)
        {
            Address[i] = 0;
        }
    }

    void Setup_Esp_Now();
    void Get_MAC_Address();
    void Print_Peers_List();
    bool Get_Esp_Now_Init_Status();
    void Register_Receive_Callback();
    bool Select_Peer(const uint8_t index);
    bool Is_Peer_Exists(const uint8_t *Mac_Address);
    void Add_Peer(const uint8_t *Mac_Address);
    void Esp_Now_Data_Sent(size_t length, const void *data);
    static void Esp_Now_Struct_Tranfer(void *Tranfer_target, size_t Tranfer_targetsize);
    static void Esp_Now_Data_Receieve(const uint8_t *Mac_Address, const uint8_t *Received_Data, int length);
};

#endif