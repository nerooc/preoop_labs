#include "Coordinates.h"
#include "Distance.h"
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>

Coordinates::Coordinates(std::string city, double lat1, double long1){

    this -> city = city;
    this -> lat1 = lat1;
    this -> long1 = long1;

}

void Coordinates::print() const{

    const char* l1;
    const char* l2;

    if(lat1 > 0){
        l1 = "N";
    }

    else{
        l1 = "S";
    }
    
    if(long1 > 0){
        l2 = "E";
    }

    else{
        l2 = "W";
    }

    std::cout << city << ":" << lat1 << l1 << " " << long1 << l2 << std::endl; 
}
  
void Coordinates::move(double x, double y){

    lat1 += x;
    long1 += y;

}
   
    
void Coordinates::name() const{
    std::cout << city << std::endl; 
}
   
double Coordinates::latitude() const{
    return lat1;
}

double Coordinates::longitude() const{
    return long1;
}

Distance Coordinates::distance(Coordinates& miasto) const{
    Distance temp(5);
    temp.dista = hypot(this->lat1 - miasto.lat1, this->long1 - miasto.long1);
    return temp;
}
   

    



