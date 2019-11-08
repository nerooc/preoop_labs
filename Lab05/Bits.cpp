#include "Bits.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#define N 32


void set(Bits* bits, int* tab, int size){

    for(int i = 1; i <= size; i++){
        bits->TAB[N-i] = tab[size-i];
    }
    
    bits->rozmiar = size;
}

void print(const Bits* bits){
    
    for(int i = 0; i < (bits->rozmiar); i++){
        std::cout << bits->TAB[N-(bits->rozmiar)+i];
    }

    std::cout << std::endl;
}

const Bits add_up(const Bits* bits, const Bits* mask){
    
    Bits sum = {{0}, 0};
    int c = 0;
    
    for(int i = 0; i < (bits->rozmiar); i++){
    
        sum.TAB[i] = ((bits->TAB[N-i-1] ^ mask->TAB[N-i-1]) ^ c); 
        c = ((bits->TAB[N-i-1] & mask->TAB[N-i-1]) | (bits->TAB[N-i-1] & mask->TAB[N-i-1])) | (mask->TAB[N-i-1] & c); 
    }
    
    
    sum.rozmiar = 12;

    return sum;
}

void bit_and(Bits* bits, Bits* mask){
   
    for(int i = 0; i < (bits->rozmiar); i++){
        bits->TAB[N-i-1] = ((bits->TAB[N-i-1])&(mask->TAB[N-i-1]));
    }
}

void bit_xor(Bits* bits, Bits* mask){

    for(int i = 0; i < (bits->rozmiar); i++){
        bits->TAB[N-i-1] = ((bits->TAB[N-i-1])^(mask->TAB[N-i-1]));
    }

    (bits->rozmiar) = 10;
    
  
}

int to_decimal(const Bits* bits){
    
    int dziesietna = 0;
    int w = 1;
    for(int i = 0; i < (bits->rozmiar); ++i)
    {
        if(bits->TAB[N-i-1] == 1)
            dziesietna += w;
        w <<= 1;     
    }
    return dziesietna;
}
