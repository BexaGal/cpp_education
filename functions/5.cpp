#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

bool isprime(int n){

    if(n == 0 || n == 1){
        return false;
    }
    if(n == 2){
        return true;
    }
    if(n % 2 == 0){
        return false;
    }
    for(int i = 3; i * i <= n; i += 2){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int testnum = 0;
    cin >> testnum;

    cout << isprime(testnum) << endl;

    return 0;
}