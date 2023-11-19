#include <stdio.h>
float Kp = 0.1, Kd = 0.01, dt = 0.01, preError = 0;

float PDCalc(float setPoint, float measure){
	float error = 0, dev = 0;
	error = setPoint - measure;
	dev = (error - preError) / dt;
	preError = error;
	return Kp * error + Kd * dev;
}
void main(void){
	float resultPD = PDCalc(12, 2);
}
