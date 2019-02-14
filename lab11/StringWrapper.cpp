#include <iostream>
#include <cstring>
#include "StringWrapper.h"

std::ostream & operator<<(std::ostream & output, const StringWrapper & string) {
    return output << string._string;
}

StringWrapper operator*(const int count, const StringWrapper & string) {
    return string*count;
}

StringWrapper::StringWrapper(const char * string) {
    int size = strlen(string) + 1;
    _string = new char[size];
    strcpy(_string, string);
}

StringWrapper::~StringWrapper() {
    delete [] _string;
}

bool StringWrapper::operator==(const StringWrapper & string) const {
    return !strcmp(_string, string._string);
}

StringWrapper StringWrapper::operator+(const StringWrapper & string) const {
    int size = strlen(string._string) + strlen(_string) + 1;
    char * tmp = new char[size];
    strcpy(tmp, _string);
    strcat(tmp, string._string);
    StringWrapper tmpWrapper(tmp);
    delete[] tmp;
    return tmpWrapper;
}

StringWrapper StringWrapper::operator*(const int count) const {
    int size = strlen(_string)*count + 1;
    char *tmp = new char[size];
    strcpy(tmp, _string);
    for(int i=1; i<count; i++)
        strcat(tmp, _string);
    StringWrapper tmpWrapper(tmp);
    delete[] tmp;
    return tmpWrapper;
}

StringWrapper & StringWrapper::operator=(const StringWrapper& string) {
    if(this == &string)
        return *this;
    
    delete[] _string;
    int size = strlen(string._string) + 1;
    _string = new char[size];
    strcpy(_string, string._string);
    return *this;
}