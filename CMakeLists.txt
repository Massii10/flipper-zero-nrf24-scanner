cmake_minimum_required(VERSION 3.13)
project(flipper_zero_nrf24_scanner)

# Aggiungi il supporto per il Flipper Zero SDK
include($ENV{FLIPPERZERO_PATH}/fbt.cmake)

# Aggiungi il target per l'applicazione
add_fbt_app(flipper_zero_nrf24_scanner flipper_zero_app.c nrf24_jam.c)

# Includi le librerie nRF24
target_include_directories(flipper_zero_nrf24_scanner PRIVATE ${CMAKE_SOURCE_DIR}/nrf24)
target_link_libraries(flipper_zero_nrf24_scanner PRIVATE nrf24)