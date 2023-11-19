#include <stdio.h>
float Kp = 0.1, Ki = 0.01, Kd = 0.0001;
float dt = 0.01, integral = 0, preError = 0;

float PIDCalc(float setPoint, float measure){
	float error = 0, prop = 0, dev = 0;
	error = setPoint - measure;
	prop = error;
	integral = integral + error * dt;
	dev = (error - preError) / dt;
	preError = error;
	return Kp * prop + Ki * integral + Kd * dev;
}

void main(void){
	float resultPID = PIDCalc(12, 2);
}
