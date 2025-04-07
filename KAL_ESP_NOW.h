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

    void Get_MAC_Address();
    void Setup_ESP_NOW();
    bool GET_ESP_NOW_INIT_STATUS();
    void ESP_NOW_DATA_SENT(size_t length, uint8_t *data);
    void ESP_NOW_DATA_RECEIVED(const uint8_t *mac_addr, const uint8_t *data, size_t length);
};

#endif