// problem 3
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    unsigned int a, b;

    cin >> a >> b;

    cout << (a + b) % 24 << endl;

    return 0;
}