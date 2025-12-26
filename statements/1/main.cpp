// Problem 1
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    float a; a = 0;
    float b; b = 0;

    cin >> a >> b;

    if(a >= b){
        cout << a << " " << b << "\n";
    } else if(a < b){
        cout << b << " " << a << "\n";
    };

    return 0;
}