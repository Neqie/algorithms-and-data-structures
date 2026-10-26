#include "TString.h"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>

const int MAX_INPUT = 1000;


TString::TString() {
    size = 0;
    str = new char[1];
    str[0] = '\0';
}

TString::TString(int n) {
    if (n < 0) throw std::invalid_argument("Size cannot be negative");
    size = n;
    str = new char[size + 1];
    std::fill(str, str + size, '\0');
    str[size] = '\0';
}

TString::TString(const char* ch) {
    if (ch == nullptr) {
        size = 0;
        str = new char[1];
        str[0] = '\0';
        return;
    }
    size = std::strlen(ch);
    str = new char[size + 1];
    std::copy(ch, ch + size + 1, str);
}

TString::TString(const TString& s) {
    size = s.size;
    str = new char[size + 1];
    std::memcpy(str, s.str, size + 1);
}

TString::~TString() {
    delete[] str;
}

TString& TString::operator=(const TString& s) {
    if (this != &s) {
        TString temp(s);
        std::swap(size, temp.size);
        std::swap(str, temp.str);
    }
    return *this;
}

TString TString::operator+(const TString& s)  {
    TString res(size + s.size);
    int i;
    for (i = 0; i < size; i++) {
        res.str[i] = str[i];
    }
    for (i = size; i < size + s.size; i++) {
        res.str[i] = s.str[i - size];
    }
    res.str[i] = '\0';
    return res;
}

TString TString::operator+(char c)  {
    TString res(size + 1);
    int i;
    for (i = 0; i < size; i++) {
        res.str[i] = str[i];
    }
    res.str[size] = c;
    res.str[size + 1] = '\0';
    return res;
}

bool TString::operator==(const TString& s) const {
    return size == s.size && std::strcmp(str, s.str) == 0;
}

bool TString::operator>(const TString& s)  {
    return std::strcmp(str, s.str) > 0;
}

bool TString::operator<(const TString& s) {
    return std::strcmp(str, s.str) < 0;
}

char& TString::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return str[index];
}

std::istream& operator>>(std::istream& is, TString& s) {
    char buffer[MAX_INPUT];
    is >> buffer; 
    s = TString(buffer);
    return is;
}

std::ostream& operator<<(std::ostream& os, const TString& s) {
    os << s.str;
    return os;
}

int TString::getlen() const {
    return size;
}
