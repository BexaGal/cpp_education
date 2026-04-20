#include <iostream>
#include <random>
using namespace std;

void posshift(int* arr, unsigned int n){
    int* array2 = new int[n];
    unsigned int index2 = 0;
    for(unsigned int i = 0; i < n; i++){
        if(arr[i] > 0){
            array2[index2] = arr[i];
            index2++;
        }
    }
    for (unsigned int i = index2 + 1; i < n; i++){
        array2[i] = 0;
    }
    for(unsigned int i = 0; i < n; i++){
        arr[i] = array2[i];
    }
    delete[] array2;
}

int main(){
    // Генерация чисел
    random_device rd;
    mt19937 gen(rd());
    // Лимит от 0 до 1000
    uniform_int_distribution<> dis(-10, 10);

    unsigned int n = 0;
    cin >> n;
    int* array = new int[n];
    for(unsigned int i = 0; i < n; i++) array[i] = dis(gen);
    for(unsigned int i = 0; i < n; i++) cout << array[i] << "\n";
    cout << "_____________\n";
    posshift(array, n);

    for(unsigned int i = 0; i < n; i++) cout << array[i] << "\n";

    

    delete[] array;
    return 0;
}