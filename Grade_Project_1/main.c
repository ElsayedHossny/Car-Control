#include "MemMap.h"
#include "StdTypes.h"

#define  F_CPU   16000000
#include "util/delay.h"

#include "MCAl/DIO_Int.h"
#include "HAL/Motor_int.h"
#include "HAL/LCD_int.h"
#include "HAL/Leds_int.h"
#include "MCAl/Timers.h"

#include "MCAl/UART_int.h"
#include "SERVICES/UART_Sevices.h"
#include "SERVICES/PWM_Speed_Int.h"

#include "App/Robot.h"

int main(void)
{	
	DIO_Init();
	LCD_Init();
	UART_Init();
	UART_InterruptServiceInit();
	sei(); //open Global Interrupt	
    Timer1_Init(TIMER1_PhaseCorrect_ICR1_MODE,TIMER1_SCALER_8);
    Timer1_OCRA1Mode(OCRA_NON_INVERTING);//  Mode of OCA on compare match
	Max_valueOFSpeed();
	
u8 f=0;
LCD_SetCursor(line_1,4);
LCD_WriteString((u8*)"Car Stop  ");
LCD_SetCursor(line_2,0);
LCD_WriteString((u8*)"Car Speed : 50%  ");
    while (1) 
    {
		if (UART_GetRXFlag())
		{
			f=UART_ReceiveStringAshync();
			Compare_Task(f);
// 			LCD_SetCursor(line_1,12);
// 			LCD_WriteChar(f);
		}
    }
}

