#include <iostream>
#include "TString.h"
using namespace std;

int main() {
    char a[6] = "Hello";
    char b[6] = "World";
    
    TString a1(a);
    TString b1(b);
;

    cout << "len: " << a1.getlen() << endl;
    cout << "a+b: " << (a1 + b1) << endl;
    cout << "a+c: " << (a1 + '!') << endl;

    if (a1 == a1) {
        cout << "equals"  << endl;
    }
    else {
        cout << "not equals" << endl;
    }
    cout << "a1<b1: " << (a1 < b1) << endl;

    cout << "id1: " << a1[0] << endl;

    try {
        a1[100];
        cout << "err: no" << endl;
    }
    catch (...) {
        cout << "err: yes" << endl;
    }

    return 0;
}