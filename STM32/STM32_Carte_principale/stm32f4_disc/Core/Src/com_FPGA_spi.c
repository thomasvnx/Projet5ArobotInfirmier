#include "com_FPGA_spi.h"


uint8_t txData [2] = {0b10111010, 0b10101010};

void test_spi(){
	//moteur1();



	spi_transmit();
	return;
}



void spi_transmit(){
	HAL_SPI_Transmit (&hspi1,txData,2,100);
	return;
}




/// CONGIG COMMANDE

void moteur1(){
	txData[1] &=  0b01111111;
}

void moteur2(){
	txData[1] |= 0b10000000;
}

void cmd_marche_arret(){

	txData[1] &=  0b11111001;
	txData[1] |=  0b00000001;
}

void sens_rotation(){
	txData[1] &=  0b11111010;
	txData[1] |=  0b00000010;
}

void config_freq_PWM(){
	txData[1] &=  0b11111100;
	txData[1] |=  0b00000100;
}

void vit_rap_cyc(){
	txData[1] &=  0b11111111;
	txData[1] |=  0b00000111;
}



void fct_vierge(){
	txData[1] &=  0b11111111;
	txData[1] |=  0b00000000;
}


/// CONFIG VALUE


