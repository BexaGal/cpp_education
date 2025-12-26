// problem 4
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    int a, b;

    cin >> a >> b;

    a > b ? cout << ">" << endl : (a == b ? cout << "=\n" : cout << "<\n");

    return 0;
}