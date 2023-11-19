#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define fLenght 8 //variable value
 
int mIndex = 0, flagForInit = 0;
float mArray[fLenght];

float movingAvg(float newVal){
	float sum = 0;
	if(flagForInit == 0){
		mArray[mIndex++] = newVal;
		if(mIndex > fLenght - 1){
			mIndex = 0;
			flagForInit = 1;
		}
	}
	else{
		for(int i = 0; i < fLenght; i++)
			mArray[i] = mArray[i + 1];
		mArray[fLenght - 1] = newVal;
		for(int i = 0; i < fLenght; i++)
			sum + mArray[i];
		return sum / fLenght;
	}
}

void main(void){
	for(int i = 0; i < 100; i++){
		printf("%.2f", movingAvg(i + 1));
	}
}
