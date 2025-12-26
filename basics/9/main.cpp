// Problem 9
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float area; area = 0;
    cin >> area;
    cout << pow(area / M_PI , 1.0/2.0) * 2 * M_PI << "\n";

    return 0;
}