#pragma once

/**
@fn find_ctrl
@brief funkcja oblicza cyfrę kontrolną na podstawie algorytmu
@param f wskaźnik do struktury przechowującej wskaźnik do funkcji i argument
@return liczba otrzymana w wyniku poddania danych wejściowych algorytmowi to cyfra kontrolna 
*/
char find_ctrl(const char *karta);

/**
@fn number_correct
@brief funkcja sprawdza na podstawie funkcji find_ctrl() czy dany numer karty jest prawidłowy
@param f wskaźnik do struktury przechowującej wskaźnik do funkcji i argument
@return wartość bool zwracająca true jeżeli numer jest prawidłowy oraz false jeżeli jest błędny
*/
bool number_correct(const char *karta); 
