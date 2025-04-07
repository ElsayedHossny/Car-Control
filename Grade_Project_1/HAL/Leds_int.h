#ifndef LEDS_INT_H_
#define LEDS_INT_H_

typedef enum{
	Red=0,
	Yellow=1,
	Green=2
	}led_t;

void Leds_ON(led_t led);
void Leds_Off(led_t led);

#endif /* LEDS_INT_H_ */