// Radix sort
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int getMax(int* arr, int n){
    int maxn = arr[0];
    for(int i = 1; i < n; i++){
        if (arr[i] > maxn){
            maxn = arr[i];
        }
    }
    return maxn;
}

void countSort(int* arr, int n, int exp)
{
    int output[n]; // временный массив для хранения результата
    int i, count[10] = { 0 }; //массив разрядов

    for (i = 0; i < n; i++){
        count[(arr[i] / exp) % 10]++; // для каждого разряда считаем количество чисел
    }
    for (i = 1; i < 10; i++){
        count[i] += count[i - 1]; // сдвигаем
    }
    for (i = n - 1; i >= 0; i--) { // непосредственная сортировка
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; // На места разрядных мест ставятся соответствующие числа из оригинального массива
        count[(arr[i] / exp) % 10]--; // уменьшаем счётчик
    }

    for (i = 0; i < n; i++){ // вывод результата в массив
        arr[i] = output[i];
    }
}

void lsd_radix_sort(int* arr, int n){
    int mx = getMax(arr, n);

    for (int exp = 1; mx / exp > 0; exp *= 10){
        countSort(arr, n, exp);
    }

}

int main(){
    random_device rd;
    mt19937 gen(rd());
    // Лимит от 0 до 1000
    uniform_int_distribution<> dis(1, 1000);

    int size = 0;
    cout << "Enter the size of the array: "; cin >> size;
    if (size <= 0) {
        cout << "Invalid size." << endl;
        return 1;
    }
    int* array = new int[size];

    // Генерация чисел
    for (int i = 0; i < size; i++) {
        array[i] = dis(gen);
    }
    
    lsd_radix_sort(array, size);

    for(int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << "\n";


    delete[] array;
    return 0;
}