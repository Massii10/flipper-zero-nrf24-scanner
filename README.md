# Flipper Zero NRF24 Scanner and Jammer

## Descrizione

Questo progetto è un'applicazione personalizzata (FAP) per il Flipper Zero che utilizza un modulo NRF24 per scannerizzare le reti WiFi a 2.4 GHz e avviare un jammer sulla rete selezionata. L'applicazione presenta un menu con due voci principali:

1. **Scansione delle reti WiFi 2.4 GHz**: Utilizzando il tasto centrale del Flipper Zero, è possibile avviare o fermare la scansione delle reti WiFi.
2. **Jammer sulla rete selezionata**: Dopo aver selezionato una rete, è possibile utilizzare il tasto destro per avviare o fermare il jammer sulla rete selezionata.

## Funzionalità

- **Scansione delle reti WiFi**: Scansiona le reti WiFi a 2.4 GHz e visualizza le reti trovate.
- **Selezione della rete**: Permette di selezionare una rete dalla lista delle reti scansionate.
- **Jammer**: Inizia e ferma il jammer sulla rete selezionata.

## Requisiti

- Flipper Zero
- Modulo NRF24

## Installazione

1. Clona questo repository sul tuo computer:
    ```sh
    git clone https://github.com/tuo-username/flipper-zero-nrf24-scanner.git
    ```
2. Naviga nella directory del repository:
    ```sh
    cd flipper-zero-nrf24-scanner
    ```
3. Compila e carica l'applicazione sul Flipper Zero utilizzando l'ambiente di sviluppo appropriato.

### Configurazione dell'Ambiente di Sviluppo

1. **Installare le Dipendenze**:
   - Su **Ubuntu/Debian**:
     ```sh
     sudo apt update
     sudo apt install build-essential cmake gcc-arm-none-eabi git
     ```
   - Su **macOS** (con Homebrew):
     ```sh
     brew install cmake make gcc-arm-none-eabi
     ```
   - Su **Windows** (con WSL):
     - Installa WSL e una distribuzione Linux (es. Ubuntu).
     - Apri il terminale WSL e installa le dipendenze:
       ```sh
       sudo apt update
       sudo apt install build-essential cmake gcc-arm-none-eabi git
       ```

### Creare una Directory di Build

Crea una directory di build dove verranno salvati i file compilati:

```sh
mkdir build
cd build
```

### Configurare il Progetto con CMake

Configura il progetto utilizzando `cmake`:

```sh
cmake ..
```

Questa operazione genererà i file necessari per la compilazione.

### Compilare il Progetto

Compila il progetto utilizzando `make`:

```sh
make
```

### Flashare l'Applicazione sul Flipper Zero

Una volta compilato, puoi flashare l'applicazione sul tuo Flipper Zero. Assicurati che il tuo Flipper Zero sia collegato al computer tramite USB. Puoi utilizzare `qFlipper`, un software grafico per Windows, per caricare il firmware sul tuo Flipper Zero.

1. **Scarica e installa qFlipper**:
   - Scarica qFlipper da [qui](https://flipperzero.one/update).
   - Installa e apri qFlipper.

2. **Carica il Firmware**:
   - Usa qFlipper per caricare il file `.fap` generato dalla compilazione sul Flipper Zero.

## Contribuire

Se desideri contribuire a questo progetto, sentiti libero di fare fork del repository e inviare una pull request con le tue modifiche.

## Licenza

Questo progetto è distribuito sotto la licenza MIT. Vedi il file [LICENSE](LICENSE) per maggiori dettagli.