#include "MyString.h"
#include <iostream>
#include <cstring>

MyString::MyString(const char *string) {
    int size = strlen(string) + 1;
    _string = new char[size];
    strcpy(_string, string);
}

char *MyString::str() const {
    return _string;
}

void MyString::setStr(char *string) {
    _string = string;
}

void MyString::join(const MyString &string) {
    int newSize = strlen(_string) + strlen(string._string) + 1;
    char *newString = new char[newSize];
    strcpy(newString, _string);
    strcat(newString, string._string);
    delete[] _string;
    _string = newString;
}

void MyString::replace(const char *string) {
    int newSize = strlen(string) + 1;
    char *newString = new char[newSize];
    strcpy(newString, string);
    delete[] _string;
    _string = newString;
}

MyString::~MyString() {
    std::cout << "- deleting " << _string << std::endl;
    delete[] _string;

}

void swap(MyString &s1, MyString &s2) {
    char *tmp = new char[strlen(s1.str()) + 1];
    strcpy(tmp, s1.str());
    s1.replace(s2.str());
    s2.replace(tmp);
    delete [] tmp;
}