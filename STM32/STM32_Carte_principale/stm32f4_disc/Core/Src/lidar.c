/*
 * lidar.c
 *
 *  Created on: Oct 14, 2021
 *      Author: Thomas VERNOUX
 */


#include "lidar.h"
#include "usart.h"
#include "gpio.h"
#include "main.h"
#include "tim.h"
#include <string.h>
#include <stdio.h>

enum BIT_STATE {start1, start2, size, data, end}; // structure pour le prochain bit qu'on va recevoir du lidar
enum BIT_STATE last_bit_state = end;
enum BIT_STATE bit_state;

enum LIDAR_STATE {stop, scan};
enum LIDAR_STATE lidar_state = stop;


uint8_t taille_message_recu;
uint8_t lidar_message_recu [100];
int index_ecriture_message_recu;

uint8_t octet_recu;

/// variables du mode scan
int compteur = 0;


// reducteur de trames
int NUMtrame = 0;





void demarrer_pwm_lidar(){

  TIM1->CCR1 = 30000;
  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  return;


  }




/*
 * Test
 */
void tests_lidar(){

	reset_lidar();

	memset(lidar_message_recu,0,sizeof(lidar_message_recu));



	//reset_lidar();
	//HAL_Delay(100);

	//lidar_get_info();

	//lidar_scan();




	return;
}



void mouvement_moteur(int vitesse){

}

void reset_lidar(){
	uint8_t Data[2] = {0xA5, 0x40};
	HAL_UART_Transmit(&huart3, Data, 2, 100);
	memset(lidar_message_recu,0,sizeof(lidar_message_recu));
	return;
}



void lidar_get_info(){
	uint8_t Data[2] = {0xA5, 0x50};
	HAL_UART_Transmit(&huart3, Data, 2, 100);
	return;
}


void lidar_scan(){
	uint8_t Data[2] = {0xA5, 0x20};
	HAL_UART_Transmit(&huart3, Data, 2, 100);
	return;
}



void uart_lidar_recieve(){

	octet_recu = UART3_rxBuffer;

	switch (lidar_state){

		case stop: // le lidar n'est pas en scan

			if ((octet_recu == 0xA5) && (last_bit_state == end) ){  // on recoit l'octet de start
				bit_state = start1;
				taille_message_recu = 0; // on remet a zero la taille du message recu
				index_ecriture_message_recu = 0;
				memset(lidar_message_recu,0,sizeof(lidar_message_recu)); // on efface le buffer
				}

			else if ((last_bit_state == start1) && (octet_recu == 0x5A)){ // on recoit le deuxième octet de start
				bit_state = start2;
			}

			else if (last_bit_state == start2){   // on a l'octet qui donne la taille de la communication
				bit_state = size;
				taille_message_recu = octet_recu;
			}

			else if ((last_bit_state == size) || (last_bit_state == data)){     // on a une data
				bit_state = data;
				reception_octet_data();

			}



			last_bit_state = bit_state; // machine d'état

			break;

		case scan :

			if (compteur == 4){
				// on transmet


				////// a reprendreeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee

				compteur = 0;

				float angle = (float)(lidar_message_recu[1] >> 1) + (float)lidar_message_recu[2] * 256;
				angle = angle / 1.41 / 64;
				float distance = (float)lidar_message_recu[4];


				uint8_t angle_8 = (uint8_t) angle;
				uint8_t distance_8 = (uint8_t) distance;

				uint8_t message_a_transmettre[3] = {1,distance_8,angle_8};


				// on reduit le nombre de trames qu'on envoit
				if (NUMtrame == 100){
					HAL_UART_Transmit(&huart2, message_a_transmettre, 3, 100);
					NUMtrame = 0;
				}
				NUMtrame ++;
			}

			lidar_message_recu[compteur] = octet_recu;

			compteur ++;


			break;




		}

	return;
}

void reception_octet_data(){
		lidar_message_recu[index_ecriture_message_recu] = octet_recu;
		index_ecriture_message_recu ++;
		if (index_ecriture_message_recu == taille_message_recu){
			bit_state = end;
			lidar_fin_du_message_recu();
		}


	return;
}


void lidar_fin_du_message_recu(){      // on transmet le message au PC



	// on est en mode scan
	if((lidar_message_recu[0] == 0x0) && (lidar_message_recu[1] == 0x0) && (lidar_message_recu[2] == 0x40) && (lidar_message_recu[3] == 0x81)){
		lidar_state = scan;

	}



	return;



}













