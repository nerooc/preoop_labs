#include "StudentList.h"
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>


using namespace std;


void prepareList(char ***namesList, int **yearsList, int capacity){

	*(namesList) = (char**)malloc(sizeof(char*) * capacity); //alokuję pamięć na tablicę imion

	*(yearsList) = (int*)malloc(sizeof(int) * capacity); 	 //alokuję pamięc na tablicę lat studiowania
}



void clearStudents(int* capacity, int* numberOfStudents, char*** namesList, int** yearsList){
	
	
	free(*yearsList);	//zwalniam pamiec z tablicy lat
	
	for(int i = 0; i < (*numberOfStudents) - 1; i++){	//zwalniam tablice w ktorych sa imiona
		free((*namesList)[i]);	
	}
	
	free(*namesList);	//zwalniam pamiec z tablicy imion

	*capacity = 0;		//zmieniamy capacity na 0
	
	*numberOfStudents = 0;	//zmieniamy liczbę studentów na 0
}



void addStudent(int* numberOfStudents, int* capacity, char*** namesList, int ** yearsList, const char* name, const char* surname, int years){
	
	if((*numberOfStudents) == ((*capacity) - 1)){  //jezeli nowy student to jeden student przed pojemnoscia to inkrementujemy pojemnosc

		(*capacity)++;
		

		char **namesList2 = NULL;
		int *yearsList2 = NULL;

		namesList2 = (char**)realloc(*namesList, (*capacity)*(sizeof(char*))); //realokuję z nową pojemnoscią
		yearsList2 = (int*)realloc(*yearsList, (*capacity)*(sizeof(int))); // -"-

		*namesList = namesList2;	//przypisuję do starego adresu by zgadzały się wszystkie oznaczenia
		*yearsList = yearsList2;
	
	}

	
	
	int rozmiar = strlen(name) + 1 + strlen(surname) + 1; //tworze zmienna o wielkosci potrzebnej na zmieszczenie imienia i nazwiska w formie "imie nazwisko\0" (dodaje "\0" na koniec bym mogl wypisywac jako stringa
	
	
	
	(*namesList)[*numberOfStudents] =  (char*)malloc(sizeof(char)*rozmiar); // alokuję pamięć na tablicę samych imion o rozmiarze potrzebnym na zmieszczenie imienia i nazwisko


	for(int i = 0; i < (strlen(name)); i++){   // przepisuje imie na poczatek stringa po literze
		(*(namesList))[*numberOfStudents][i] = name[i];
	}


	int i = strlen(name);	//ustawiam zmienną "i" na element po końcu imienia, by móc wstawić tam spację

	
	(*namesList)[*numberOfStudents][i] = ' ';  // tworze spacje miedzy imieniem i nazwiskiem


	int j = 0;	//deklaruję zmienną, która pozwoli mi przepisać nazwisko


	for(int i = (strlen(name) + 1); i <= (rozmiar-2); i++){ // przepisuje nazwisko na koniec stringa po literze
		(*namesList)[*numberOfStudents][i] = surname[j];
		j++;
	}

	
	i = rozmiar - 1;	//ustawiam zmienną "i" na ostatni element zaalokowanej tablicy

	
	(*namesList)[*numberOfStudents][i] = '\0'; // tworze zakończenie naszego stringa
	
	(*yearsList)[*numberOfStudents] = years;// wpisuje liczbe lat studiowania do tablicy



	(*numberOfStudents)++;  // zwiekszam liczbe studentow (powoduje potem zwiekszenie zmiennej capacity i wywolania funkcji dla nowych wartosci)
}



void printListContent(int capacity, char** namesList){ 

	for(int i = 0; i < (capacity-1); i++){ //wypisuje imiona i nazwiska studentow w petli
		printf("%s\n", namesList[i]);
	}
	
	printf("\n");
}



void printAllListContent (int capacity, char **namesList, int *yearsList){

	for(int i = 0; i < (capacity-1); i++){ //wypisuje imiona, nazwiska i lata nauki studentow w petli
		printf("%s - %d\n", namesList[i], yearsList[i]);
	}

	printf("\n");
}



