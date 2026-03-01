#include <iostream>
#include <random>
using namespace std;
// Функция пузырьковой сортировки. В функцию передаются переменные через ссылки
void bubble_sort(int* arr, int size, int& comparisons, int& swaps, int& passes_efficient) { 
    for (int i = 0; i < size - 1; i++) {
        passes_efficient++;
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}
// Оптимизированная пузырьковая сортировка
void optimized_bubble_sort(int* arr, int size, int& comparisons, int& swaps, int& passes_efficient) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        passes_efficient++;
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
                swaps++;
            }
        }
        if (!swapped) {
            break;
        }
    }
}
// Функция сортировки вставками
void insertion_sort(int* arr, int size, int& comparisons, int& swaps) { 
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        if (j >= 0) {
            comparisons++;
        }
        arr[j + 1] = key;
        swaps++;
    }
}

int main(int argc, char* argv[]) {
    bool help_flag = false;
    bool write_flag = false;
    bool efficient_flag = false;
    // Парсинг аргументов командной строки
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--help" || arg == "-h") {
            help_flag = true;
        } else if (arg == "--write" || arg == "-w") {
            write_flag = true;
        } else if (arg == "--efficient" || arg == "-e") {
            efficient_flag = true;
        } else {
            cout << "Unknown argument: " << arg << endl;
            return 1;
        }
    }

    // Проверка на аргументы -h --help
    if (help_flag) {
        cout << "Sorting Algorithm Performance Comparison" << endl << "Bubble sort versuus Insertion sort." << endl;
        cout << "Usage: " << endl;
        cout << "-w --write: output sorted arrays to stdout." << endl;
        cout << "-e --efficient: optimize bubble sort with early exit." << endl;
        cout << "-h --help: show this message." << endl;
        return 0;
    }

    int size = 0;
    cout << "Enter the size of the array: "; cin >> size;
    if (size <= 0) {
        cout << "Invalid size." << endl;
        return 1;
    }

    int* array1 = new int[size];
    int* array2 = new int[size];
    // Генерация чисел
    random_device rd;
    mt19937 gen(rd());
    // Лимит от 0 до 1000
    uniform_int_distribution<> dis(1, 1000);

    for (int i = 0; i < size; i++) {
        array1[i] = dis(gen);
    }

    for (int i = 0; i < size; i++) {
        array2[i] = array1[i];
    }

    int cmps[2] = {0, 0};
    int swps[2] = {0, 0};
    int passes_efficient = 0;

    cout << "Generated array: ";
    for (int i = 0; i < size; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;
    if(efficient_flag){
        optimized_bubble_sort(array1, size, cmps[0], swps[0], passes_efficient);
    }else{
        bubble_sort(array1, size, cmps[0], swps[0], passes_efficient);
    }
    
    insertion_sort(array2, size, cmps[1], swps[1]);
    // Вывод отсортированных массивов, если указано в аргументах
    if (argc > 1 && (string(argv[1]) == "-w" || string(argv[1]) == "--write")) {
        cout << "Sorted array, Bubble: ";
        for (int i = 0; i < size; i++) {
            cout << array1[i] << " ";
        }
        cout << endl;
        cout << "Sorted array, Insertion: ";
        for (int i = 0; i < size; i++) {
            cout << array2[i] << " ";
        }
        cout << endl;
    }

    cout << "---Summary---" << endl;
    cout << "Bubble Sort - Comparisons: " << cmps[0] << ", Swaps: " << swps[0] << endl;
    if (efficient_flag) {
        cout << "Bubble Sort was optimized and made " << passes_efficient << " passes." << endl;
    } else {
        cout << "Bubble Sort was not optimized and made " << passes_efficient << " passes." << endl;
    }
    cout << "Insertion Sort - Comparisons: " << cmps[1] << ", Swaps: " << swps[1] << endl;
    if (cmps[0] < cmps[1]) {
        cout << "Bubble Sort is faster." << endl;
    } else if (cmps[0] > cmps[1]) {
        cout << "Insertion Sort is faster." << endl;
    } else {
        cout << "Both sorts have the same number of comparisons." << endl;
    }
    if (swps[0] < swps[1]) {
        cout << "Bubble Sort is more efficient." << endl;
    } else if (swps[0] > swps[1]) {
        cout << "Insertion Sort is more efficient." << endl;
    } else {
        cout << "Both sorts have the same number of swaps." << endl;
    }

    delete[] array1;
    delete[] array2;
    return 0;
}