# RP2040 FreeRTOS LoRa1280 Demo

This project demonstrates a basic SPI-based register communication with the NiceRF LoRa1280F27-TCXO module using a Raspberry Pi Pico (RP2040) and FreeRTOS.

## 🗂 Directory Structure

```
.
├── CMakeLists.txt            # Project configuration and build setup
├── LICENSE                   # Optional license file
├── pico_sdk_import.cmake     # Pico SDK bootstrap
├── README.md                 # This file
└── src/
    ├── main.c                # Entry point, starts FreeRTOS
    ├── lora_task.c           # FreeRTOS task for LoRa1280 test
    ├── lora1280.c            # Low-level register access code
    └── lora1280.h            # Interface header for LoRa1280
```

## 🔧 Hardware Setup

| Module Pin | Pico Pin | Notes         |
|------------|----------|---------------|
| MISO       | GP4      | SPI0 RX       |
| MOSI       | GP3      | SPI0 TX       |
| SCK        | GP2      | SPI0 SCK      |
| NSS        | GP5      | CS GPIO       |
| VCC        | 3.3V     | 3.3V only!     |
| GND        | GND      | Ground        |

## 🛠 Build Instructions

1. Clone this repo
2. Initialize Pico SDK and FreeRTOS support
3. Build with `cmake` + `make` or `ninja`

```
mkdir build && cd build
cmake ..
make
```

## ▶️ Run

Once flashed, the RP2040:
- Initializes SPI
- Launches a FreeRTOS task
- Communicates with the LoRa1280
- Prints SX1280 version over USB serial
- Blinks onboard LED as a heartbeat

## ✅ Next Steps

- Add transmit example
- Decode packets on a ground SDR
- Compare LoRa vs FLRC vs (G)FSK modes

