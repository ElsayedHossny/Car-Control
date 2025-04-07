#ifndef UART_SEVICES_H_
#define UART_SEVICES_H_

void RX_Func(void);
u8 UART_ReceiveStringAshync(void); //setter
void UART_InterruptServiceInit(void);
u8 UART_GetRXFlag(void);

#endif /* UART_SEVICES_H_ */