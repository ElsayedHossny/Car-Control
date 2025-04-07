#ifndef ROBOT_H_
#define ROBOT_H_


#define NumOfTasks 15

typedef struct{	
	u8 N_Re;
	void (*pf) (void);
	}Choose_t;
	
void Error(void);	
u8 Compare_Task(u8 Re);





#endif /* ROBOT_H_ */