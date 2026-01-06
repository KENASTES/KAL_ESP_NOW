#include <KAL_ESP_NOW.h>

KAL_ESP_NOW_SETUP_STATUS REPORT_ESP_NOW_SETUP_STATUS(esp_err_t SETUP_STATUS)
{
    switch (SETUP_STATUS){
        case ESP_OK:
            return KAL_ESP_NOW_SETUP_SUCCESS;
        case ESP_ERR_ESPNOW_INTERNAL:
            return KAL_ESP_NOW_ERR_INIT_FAILED;
        case ESP_ERR_ESPNOW_ARG:
            return KAL_ESP_NOW_ERR_ARG;
        case ESP_ERR_ESPNOW_NO_MEM:
            return KAL_ESP_NOW_ERR_NO_RAM;
        
    }
}

PEER_ADDING_STATUS REPORT_ADDING_STATUS(esp_err_t ADDING_STATUS)
{
    switch (ADDING_STATUS){
        case ESP_OK:
            return PEER_ADDRESS_ADDED;
        case ESP_ERR_ESPNOW_EXIST:
            return PEER_ADDRESS_EXISTS;
        case ESP_ERR_ESPNOW_NO_MEM:
            return PEER_ADDRESS_ADDING_FAILED;
        case ESP_ERR_ESPNOW_ARG:
            return PEER_ADDRESS_ADDING_FAILED;
        case ESP_ERR_ESPNOW_FULL:
            return PEER_ADDRESS_ADDING_FAILED;
    }
}

uint8_t KAL_ESP_NOW_RE::ADD_PEER_ADDR(uint8_t *PEER_ADDR[8]){
    memset()
    esp_err_t ADDING_PEER = esp_now_add_peer()
}