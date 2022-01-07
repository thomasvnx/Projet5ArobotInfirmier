#include "com_pc.h"
#include "usart.h"
#include "main.h"
#include <String.h>
#include "moteur.h"



// variable globale
char message_recu_PC [100];

int pwm = 0;

//MOTOR_STATE_SPEED motor_state_speed;





/*
 * Envoyer un message depuis le PC
 */
int envoyer_message_pc (){

	uint8_t constantes[4] = {1, 5, 9, 4};

	HAL_UART_Transmit(&huart2, constantes, sizeof(constantes), 100);

	return 1;
}

/*
 * Cette fonction est activelorsqu'on recoit un message du PC.
 * Elle permet de traiter l'information.
 */
void recevoir_message_pc(){
/*
	strcpy(UART2_rxBuffer,message_recu_PC);

	if (strcmp(&message_recu_PC,"test")){
		envoyer_message_pc("test recu");
		return;
	}

	else if (strcmp(&message_recu_PC,"A")){
		envoyer_message_pc("test recu");
		return;
	}
	*/
}


void recevoir_message_pc2(){

	if (UART2_rxBuffer_2[pc_message_recu_index] == '\r'){ // on est a la fin du message
		strcpy((char *)message_recu_PC,(char *)UART2_rxBuffer_2);
		pc_message_recu_index = 0;
		traiter_message_pc();

		HAL_UART_Abort(&huart2);
		HAL_UART_Receive_IT(&huart2, UART2_rxBuffer_2, sizeof(UART2_rxBuffer_2));
	}

	pc_message_recu_index ++;

}


void traiter_message_pc(){

	int a;



	switch(message_recu_PC[0]){



	case 0:   // stop
		a = 0;
		break;

	case 1:   // avancer


		break;

	case 2:   // reculer
		a = 2;

		break;

	case 3:   // droite
		a = 3;
		break;

	case 4:   // gauche
		a = 4;

		break;

	case 5:   // controle PWM

		a = 5;

		pwm = 2 * UART2_rxBuffer_2[1]; // on a un rapport *2
		break;
	}

}












