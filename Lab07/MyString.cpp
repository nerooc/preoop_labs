#include "MyString.h"
#include <iostream>

void MyString::append(MyString &add)
{
    char* tab = new char[strlen(_napis) + strlen(add._napis) + 1];
    strcpy(tab, _napis);
    strcpy(tab+strlen(_napis),add._napis);
    _napis = tab;
    return;
}

void MyString::replace(const MyString &replace)
{
    _napis = replace._napis;
    return;
}

char* MyString::str() const
{
   return _napis;
}
