#include "../StdTypes.h"
#include "../MCAl/DIO_Int.h"

#include "LCD_int.h"

#include "../CFG/Motor_cfg.h"
#include "Motor_int.h"

volatile u8 MotorArr[4][2]={ {MFR_IN1,MFR_IN2},
	                         {MBR_IN1,MBR_IN2},
		                     {MFL_IN1,MFL_IN2},
			                 {MBL_IN1,MBL_IN2}
	                       };
					
void CAR_Right(void){
	Motor_Front(Motor_FL);
	Motor_Front(Motor_BL);
	LCD_SetCursor(line_1,4); 
    LCD_WriteString((u8*)"Car Right  ");
}

void CAR_Left(void){
	Motor_Front(Motor_FR);
	Motor_Front(Motor_BR);
    LCD_SetCursor(line_1,4);
	LCD_WriteString((u8*)"Car Left  ");
}

					
						   
void Motor_Front(Motor_t M){
	DIO_WritePin(MotorArr[M][0],HIGH);
	DIO_WritePin(MotorArr[M][1],LOW);
}

void Motor_Back(Motor_t M){
	DIO_WritePin(MotorArr[M][0],LOW);
	DIO_WritePin(MotorArr[M][1],HIGH);
}

void CAR_FRONT(void){
			LCD_SetCursor(line_1,4);
			LCD_WriteString((u8*)"Car Front  ");
	for(Motor_t i=Motor_FR ; i<= Motor_BL ;i++){
		DIO_WritePin(MotorArr[i][0],HIGH);
		DIO_WritePin(MotorArr[i][1],LOW);
	}

}
void CAR_BACK(void){
				LCD_SetCursor(line_1,4);
				LCD_WriteString((u8*)"Car Back  ");
		for(Motor_t i=Motor_FR ; i<= Motor_BL ;i++){
			DIO_WritePin(MotorArr[i][0],LOW);
			DIO_WritePin(MotorArr[i][1],HIGH);
		}

}
void Motor_Stop(void){
			LCD_SetCursor(line_1,4);
			LCD_WriteString((u8*)"Car Stop  ");
	for(Motor_t i=Motor_FR ; i<= Motor_BL ;i++){
		DIO_WritePin(MotorArr[i][0],LOW);
		DIO_WritePin(MotorArr[i][1],LOW);
	}

}

