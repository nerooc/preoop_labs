#pragma once
#include <cmath> 
#include <iostream>
#include <string>
#include <stdlib.h>
#include <utility>
#define PI 3.14159265

class Vector2D//klasa
{
    

public:

    Vector2D(double x, double y);
    static Vector2D fromCarthesian(double x, double y);      // konstruktor z Kartezjańskimi
    static const Vector2D fromPolar(double radius, double angle);   // konstruktor z Polar
    
    Vector2D(const Vector2D& vector){
    
        count++;
        _x = vector._x;
        _y = vector._y;
        std::cout << "copying (" << vector._x << ", " << vector._y << ")" << std::endl;      
              
         
    }   //konstruktor kopiujący

    Vector2D(Vector2D&& vector){
        
        std::cout << "moving (" << vector._x << ", " << vector._y << ")" << std::endl;
    
        _x = vector._x;
        _y = vector._y;        

        vector._x = 0;
        vector._y = 0;
        
        count++;

    };    //konstruktor przenoszący


    ~Vector2D(){
            count--;
    } //destruktor


    Vector2D add(const Vector2D&) const; //funkcja dodająca wektory
    double dot(const Vector2D&) const; //funkcja odpowiadająca za iloczyn skalarny
    void print(std::string) const; //funkcja wypisująca
    
    static int count;   //zmienna licząca wektory
     

   
private:
    
    double _x; //współrzędne :)
    double _y;
};

inline Vector2D::Vector2D(double x, double y) : _x(x), _y(y) {
    count++;
 }

inline Vector2D Vector2D::fromCarthesian(double x, double y){ 
    
    return Vector2D(x, y); 
}

inline const Vector2D Vector2D::fromPolar(double radius, double angle)
{ return Vector2D(radius*std::cos(PI/(180/angle)), radius*std::sin(PI/(180/angle))); }
