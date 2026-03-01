#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){

    char cont;

    do{
    int studnum = 0;
    reenternum:
    cout << "Enter amount of students (1-50): "; cin >> studnum;
    if(studnum <= 0 || studnum > 50){
        cout << "Please enter a valid number of students." << endl;
        goto reenternum;
    }
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
        points = 101;
    }
    float average = static_cast<float>(sumpoints) / studnum; //каст sumpoints в float
    int n = 0;
    int aboveaverage = 0;
    cout << "Reenter grades" << endl;
    while(n < studnum){
        int newpoints = 101;
        while(newpoints < 0 || newpoints > 100){
            cout << "Enter student\'s new grade points (in range of 0 to 100): "; cin >> newpoints;
        }
        if(newpoints > static_cast<float>(sumpoints) / studnum){
            aboveaverage++;
        }
        n++;
        newpoints = 101;
    }
    cout << "--------------------------------" << endl;
    cout << "Students: " << studnum << endl;
    cout << "Average grade points: " << static_cast<float>(sumpoints) / studnum << endl;
    cout << "Best grade: " << maxpoint << endl;
    cout << "Worst grade: " << minpoint << endl;
    cout << "Best graders (90-100): " << bestgraders << endl;
    cout << "Good graders (75-89): " << goodgraders << endl;
    cout << "Decent graders (60-74): " << decentgraders << endl;
    cout << "Bad graders (0-59): " << badgraders << endl;
    cout << "Best graders percentage: " << (static_cast<float>(bestgraders) / studnum) * 100 << "%" << endl;
    cout << "Above average graders: " << aboveaverage << endl;
    if(static_cast<float>(sumpoints) / studnum >= 85){
        cout << "Class performance: High" << endl;
    }else if(static_cast<float>(sumpoints) / studnum >= 70 && static_cast<float>(sumpoints) / studnum < 85){
        cout << "Class performance: Average" << endl;
    }else if (static_cast<float>(sumpoints) / studnum >= 60 && static_cast<float>(sumpoints) / studnum < 70){
        cout << "Class performance: Lower than average" << endl;
    }else{
        cout << "Class performance: Low" << endl;
    }
    if(needshelp){
        cout << "There are students in need of academic help." << endl;
    }

    cout << "---------------------------------" << endl;

    continuation:
    cout << "Do you wish to make another calculation? (Y/N): "; cin >> cont;
    if (!(cont == 'Y' || cont == 'y' || cont == 'N' || cont == 'n')){
        cout << "Choose Y or N only." << endl;
        goto continuation;
    }
    }while(cont == 'Y' || cont == 'y');

    return 0;
}