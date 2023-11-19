#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float avarageFilter(float *val, float size){
	float sum = 0;
	for(int i = 0; i < size; i++)
		sum += val[i];
	return sum / size;
}

void main(void){
	srand(time(NULL));
	float val[100];
	for(int i = 0; i < 100; i++)
		val[i] = i + 1;
	float resultAF = avarageFilter(&val, sizeof(val) / sizeof(float));
}
