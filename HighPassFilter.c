#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float alpha = 0.5; //variable value
float HPFOut = 0, preVal = 0;

float BasicHPF(float newVal){
	HPFOut = alpha * HPFOut + alpha * (newVal - preVal);
	preVal = newVal;
	return HPFOut;
}

void main(void){
	srand(time(NULL));
	float resultHPF = BasicHPF(rand() % 9 + 1);
}
