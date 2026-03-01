#include <iostream>
#include <random>
using namespace std;
//Глобальные массивы для хранения количества сравнений и обменов для каждой сортировки
int comps[2] = {0, 0}; 
int swps[2] = {0, 0};
int passes_efficient = 0;
// Функция пузырьковой сортировки
void bubble_sort(int* arr, int size) { 
    int swaps = 0;
    int comparisons = 0;
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
    comps[0] = comparisons;
    swps[0] = swaps;
}
// Оптимизированная пузырьковая сортировка
void optimized_bubble_sort(int* arr, int size) {
    int swaps = 0;
    int comparisons = 0;
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
    comps[0] = comparisons;
    swps[0] = swaps;
}
// Функция сортировки вставками
void insertion_sort(int* arr, int size) { 
    int swaps = 0;
    int comparisons = 0;
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
    comps[1] = comparisons;
    swps[1] = swaps;
}

int main(int argc, char* argv[]) {
    bool help_flag = false;
    bool write_flag = false;
    bool efficient_flag = false;

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

    cout << "Generated array: ";
    for (int i = 0; i < size; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;
    if(efficient_flag){
        optimized_bubble_sort(array1, size);
    }else{
        bubble_sort(array1, size);
    }
    
    insertion_sort(array2, size);
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
    cout << "Bubble Sort - Comparisons: " << comps[0] << ", Swaps: " << swps[0] << endl;
    if (efficient_flag) {
        cout << "Bubble Sort was optimized and made " << passes_efficient << " passes." << endl;
    } else {
        cout << "Bubble Sort was not optimized and made " << passes_efficient << " passes." << endl;
    }
    cout << "Insertion Sort - Comparisons: " << comps[1] << ", Swaps: " << swps[1] << endl;
    if (comps[0] < comps[1]) {
        cout << "Bubble Sort is faster." << endl;
    } else if (comps[0] > comps[1]) {
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