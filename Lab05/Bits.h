#pragma once
#define N 32

struct Bits{ //struktura zawierająca tablicę z bitami oraz "rozmiar" liczby binarnej
    int TAB[N] = {0};
    int rozmiar = 0;
};

void set(Bits*, int*, int); //funkcja wstawiająca bity do tablicy w strukturze

void print(const Bits*); //funkcja wypisująca tablice bitów ze struktury

const Bits add_up(const Bits*, const Bits*); //funkcja dodająca bity

void bit_and(Bits*, Bits*); //funkcja przeprowadzająca działanie "AND" na bitach

void bit_xor(Bits*, Bits*); //funkcja przeprowadzająca działanie "XOR" na bitach

int to_decimal(const Bits*); //funkcja zmieniająca liczbę dwójkową w dziesiętną
