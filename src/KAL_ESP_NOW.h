#ifndef KAL_ESP_NOW_H
#define KAL_ESP_NOW_H

#define HEADER_VERSION 1.0.0
#define HEADER_DATE "05/4/2025"

#ifdef ARDUINO
#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#endif

#include <stdint.h>
#include <cstdio>

enum Esp_Now_Status {
    
};

class KAL_ESP_NOW {
    public:

    uint8_t Address[6];
    KAL_ESP_NOW(){   
    
    }

    KAL_ESP_NOW(const uint8_t *address){
        for (int i = 0; i < 6; i++){
            Address[i] = address[i];
        }
    }

    ~KAL_ESP_NOW(){
        for (int i = 0; i < 6; i++){
            Address[i] = 0;
        }
    }

    void PrintPeers();
    void Setup_Esp_Now();
    void Get_MAC_Address();
    bool Get_Esp_Now_Init_Status();
    bool Add_Peer(const uint8_t* Mac_Address);
    bool Remove_Peer(const uint8_t* Mac_Address);
    void Esp_Now_Data_Sent(size_t length, uint8_t *data);
    bool Upon_Send_data(const uint8_t *mac_addr, esp_now_send_status_t status);
    static void Esp_Now_Data_Receieve(const uint8_t * Mac_Address, const uint8_t *Received_Data, size_t length);
};

#endif