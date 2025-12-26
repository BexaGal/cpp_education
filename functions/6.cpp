#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

int digitsum(int n){
    unsigned int sum = 0;
    unsigned int absn = abs(n);
    unsigned int count = 0;
    if(n == 0){
        return 0;
    }
    while(absn > 0){
        absn = absn / 10;
        count++;
    }
    for(int i = 0; i <= count; i++){
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

int main(){
    int testnum = 0;
    cin >> testnum;

    cout << digitsum(testnum) << endl;

    return 0;
}