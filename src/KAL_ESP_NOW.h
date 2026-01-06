#ifndef KAL_ESP_NOW_H
#define KAL_ESP_NOW_H

#define RE_HEADER_VERSION "1.0.0"
#define RE_HEADER_DATE "6/1/2026"

#ifdef ARDUINO
#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#endif

#include <stdint.h>
#include <cstdio>

typedef enum
{
    PEER_ADDRESS_ADDED,
    PEER_ADDRESS_EXISTS,
    PEER_ADDRESS_ADDING_FAILED
} PEER_ADDING_STATUS;

typedef enum
{
    KAL_ESP_NOW_SETUP_SUCCESS,
    KAL_ESP_NOW_ERR_INIT_FAILED,
    KAL_ESP_NOW_ERR_NO_RAM,
    KAL_ESP_NOW_ERR_ARG,

} KAL_ESP_NOW_SETUP_STATUS;

KAL_ESP_NOW_SETUP_STATUS REPORT_ESP_NOW_SETUP_STATUS(esp_err_t SETUP_STATUS);
PEER_ADDING_STATUS REPORT_ADDING_STATUS(esp_err_t ADDING_STATUS);

class KAL_ESP_NOW_RE
{
public:
    KAL_ESP_NOW_RE *Next_Peer_Order;
    KAL_ESP_NOW_RE *Previous_Peer_Order;
    uint8_t Peer_Number;
    uint8_t Peer_Mac_Address[6];

    uint8_t ADD_PEER_ADDR(uint8_t *PEER_ADDR[6]);
    uint8_t REMOVE_PEER_ADDR(uint8_t PEER_ADDR[6]);
    void CLEAR_ALL_PEER_ADDRS();
    void SHOW_ALL_PEER_ADDRS();
};

#endif