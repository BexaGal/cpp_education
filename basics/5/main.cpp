// Problem 5
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    int* sides = new int[g];
    for(int i = 0; i < 3; i++){
        cin >> sides[i];
    }
    int result; result = 1;

    for(int i = 0; i < 3; i++){
        result = result * sides[i];
    }
    cout << result << "\n";
    delete[] sides;
    return 0;
}