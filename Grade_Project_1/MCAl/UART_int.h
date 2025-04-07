#ifndef UART_INT_H_
#define UART_INT_H_

typedef enum {
	Asynchronous=0,
	synchronous
	}USART_Mode;

typedef enum {
	Disabled=0,
	Even_Parity,
	Odd_Parity
	}Parity_Mode;

 typedef enum {
	 One_Bit=0,
	 Two_Bit
	 }Stop_Bit;

typedef enum {
	FIVE_Bit=0,
    SIX_Bit,
	Seven_Bit,
	Eight_Bit
	}Bits_Settings;



void UART_Init(void);
void UART_Send(u8 data);

u8 UART_Receive(void);
u8 UART_ReceivePerodic(u8*pdata);


void UART_FrameSetting(USART_Mode mode , Parity_Mode parity ,Stop_Bit stop , Bits_Settings Bit);
void Normal_BaudRate(void);
void Double_BaudRate(void);


void UART_TRANSMIT_Enable(void);
void UART_TRANSMIT_Disable(void);
void UART_RECEIVE_Enable(void);
void UART_RECEIVE_Disable(void);



void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);

void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);

void UART_RX_SetCallBack(void (*LocalFptr)(void));
void UART_TX_SetCallBack(void (*LocalFptr)(void));

void UART_SendNoBlock(u8 data);
u8 UART_ReceiveNoBlock(void);






#endif /* UART_INT_H_ */