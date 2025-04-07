#include "../StdTypes.h"
#include "../MCAl/DIO_int.h"
#include "../CFG/Leds_cfg.h"
#include "Leds_int.h"

volatile u8 Arr_Leds [NumOfLEDS]={ LED_R , LED_Y , LED_G };

void Leds_ON(led_t led){		
	DIO_WritePin(Arr_Leds[led],HIGH); 
}
void Leds_Off(led_t led){
    DIO_WritePin(Arr_Leds[led],LOW); 	
}