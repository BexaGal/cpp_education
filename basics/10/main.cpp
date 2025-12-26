// Problem 10
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float circumference; circumference = 0;
    cin >> circumference;
    cout << pow(circumference / (2.0 * M_PI), 2) * M_PI << "\n";

    return 0;
}