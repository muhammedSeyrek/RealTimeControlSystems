#include <stdio.h>

float PID_OUT = 0.0;
int state = 1;
float motorPosition = 0;
int msCounter = 0;
int stateTime; // get main.c
int msDelay; // get main.c

float ReadMotorPosition(){
	//
}

void main(void){
	state_time_HAL_TIM_GET_COUNTER(&htim2);
	if(abs(stateTime - msDelay > 1000)){
		msCounter++;
		msDelay = stateTime;
	}	
	motorPosition = ReadMotorPosition();
	switch(state){
		case 1: //10 Radius
			PID_OUT = PID_Calc(10, motorPosition);
			Drive_BLDC_Motor(PID_OUT, motorPosition);
			if(fabs(motorPosition - 10) < 0.5){
				msCounter = 0;
				state++;
			}
			break;
		
		case 2:
			if(msCounter > 500) //500 ms bekle
				state++;
			break;
		case 3: //100 Radius
			PID_OUT = PID_Calc(100, motorPosition);
			Drive_BLDC_Motor(PID_OUT, motorPosition);
			if(fabs(motorPosition - 100) < 0.5){
				msCounter = 0;
				state++;
			}
			break;
		case 4: //back to top
			if(msCounter > 500)
				state = 1;
			break;
	}
}
