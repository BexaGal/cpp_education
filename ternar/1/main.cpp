// problem 1
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    int a, b;

    cin >> a >> b;

    (a * b) > (a + a + b + b) ? cout << a * b << endl : cout << a + a + b + b << endl;

    return 0;
}