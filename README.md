# RP2040 FreeRTOS LoRa1280 Demo

This project demonstrates SPI-based communication with the [NiceRF LoRa1280F27-TCXO](https://www.nicerf.com/products/detail/lora1280f27.html) module using a Raspberry Pi Pico (RP2040) and FreeRTOS.

It includes:
- Precise SPI setup using Pico SDK
- SX1280 LoRa configuration (modulation, packet format, TX)
- FreeRTOS task to manage radio logic
- USB serial output for debugging
- Flexible pin assignment and hardware bring-up logic
- Ported C++ Arduino driver (with MOSI/SCK/MISO/NSS handling)

---

## ⚡️ Quick Start

### ✅ Clone with Submodules

This project uses FreeRTOS as a Git submodule:

```bash
git clone --recurse-submodules https://github.com/YOUR_USERNAME/rp2040-freertos-lora1280.git
cd rp2040-freertos-lora1280
```

> Already cloned without `--recurse-submodules`?
```bash
git submodule update --init --recursive
```

---

## 📂 Directory Structure

```
.
├── CMakeLists.txt             # Build configuration
├── lib/                       # FreeRTOS submodule
│   └── FreeRTOS-Kernel/       # Git-submodule linked
├── pico_sdk_import.cmake      # Pico SDK bootstrap
├── src/
│   ├── main.cpp               # Main entry point
│   ├── lora_task.cpp          # FreeRTOS task loop
│   ├── lora1280.cpp/h         # RP2040 driver wrapper
│   ├── SX1280.cpp/h           # Original Arduino-style driver
│   └── spi_test.cpp/h         # Raw SPI test logic
└── README.md
```

---

## 🔧 Hardware Setup

| SX1280 Pin | RP2040 (Pico) Pin | Function      |
|------------|-------------------|---------------|
| SCK        | GP2               | SPI0 SCK      |
| MOSI       | GP3               | SPI0 TX       |
| MISO       | GP4               | SPI0 RX       |
| NSS        | GP5               | Chip Select   |
| RESET      | GP22              | Reset Line    |
| BUSY       | GP26              | SPI Ready     |
| DIO1       | GP27              | IRQ Input     |
| VCC        | 3.3V              | ⚠️ 3.3V only! |
| GND        | GND               | Ground        |

---

## 🛠️ Build Instructions

```bash
mkdir build && cd build
cmake ..
make -j
```

> You must have the Pico SDK installed and `PICO_SDK_PATH` set, or adjust `pico_sdk_import.cmake` accordingly.

---

## ▶️ Run

Once flashed:

- SPI is initialized to talk to the SX1280
- TCXO and power pins are enabled
- LoRa configuration (SF7, BW1600, CR4/5) is applied
- A test packet is transmitted at 2410 MHz
- USB CDC prints status and diagnostic info
- Onboard LED can blink on TX complete

---

## ✅ Features Implemented

- [x] Ported SX1280 Arduino driver to C++ on RP2040
- [x] SPI tested and debugged using logic analyzer
- [x] NSS/CS manual toggling for accurate chip control
- [x] TCXO enable pin and RF TXEN support
- [x] LoRa TX confirmed via SDR waterfall at 2410 MHz
- [x] IRQ polling for `TX_DONE`

---

## 📡 Future Enhancements

- [ ] CAN bus activation (e.g., transmit on CAN trigger)
- [ ] External SPI flash for image storage
- [ ] RX mode + packet parsing
- [ ] Support for FLRC and GFSK modulation
- [ ] Optional DIO1 interrupt handling

---

## 🚀 About

This project is part of the [CubeSat@MSU](https://www.msstate.edu/) initiative to teach and explore space-based communication, radio protocols, and embedded software design.

Authored by **Nick Grabbs**  
🗕️ July 2025

