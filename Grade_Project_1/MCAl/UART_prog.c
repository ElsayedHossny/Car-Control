#include "../MemMap.h"
#include "../StdTypes.h"

#include "../CFG/UART_cfg.h"
#include "UART_int.h"

static void(*UART_RX_Fptr)(void)=NULLPTR;
static void(*UART_TX_Fptr)(void)=NULLPTR;


void UART_FrameSetting(USART_Mode mode , Parity_Mode parity ,Stop_Bit stop , Bits_Settings Bit){
/*	SET_BIT(UCSRC,URSEL);*/	
	/*USART_Mode*/
	if(mode==Asynchronous){
		CLR_BIT(UCSRC, UMSEL);
		}else{
		SET_BIT(UCSRC,UMSEL);
	}
		/*Parity_Mode*/
		switch(parity){
			case Disabled   : CLR_BIT(UCSRC,UPM1); CLR_BIT(UCSRC,UPM0); break;
			case Even_Parity: SET_BIT(UCSRC,UPM1); CLR_BIT(UCSRC,UPM0); break;
			case Odd_Parity : SET_BIT(UCSRC,UPM1); SET_BIT(UCSRC,UPM0); break;
			default: break;
		}
	/*Stop_Bit*/
	if(stop==One_Bit){
		CLR_BIT(UCSRC,USBS);
		}else{
		SET_BIT(UCSRC,USBS);
	}

	/*Bits_Settings*/
	switch(Bit){
		case FIVE_Bit : CLR_BIT(UCSRB,UCSZ2); CLR_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ0); break;
		case SIX_Bit  : CLR_BIT(UCSRB,UCSZ2); CLR_BIT(UCSRC,UCSZ1); SET_BIT(UCSRC,UCSZ0); break;
		case Seven_Bit: CLR_BIT(UCSRB,UCSZ2); SET_BIT(UCSRC,UCSZ1); CLR_BIT(UCSRC,UCSZ0); break;
		case Eight_Bit: CLR_BIT(UCSRB,UCSZ2); SET_BIT(UCSRC,UCSZ1); SET_BIT(UCSRC,UCSZ0); break;
		default: break;
	}
	

}



void UART_Init(void)
{	
 	/*Baud_Rate*/
 	Normal_BaudRate();
 	UBRRL=UBRR_Reg; //value in register BR_reg=103 , CPU=16MHZ
	/*enable*/
	UART_TRANSMIT_Enable();
 	UART_RECEIVE_Enable();
}

/*******************************UART_Send***********************************/
void UART_Send(u8 data)
{
	//Blocking
	while(!GET_BIT(UCSRA,UDRE));
	UDR=data;
}

/*******************************UART_Receive***********************************/
u8 UART_Receive(void)
{
	//Busy_Wait
	while(!GET_BIT(UCSRA,RXC));
	return UDR;
}


u8 UART_ReceivePerodic(u8*pdata)
{
	//polling
	if (GET_BIT(UCSRA,RXC))
	{
		*pdata=UDR;
		return 1;
	}
	return 0;	
}


/**************************** BaudRate functions**************************************/
void Normal_BaudRate(void){
	CLR_BIT(UCSRA,U2X);
}
void Double_BaudRate(void){
	SET_BIT(UCSRA,U2X);
}
/**************************** TX,RX functions**************************************/
void UART_TRANSMIT_Enable(void){
	SET_BIT( UCSRB,TXEN);	
}
void UART_TRANSMIT_Disable(void){
	CLR_BIT( UCSRB,TXEN);
}
void UART_RECEIVE_Enable(void){
	SET_BIT( UCSRB,RXEN);
}
void UART_RECEIVE_Disable(void){
	CLR_BIT( UCSRB,RXEN);
}

/**************************** TX,RX Interrupt functions**************************************/

void UART_SendNoBlock(u8 data)
{
	UDR=data;
}

u8 UART_ReceiveNoBlock(void)
{
	return UDR;
}

void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,RXCIE);
}

void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}

void UART_TX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,TXCIE);
}

/*********************************UART Callback-ISR functions*********************************************/

void UART_RX_SetCallBack(void (*LocalFptr)(void))
{
	UART_RX_Fptr = LocalFptr;
}

void UART_TX_SetCallBack(void (*LocalFptr)(void))
{
	UART_TX_Fptr = LocalFptr;
}


ISR(UART_RX_vect)
{
	if (UART_RX_Fptr!=NULLPTR)
	{
		UART_RX_Fptr();
	}
}

ISR(UART_TX_vect)
{
	if (UART_TX_Fptr!=NULLPTR)
	{
		UART_TX_Fptr();
	}
}