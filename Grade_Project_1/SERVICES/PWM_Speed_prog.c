#include "../MCAl/Timers.h"
#include "../MemMap.h"
#include "PWM_Speed_Int.h"
#include "../HAL/LCD_int.h"

void Max_valueOFSpeed(void){
    ICR1=65530;
	Speed_50();
	TCNT1=0;		
}

void Speed_20 (void){
	OCR1A= (0.2*ICR1);
	LCD_SetCursor(line_2,12);
	LCD_WriteString((u8*)"20%  ");
}
void Speed_30 (void){
	OCR1A= (0.3*ICR1);
	LCD_SetCursor(line_2,12);
	LCD_WriteString((u8*)"30%  ");
}
void Speed_40 (void){
	OCR1A= (0.4*ICR1);
	LCD_SetCursor(line_2,12);
	LCD_WriteString((u8*)"40%  ");
}
void Speed_50 (void){
	OCR1A= (0.5*ICR1);
	LCD_SetCursor(line_2,12);
	LCD_WriteString((u8*)"50%  ");
}
void Speed_60 (void){
	OCR1A=(0.6*ICR1);
	LCD_SetCursor(line_2,12);
	LCD_WriteString((u8*)"60%  ");
}
void Speed_70 (void){
	OCR1A=(0.7*ICR1);
	LCD_SetCursor(line_2,12);
	LCD_WriteString((u8*)"70%  ");
}
void Speed_80 (void){
	OCR1A=(0.8*ICR1);
	LCD_SetCursor(line_2,12);
	LCD_WriteString((u8*)"80%  ");
}
void Speed_90 (void){
	OCR1A=(0.9*ICR1);
	LCD_SetCursor(line_2,12);
	LCD_WriteString((u8*)"90%  ");
}
void Speed_100 (void){
	OCR1A=ICR1;
	LCD_SetCursor(line_2,12);
	LCD_WriteString((u8*)"100%  ");
}
