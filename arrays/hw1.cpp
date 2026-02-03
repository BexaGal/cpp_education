// divide array of numbers into two arrays of odd and even numbers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(){
    unsigned int amount = 0;
    cin >> amount;
    int* arr = new int[amount];
    
    for(unsigned int i = 0; i < amount; i++){
        cin >> arr[i];
    }
    unsigned int oddcount = 0;
    unsigned int evencount = 0;
    for(unsigned int i = 0; i < amount; i++){
        if(arr[i] % 2){
            oddcount++;
        } else {
            evencount++;
        }
    }

    int* evenarr = new int[evencount];
    int* oddarr = new int[oddcount];
    unsigned int odditerator = 0;
    unsigned int eveniterator = 0;
    for(unsigned int i = 0; i < amount; i++){
        if(arr[i] % 2){
            oddarr[odditerator] = arr[i];
            odditerator++;
        } else{
            evenarr[eveniterator] = arr[i];
            eveniterator++;
        }
    }
    cout << "Odd array" << "\n";
    for(unsigned int i = 0; i < oddcount; i++){
        cout << oddarr[i] << ' ';
    }
    cout << "\n" << "Even array" << "\n";
    for(unsigned int i = 0; i < evencount; i++){
        cout << evenarr[i] << ' ';
    }
    cout << '\n';

    delete[] arr; delete[] oddarr; delete[] evenarr;
    return 0;
}