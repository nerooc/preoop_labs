#include "StudentList.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>


using namespace std;


void prepareList(char ***namesList, int **yearsList, int capacity){

	*(namesList) = (char**)malloc(sizeof(char*) * capacity); //alokuję pamięć na tablicę imion

	*(yearsList) = (int*)malloc(sizeof(int) * capacity); //alokuję pamięc na tablicę lat
}



void clearStudents(int* capacity, int* numberOfStudents, char*** namesList, int** yearsList){
	

	free(*yearsList);	//zwalniam pamiec z tablicy lat

	for(int i = 0; i < *numberOfStudents; i++){	//zwalniam tablice w ktorych sa imiona
		free(namesList[i]);	
	}
	
	free(*namesList);	//zwalniam pamiec z tablicy imion

}



void addStudent(int* numberOfStudents, int* capacity, char*** namesList, int ** yearsList, const char* name, const char* surname, int years){
	
	if(*numberOfStudents == *capacity - 1){  //jezeli nowy student to jeden student przed pojemnoscia to inkrementujemy pojemnosc

		*capacity++;
	}

	*(namesList) = (char**)realloc(*(namesList), (*capacity)); //realokuję z nową lub starą pojemnoscią
	*(yearsList) = (int*)realloc(*(namesList), (*capacity)); // -"-

	int rozmiar = strlen(name) + 1 + strlen(surname) + 1; //tworze zmienna o wielkosci potrzebnej na zmieszczenie imienia i nazwiska w formie "imie nazwisko\0" (dodaje "\0" na koniec bym mogl wypisywac jako stringa

	*(namesList)[*numberOfStudents] =  (char*)malloc(sizeof(char)*rozmiar); // alokuję pamięć na tablicę samych imion o rozmiarze potrzebnym na zmieszczenie imienia i nazwisko

	int i = 0; //deklaruję i zeruje zmienną "i" do użycia w pętli

	for(int i; i < (strlen(name)); i++){ // przepisuje imie na poczatek stringa po literze
		(*(namesList))[*numberOfStudents][i] = *name;
		*name++;
	}
	
	i++; 
	(*namesList)[*numberOfStudents][i] = ' ';  // tworze spacje miedzy imieniem i nazwiskiem
	i++;

	for(int i; i < (strlen(surname)); i++){ // przepisuje nazwisko na koniec stringa po literze
		(*(namesList))[*numberOfStudents][i] = *surname;
		*surname++;
	}
	
	i++;
	*(namesList)[*numberOfStudents][i] = '\0'; // tworze zakończenie naszego stringa
	(*(yearsList))[*numberOfStudents] = years;
	

}



void printListContent(int capacity, char** namesList){ 

	for(int i = 0; i < capacity; i++){ //wypisuje imienia i nazwiska studentow w petli
		printf("%s\n", namesList[i]);
	}
	
}



void printAllListContent(int capacity, char** namesList, int* yearsList){

	for(int i = 0; i < capacity; i++){ //wypisuje imienia, nazwiska i lata nauki studentow w petli
		printf("%s - %d\n", namesList[i], yearsList[i]);
	}

}



