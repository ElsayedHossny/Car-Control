#ifndef MOTOR_INT_H_
#define MOTOR_INT_H_

typedef enum {
	Motor_FR=0,
	Motor_BR=1,
	Motor_FL=2,
	Motor_BL=3,
	}Motor_t;
	
void Motor_Front(Motor_t M);
void Motor_Back(Motor_t M);	
void Motor_Stop(void);

void CAR_FRONT(void);
void CAR_BACK(void);
void CAR_Right(void);
void CAR_Left(void);



#endif /* MOTOR_INT_H_ */