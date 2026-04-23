#include <iostream>
#include <random>
using namespace std;

int main(){
    random_device rd;
    mt19937 gen(rd());
    // Лимит от 1 до 50
    uniform_int_distribution<> dis(1, 51);
    unsigned int answer = dis(gen);
    unsigned int userin;

    for(unsigned int tries = 5; tries > 0; tries--){
        cout << "Enter number: ";
        cin >> userin;
        if(userin > answer){cout << "Less\n";}
        else if(userin < answer){cout << "More\n";}
        else{
            cout << "You WIN!\n";
            return 0;
        }
    }
    cout << "You lose!\n";
    return 0;
}