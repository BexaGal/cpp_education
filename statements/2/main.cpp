// Problem 2
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    unsigned int amount = 3;
    bool swapstate = false;
    float nums[amount] {0.0, 0.0, 0.0, 0.0};
    float substit = 0;

    for(unsigned int i = 0; i < amount; i++){
        cin >> nums[i];
    }

    do{
        swapstate = false;
        substit = 0;
        for(unsigned int i = 0; i < amount - 1; i++){
            if(nums[i] > nums[i+1]){
                substit = nums[i];
                nums[i] = nums[i+1];
                nums[i+1] = substit;
                swapstate = true;
            }
        }
    } while(swapstate);

    for(unsigned int i = 0; i < amount; i++){
        cout << nums[i] << " ";
    }
    cout << "\n";
    return 0;
}