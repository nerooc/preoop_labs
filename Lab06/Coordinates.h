#pragma once
#include <string>
#include <iostream>

class Distance;

class Coordinates{

public:

    Coordinates(std::string city, double latitude, double longitude);
    void print() const;
    void move(double x, double y);
    void name() const;
    double latitude() const;
    double longitude() const;
    Distance distance(Coordinates& miasto) const;
   

    
private:

    std::string city;
    double lat1;
    double long1;

};
