#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float LPFOut = 0;
float alpha = 0.5; //Variable value

float BasicLPF(float newVal){
	LPFOut = alpha * newVal + (1 - alpha) * LPFOut;
	return LPFOut;
}

void main(void){
	srand(time(NULL));
	float resultLPFOut = BasicLPF(rand() % 9 + 1);
}
