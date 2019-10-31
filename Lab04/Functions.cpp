#include "Functions.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

typedef double* DataPtr;

typedef void (*functionPtr)(DataPtr);

DataPtr initializeData(const int size){	
	DataPtr tab;
	tab = (DataPtr)malloc(sizeof(double)*size);
	
	double j = 0;
	

	for(int i = 0; i < size; i++){
		tab[i] = j;
		j++;
	}	
	
	
	return tab;
}

void printSeries(DataPtr ptrStart, DataPtr ptrEnd){
	
	for(DataPtr temp = ptrStart; temp < ptrEnd - 1; temp++){
			//printf("%.5f, ", (*temp));
			std::cout << *temp << ", ";
	
	}
	std::cout << *(ptrEnd - 1) << std::endl;
	//printf("%.5f\n", *(ptrEnd - 1)); < to mi wyrzucało duuużo zer, więc wolimy cout :))
	

}

void tripple(DataPtr x){
	(*x) = 3* (*x);
}

void squareroot(DataPtr x){
	*x = sqrt(*x);
}

void add_one(DataPtr x){
	(*x) = (*x) + 1;
}

void executeFunction(functionPtr func, DataPtr ptrStart, DataPtr ptrEnd){
	for(DataPtr temp = ptrStart; temp < ptrEnd; temp++){
		func(temp);
	}
}

void clearData(DataPtr Data){
	free(Data);
}
