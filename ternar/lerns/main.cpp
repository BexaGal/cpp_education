#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    int a, b;

    cin >> a >> b;

    a > b ? cout << "a is greater than b\n" : (a == b ? cout << "a eq b\n" : cout << "a is less than b\n");

    return 0;
}