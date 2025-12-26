// Problem 3
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    unsigned int age = 0;

    cin >> age;

    if(age < 18){
        cout << "Go home, you're too young for this yet!" << "\n";
    }else if(age > 17 && age < 41){
        cout << "Welcome! Take a seat, have a bite, drink some beer and dance!" << "\n";
    }else if(age > 40 && age < 71){
        cout << "Dude, you sure you can handle this?" << "\n";
    }else{
        cout << "Welp, we are not providing funeral services..." << "\n";
    }

    return 0;
}