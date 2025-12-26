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

bool primestring(int n[3][4]){
    bool primesubarray = false;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            if(!isprime(n[i][j])){
                break;
            }
            if(j == 3){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int testnums[3][4] = {{1, 2, 3, 4}, {11, 13, 17, 257}, {22, 13, 17, 5}};
    cout << primestring(testnums) << endl;
    return 0;
}