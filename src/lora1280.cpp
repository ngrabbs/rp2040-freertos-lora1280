#include "lora1280.h"
#include "SX1280.h"
#include <stdio.h>
#include "hardware/spi.h"

#define RF_FREQUENCY                                2410000000 // Hz

#define PIN_NSS  5
#define PIN_RESET 22
#define PIN_BUSY 26
#define PIN_DIO1 27
#define PIN_SCK 2
#define PIN_MOSI 3
#define PIN_MISO 4

SX1280 LoRa1280(PIN_NSS, PIN_RESET, PIN_BUSY, PIN_DIO1, PIN_SCK, PIN_MOSI, PIN_MISO);	//define a object of class SX1280.
loRa_Para_t	lora_para;	//define a struct to hold lora parameters.


int8_t power_table[32]={-18,-17,-16,-15,-14,-13,-12,-11,-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13};
uint8_t lora_sf_table[8]={LORA_SF5,LORA_SF6,LORA_SF7,LORA_SF8,LORA_SF9,LORA_SF10,LORA_SF11,LORA_SF12};
uint8_t bw_table[4]={LORA_BW_0200,LORA_BW_0400,LORA_BW_0800,LORA_BW_1600};
uint8_t cr_table[7]={LORA_CR_4_5,LORA_CR_4_6,LORA_CR_4_7,LORA_CR_4_8,LORA_CR_LI_4_5,LORA_CR_LI_4_6,LORA_CR_LI_4_7};


uint8_t tx_buf[]={"Cubesat@MSU  Testing Testing Testing Testing  Testing Testing Testing Testing  Testing Testing Testing Testing  Testing Testing Testing Testing  Testing Testing Testing Testing Testing Testing Testing Testing "};
uint16_t tx_cnt = 0;

uint8_t rx_buf[20]={};
uint16_t rx_cnt = 0;
uint16_t rx_size = 0;

uint8_t val;
uint8_t state;


void lora1280_init(void) 
{
	bool temp;
	stdio_init_all();

	lora_para.rf_freq    = RF_FREQUENCY;
	lora_para.tx_power   = 2;			//-18~13
	lora_para.lora_sf    = LORA_SF12;
	lora_para.band_width = LORA_BW_1600;
	lora_para.code_rate  = LORA_CR_4_5;
	lora_para.payload_size = sizeof(tx_buf);

	temp = LoRa1280.Init(&lora_para);
	
	if(0 == temp)
	{
		printf("Init fail!");
	}
	printf("SX1280 demo master!");
}

void lora1280_transmit_test(void)
{

	LoRa1280.TxPacket(tx_buf,sizeof(tx_buf));
	state = LoRa1280.WaitForIRQ_TxDone();
	if(state)
	{
		tx_cnt++;
		printf("tx_cnt = %d\n", tx_cnt);
	}
    sleep_ms(1000);
	
}
