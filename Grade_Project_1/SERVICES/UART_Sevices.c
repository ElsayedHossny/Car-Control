
#include "../StdTypes.h"
#include "../MCAl/UART_int.h"
#include "UART_Sevices.h"

#include "../HAL/LCD_int.h"


/********************************************Design_TX,RX_UART_Interrupt********************************************/

volatile u8 UART_ReceiveBuffer ,RX_Flag=0 ;



void RX_Func(void){
	RX_Flag=1;
	UART_ReceiveBuffer=UART_ReceiveNoBlock();
}

void UART_InterruptServiceInit(void)
{
	UART_RX_SetCallBack(RX_Func);
	UART_RX_InterruptEnable();
}


u8 UART_ReceiveStringAshync(void){
	return UART_ReceiveBuffer;
}

u8 UART_GetRXFlag(void)
{// Known me the string compelete
	u8 f=RX_Flag;
	RX_Flag=0;
	return f;
}









