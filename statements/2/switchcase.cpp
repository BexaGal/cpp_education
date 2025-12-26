// Problem 2
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    float a = 0, b = 0, c = 0;

    cin >> a >> b >> c;

    if(a <= b && b <= c ){
        cout << a << " " << b << " " << c << "\n";
    }else if(a < c && c < b ){
        cout << a << " " << c << " " << b << "\n";
    }else if( b < a && a < c ){
        cout << b << " " << a << " " << c << "\n";
    }else if( b < c && c < a){
        cout << b << " " << c << " " << a << "\n";
    }else if( c < a && a < b ){
        cout << c << " " << a << " " << b << "\n";
    }else{
        cout << c << " " << b << " " << a << "\n";
    }

    return 0;
}