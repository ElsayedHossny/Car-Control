#include "../StdTypes.h"
#include "../HAL/Motor_int.h"
#include "../SERVICES/UART_Sevices.h"
#include "../HAL/Leds_int.h"
#define  F_CPU 16000000
#include "util/delay.h"
#include "../SERVICES/PWM_Speed_Int.h"
#include "Robot.h"

volatile u8 Re_FromUART;
							  
Choose_t Arr_Tasks[NumOfTasks]={  {'F' , CAR_FRONT} , {'B' ,CAR_BACK} , {'S',Motor_Stop} ,{'R',CAR_Right},{'L',CAR_Left},
                                  {'1' , Speed_100} , {'2' , Speed_20},{'3' , Speed_30},{'4' , Speed_40},{'5' , Speed_50},
								  {'6' , Speed_60} , {'7' , Speed_70},{'8' , Speed_80},{'9' , Speed_90} ,{'E',Error}};
							  

u8 Compare_Task(u8 Re){	
	for(u8 i=0 ; i<NumOfTasks ;i++){
		if(Re == Arr_Tasks[i].N_Re){
			Arr_Tasks[i].pf();
			return 0;
		}
	}
	Arr_Tasks[NumOfTasks-1].pf();
	return 1;	
}

void Error(){
	Leds_ON(Red);
	_delay_ms(500);
	Leds_Off(Red);
}