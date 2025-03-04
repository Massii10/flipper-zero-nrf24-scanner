#include "nrf24_jam.h"
#include <nrf24/nrf24.h>
#include <string.h>

static bool jamming = false;

// Frequenza di partenza per il jammer (in MHz)
#define JAM_START_FREQ 2400

// Numero di canali da disturbare
#define JAM_CHANNELS 16

void nrf24_start_jam(const char* network) {
    if(jamming) {
        return;
    }

    // Configura il modulo NRF24 per il jamming
    nrf24_init();
    nrf24_set_rf_channel(JAM_START_FREQ);
    nrf24_set_data_rate(NRF24_250KBPS);
    nrf24_set_tx_power(NRF24_PWR_MAX);
    
    // Inizia a inviare pacchetti di disturbo
    jamming = true;
    while(jamming) {
        for(uint8_t channel = 0; channel < JAM_CHANNELS; ++channel) {
            nrf24_set_rf_channel(JAM_START_FREQ + channel);
            uint8_t payload[32];
            memset(payload, 0xFF, sizeof(payload)); // Pacchetto di disturbo
            nrf24_send(payload, sizeof(payload));
        }
    }
}

void nrf24_stop_jam(void) {
    if(!jamming) {
        return;
    }

    // Ferma il jamming
    jamming = false;
    nrf24_power_down();
}