// Problem 6
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    int* sides = new int[3];
    for(int i = 0; i < 3; i++){
        cin >> sides[i];
    }
    int result; result = 2 * (sides[0]*sides[1] + sides[1]*sides[2] + sides[0]*sides[2]);

    cout << result << "\n";
    delete[] sides;
    return 0;
}