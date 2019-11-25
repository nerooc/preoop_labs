#pragma once
#include <iostream>
#include <cstring>

class MyString//klasa MyString
{
    public:
            MyString(const char* napis) //konstruktor
            {
                _napis = (char*)napis;
            }
            ~MyString() // "głośny" destruktor
            {
                std::cout << "- deleting " << this->_napis << std::endl;
            }
            void append(MyString&); //funkcja dodająca do napisu
            void replace(const MyString&); //funkcja wstawiająca napis na miejsce innego 
            static void swap(MyString &str1, MyString &str2)
            {
                char* temp = str1._napis;
                str1._napis = str2._napis;
                str2._napis = temp;
                return;
            } //funkcja zamieniająca napisy miejscami
            char* str() const; //funkcja zwracająca napis 
    private:
            char* _napis; //składnik klasy
};
