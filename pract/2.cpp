#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(){

    char cont;

    do{
    int studnum = 0;
    string name;
    int points = 101;
    int sumpoints = 0;
    int bestgraders = 0;
    int goodgraders = 0;
    int decentgraders = 0;
    int badgraders = 0;
    int maxpoint = 0;
    int minpoint = 100;
    bool needshelp = false;
    for (int i = 0; i < studnum; i++){
        cout << "Enter student\'s name: " << endl;
        while(points < 0 || points > 100){
            cout << "Enter student's grade points (in range of 0 to 100): "; cin >> points;
        }
        sumpoints += points;
        if(points >= 90){
            bestgraders++;
        }else if(points >= 75 && points < 90){  
            goodgraders++;
        }else if(points >= 60 && points < 75){
            decentgraders++;
        }else{
            badgraders++;
            needshelp = true;
        }

        if (points > maxpoint){
            maxpoint = points;
        }
        if (points < minpoint){
            minpoint = points;
        }

    
    }

    cout << "";

    continuation:
    cout << "Do you wish to make another calculation? (Y/N): "; cin >> cont;
    if (!(cont == 'Y' || cont == 'y' || cont == 'N' || cont == 'n')){
        cout << "Choose Y or N only." << endl;
        goto continuation;
    }
    }while(cont == 'Y' || cont == 'y');

    return 0;
}