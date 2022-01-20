#include "com_pc.h"
#include "usart.h"
#include "main.h"
#include <String.h>
#include "moteur.h"
#include "com_FPGA_spi.h"



// variable globale
extern char message_recu_PC [100];
extern uint8_t txData [2];
int pwm = 0;

//MOTOR_STATE_SPEED motor_state_speed;


extern uint8_t objectif_vitesse;
extern uint8_t vitesse_actuelle;


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


/*
	if (UART2_rxBuffer_2[2] == 101){
		strcpy((char *)message_recu_PC,(char *)UART2_rxBuffer_2);
		HAL_UART_Receive_IT(&huart2, UART2_rxBuffer_2, sizeof(UART2_rxBuffer_2));
		traiter_message_pc();
	}
*/

	message_recu_PC[pc_message_recu_index] = UART2_rxBuffer;
	pc_message_recu_index ++;


	if (UART2_rxBuffer == 101){ // on est a la fin du message
		pc_message_recu_index = 0;


		traiter_message_pc();

		message_recu_PC[0] = 0;
		message_recu_PC[1] = 0;
		message_recu_PC[2] = 0;
		message_recu_PC[3] = 0;


	}

	HAL_UART_Receive_IT(&huart2, &UART2_rxBuffer, 1);


	/*
	 * if (UART2_rxBuffer_2[pc_message_recu_index] == 101){ // on est a la fin du message
		pc_message_recu_index = 0;
		strcpy((char *)message_recu_PC,(char *)UART2_rxBuffer_2);
		pc_message_recu_index = 0;
		traiter_message_pc();

		HAL_UART_Abort(&huart2);
		MX_USART2_UART_Init();
		HAL_Delay(10);
		HAL_UART_Receive_IT(&huart2, UART2_rxBuffer_2, sizeof(&UART2_rxBuffer_2));
	}

	pc_message_recu_index ++;
	 */


}


void traiter_message_pc(){

	int a;

	fct_vierge();

	switch(message_recu_PC[0]){



	case 0:   // stop
		fct_vierge();
		moteur1();
		cmd_arret();
		spi_transmission();

		fct_vierge();
		moteur2();
		cmd_arret();
		spi_transmission();

		break;

	case 1:   // avancer

		fct_vierge();
		moteur1();
		sens_rotation_avant();
		spi_transmission();

		fct_vierge();
		moteur2();
		sens_rotation_avant();
		spi_transmission();


		fct_vierge();
		moteur1();
		vit_rap_cyc(10); // on va a 10 pourcent
		spi_transmission();

		fct_vierge();
		moteur2();
		vit_rap_cyc(10);
		spi_transmission();



		break;

	case 2:   // reculer

		fct_vierge();
		moteur1();
		sens_rotation_arriere();
		spi_transmission();

		fct_vierge();
		moteur2();
		sens_rotation_arriere();
		spi_transmission();


		fct_vierge();
		moteur1();
		vit_rap_cyc(10); // on va a 10 pourcent
		spi_transmission();

		fct_vierge();
		moteur2();
		vit_rap_cyc(10);
		spi_transmission();


		break;

	case 3:   // droite
		a = 3;
		break;

	case 4:   // gauche
		a = 4;

		break;

	case 5:   // controle PWM
		fct_vierge();
		moteur2();
		config_freq_PWM();
		txData[1] = message_recu_PC[1] << 1;
		spi_transmission();
		break;

	case 6:  // contrôle du rapport cyclique
		//fct_vierge();
		//moteur2();
		//vit_rap_cyc(message_recu_PC[1]);  // modif pour la rampe d'accélération
		objectif_vitesse = message_recu_PC[1];
		//spi_transmission();

		break;
	}





}












