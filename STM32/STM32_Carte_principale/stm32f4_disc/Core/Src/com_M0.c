#include "com_M0.h"
#include "main.h"
#include "spi.h"
#include "string.h"
#include "usart.h"


uint8_t UART6_rxBuffer[10];


// UART 6 reservé pour la communication avec le M0

void setup_com_M0(){
	HAL_UART_Receive_IT(&huart6, UART6_rxBuffer, sizeof(UART6_rxBuffer));

}

void reception_M0(){

	HAL_UART_Receive_IT(&huart6, UART6_rxBuffer, sizeof(UART6_rxBuffer));


}
























