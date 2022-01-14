#include "com_FPGA_spi.h"


uint8_t txData [2] = {0b00000000, 0b00000000};



void test_spi(){

	fct_vierge();
	moteur2();
	cmd_marche();

	HAL_SPI_Init( &hspi1 );
	HAL_SPI_Transmit (&hspi1, txData, 2, 100);
	while( hspi1.State == HAL_SPI_STATE_BUSY );
	HAL_SPI_DeInit( &hspi1 );
	HAL_Delay(10);



	fct_vierge();
	moteur2();
	vit_rap_cyc(64);

	HAL_SPI_Init( &hspi1 );
	HAL_SPI_Transmit (&hspi1, txData, 2, 100);
	while( hspi1.State == HAL_SPI_STATE_BUSY );
	HAL_SPI_DeInit( &hspi1 );
	HAL_Delay(10);


	fct_vierge();
	moteur2();
	vit_rap_cyc(127);

	HAL_SPI_Init( &hspi1 );
	HAL_SPI_Transmit (&hspi1, txData, 2, 100);
	while( hspi1.State == HAL_SPI_STATE_BUSY );
	HAL_SPI_DeInit( &hspi1 );
	HAL_Delay(10);

	fct_vierge();
	moteur2();
	vit_rap_cyc(13);

	HAL_SPI_Init( &hspi1 );
	HAL_SPI_Transmit (&hspi1, txData, 2, 100);
	while( hspi1.State == HAL_SPI_STATE_BUSY );
	HAL_SPI_DeInit( &hspi1 );
	HAL_Delay(10);


	return;
}

void test_spi_inverse(){
	uint8_t txData_i [2] = {0b01000000, 0b10000010};
	HAL_SPI_Transmit (&hspi1,txData_i,2,100);


}


void spi_transmit(){
	HAL_SPI_Transmit (&hspi1,txData,2,100);
	return;
}




/// CONGIG COMMANDE

void moteur1(){
	txData[0] &=  0b11110111;
}

void moteur2(){
	txData[0] |=  0b00001000;
}


/*
 * Commandes marche / arret
 */
void cmd_marche_arret(){

	txData[0] &=  0b11111010;
	txData[0] |=  0b00000010;
}

void cmd_marche(){

	txData[0] &=  0b11111001;
	txData[0] |=  0b00000001;

	txData[1] =   0b00000010;
}

void cmd_arret(){

	txData[0] &=  0b11111001;
	txData[0] |=  0b00000001;
	txData[1] =   0b00000000;
}

/*
 * Commande sens de rotation
 */
void sens_rotation(){
	txData[0] &=  0b11111010;
	txData[0] |=  0b00000010;
}

void sens_rotation_avant(){
	sens_rotation();
	txData[1] =  0b00000000;

}

void sens_rotation_arriere(){
	sens_rotation();
	txData[1] =  0b00000010;
}

/*
 * Configuration de la PWM
 */
void config_freq_PWM(){
	txData[0] &=  0b11111100;
	txData[0] |=  0b00000100;
}

void config_freq_PWM_p1(){
	txData[0] &=  0b11111100;
	txData[0] |=  0b00000100;
	txData[1] =  0b00000010;
}

void config_freq_PWM_p16(){
	txData[0] &=  0b11111100;
	txData[0] |=  0b00000100;
	txData[1] =  0b00010000;
}

/*
 * rapport cyclique
 * attention c'est sur 7 bits
 */
void vit_rap_cyc(uint8_t vitesse){
	txData[0] &=  0b11111111;
	txData[0] |=  0b00000111;
	txData[1] =  vitesse << 1;
}



void fct_vierge(){
	txData[0] =  0b00000000;
	txData[1] =  0b00000000;
}


void spi_transmission(){
	HAL_SPI_Init( &hspi1 );
	HAL_SPI_Transmit (&hspi1, txData, 2, 100);
	while( hspi1.State == HAL_SPI_STATE_BUSY );
	HAL_SPI_DeInit( &hspi1 );
	//HAL_Delay(10);
	return;
}



/// CONFIG VALUE



