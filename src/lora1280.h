
#ifndef LORA1280_H
#define LORA1280_H


#ifdef __cplusplus
extern "C" {
#endif

#include "hardware/spi.h"
#include "pico/stdlib.h"

extern int8_t power_table[32];
extern uint8_t lora_sf_table[8];
extern uint8_t bw_table[4];
extern uint8_t cr_table[7];

uint8_t lora1280_read_register(uint8_t addr);
uint8_t lora1280_get_status(uint8_t addr);
void print_sx1280_status(uint8_t status);
void lora1280_test_standby_mode(void);
void lora1280_soft_reset(void);
void lora1280_set_regulator_mode(void);
void lora1280_set_packet_type(uint8_t type);
void lora1280_set_modulation_params(void);
void lora1280_set_packet_params(uint8_t payload_len);
void lora1280_set_buffer_base_address(void);
void lora1280_set_dio_irq_params(void);
void lora1280_clear_irq_status(void);
bool lora1280_wait_for_tx_done(uint32_t timeout_ms);
void lora1280_test_cw(void);

#ifdef __cplusplus
}
#endif
#endif // LORA1280_H
