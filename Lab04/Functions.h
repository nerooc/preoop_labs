#pragma once

typedef double* DataPtr;

typedef void (*functionPtr)(DataPtr);

DataPtr initializeData(const int); //funkcja inicjalizująca tablicę (ciąg) o długości podanej w parametrze

void printSeries(DataPtr, DataPtr); //funkcja wypisująca tablicę (ciąg) na podstawie dwóch wskaźników na poczatek i koniec

void tripple(DataPtr); //funkcja potrajająca wartość 

void squareroot(DataPtr); //funkcja dająca pierwiastek kwadratowy z wartości

void add_one(DataPtr); //funkcja dodająca 1 do wartości

void executeFunction(functionPtr, DataPtr, DataPtr); //funkcja wywołująca inną funkcje z danymi wskaźnikami

void clearData(DataPtr); //funkcja usuwająca dane - zwalniająca dane
