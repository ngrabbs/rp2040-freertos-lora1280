extern "C" {
    #include <stdio.h>
    #include "pico/stdlib.h"
    #include "FreeRTOS.h"
    #include "task.h"
}

extern void launch_lora_task();

int main() {
    stdio_init_all();

    launch_lora_task();
    vTaskStartScheduler();
    while (1) {
        // Should never reach here
    }
    return 0;
}

