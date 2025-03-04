#ifndef NRF24_JAM_H
#define NRF24_JAM_H

#include <stdint.h>

// Inizia il jammer sulla rete selezionata
void nrf24_start_jam(const char* network);

// Ferma il jammer
void nrf24_stop_jam(void);

#endif // NRF24_JAM_H