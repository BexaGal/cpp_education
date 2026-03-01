#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double calculate_total(double* sales, int size){
    double total = 0;
    for (int i = 0; i < size; i++){
        total += *(sales + i);
    }
    return total;
}

double calculate_average(double* sales, int size){
    double total = calculate_total(sales, size);
    return total / size;
}

double findmax(double* arr, int size){
    double max = *arr;
    for (int i = 1; i < size; i++){
        if (*(arr + i) > max){
            max = *(arr + i);
        }
    }
    return max;
}

double findmin(double* arr, int size){
    double min = *arr;
    for (int i = 1; i < size; i++){
        if (*(arr + i) < min){
            min = *(arr + i);
        }
    }
    return min;
}

void bubblesortinplace(double* arr, int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (*(arr + j) > *(arr + j + 1)){
                double temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main(){
    int days = 0;
    daysreenter:
    cout << "Enter amount of days in month: "; cin >> days;
    if(days < 1 || days > 31){
        cout << "Invalid amount of days." << endl;
        goto daysreenter;
    }
    double* sales = new double[days];

    for (int i = 0; i < days; i++){
        cout << "Enter sales total for a day " << i + 1<< ": "; cin >> *(sales + i);
    }

    double avg = calculate_average(sales, days);

    cout << "-------------------------------------" << endl;

    cout << "Total sales for the month: " << calculate_total(sales, days) << endl;
    cout << "Average sales for the month: " << avg << endl;
    cout << "Maximum sales for the month: " << findmax(sales, days) << endl;
    cout << "Minimum sales for the month: " << findmin(sales, days) << endl;
    int daysabavg = 0;
    for (int i = 0; i < days; i++){
        if (*(sales + i) > avg){
            daysabavg++;
        }
    }
    cout << "Days with sales above average: ";
    cout << daysabavg << endl;
    
    int daysminus = 0;
    for (int i = 0; i < days; i++){
        if (*(sales + i) < 0){
            daysminus++;
        }
    }
    
    if(daysminus > 0){
        cout << "There were " << daysminus << " days with negative sales." << endl;
    } else{
        cout << "There were no days with negative sales." << endl;
    }

    for (int i = 0; i < days; i++){
        *(sales + i) = abs(*(sales + i) * 1.05);
    }

    bubblesortinplace(sales, days);
    cout << "Sales sorted in ascending order after inflation (5%) simulation: ";
    for (int i = 0; i < days; i++){
        cout << *(sales + i) << " ";
    }
    cout << endl;

    delete[] sales;
    sales = nullptr;


    return 0;
}