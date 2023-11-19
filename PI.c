#include <stdio.h>
float Kp = 0.1, Ki = 0.01, integral = 0;

float PI(float setPoint, float measure){
	float error = 0, prop = 0;
	prop = error;
	integral += error * dt;
	preError = error;
	return Kp * prop + Ki * integral;
}

void main(void){
	float resultPI = PI(12, 2);
}
