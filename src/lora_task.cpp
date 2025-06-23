extern "C" {
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "FreeRTOS.h"
#include "task.h"
#include "lora1280.h"
#include <stdio.h>
}

extern void lora1280_init();
extern void lora1280_transmit_test();

void lora_task(void *pvParameters) {
    (void)pvParameters;


    lora1280_init();
    while (1) {
        lora1280_transmit_test();
        vTaskDelay(pdMS_TO_TICKS(900));
    }
}

void launch_lora_task() {
    xTaskCreate(
        lora_task,
        "LoRa1280",
        512,
        NULL,
        tskIDLE_PRIORITY + 1,
        NULL
    );
}

