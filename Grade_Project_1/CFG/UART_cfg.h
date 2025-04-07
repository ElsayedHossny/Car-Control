#ifndef UART_CFG_H_
#define UART_CFG_H_

/*
           NORMAL        Double
BR		UBRR  Error    UBRR  Error
2400	416   -0.1%    832   0.0%
4800    207   0.2%     416   -0.1% 
9600    103   0.2%     207   0.2%   // 51->8MHZ
*/

#define UBRR_Reg  103

#endif /* UART_CFG_H_ */