#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void reversearray(int* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        swap(arr[i], arr[size - i - 1]);
    }
}
int partition(int* arr, int low, int high, int& comparisons, int& swaps) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swaps++;
    return i + 1;
}

void quicksort(int* arr, int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quicksort(arr, low, pi - 1, comparisons, swaps);
        quicksort(arr, pi + 1, high, comparisons, swaps);
    }
}

void merge(int* arr, int left, int mid, int right, int& comparisons, int& swaps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
            swaps++;
        } else {
            arr[k] = R[j];
            j++;
            swaps++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        swaps++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        swaps++;
    }
    delete[] L;
    delete[] R;
}

void mergesort(int* arr, int left, int right, int& comparisons, int& swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid, comparisons, swaps);
        mergesort(arr, mid + 1, right, comparisons, swaps);
        merge(arr, left, mid, right, comparisons, swaps);
    }
}  

void bucketsort(int* arr, int size, int& comparisons, int& swaps) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        comparisons++;
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int bucketCount = max / 10 + 1;
    vector<int>* buckets = new vector<int>[bucketCount];
    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / 10;
        buckets[bucketIndex].push_back(arr[i]);
        swaps++;
    }
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        if (!buckets[i].empty()) {
            // Бакеты сортируются быстрой сортировкой. Можно было использовать любую.
            quicksort(&buckets[i][0], 0, buckets[i].size() - 1, comparisons, swaps);
            for (size_t j = 0; j < buckets[i].size(); j++) {
                arr[index++] = buckets[i][j];
                swaps++;
            }
        }
    }
    delete[] buckets;
}

int main(int argc, char* argv[]) {
    bool help_flag = false;
    bool write_flag = false;
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--help" || arg == "-h") {
            help_flag = true;
        } else if (arg == "--write" || arg == "-w") {
            write_flag = true;
        } else {
            cout << "Unknown argument: " << arg << endl;
            return 1;
        }
    }

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
    int* array1 = new int[size];
    int* array2 = new int[size];
    int* array3 = new int[size];
    // Генерация чисел
    for (int i = 0; i < size; i++) {
        array1[i] = dis(gen);
        array2[i] = array1[i];
        array3[i] = array1[i];
    }
    int comparisons[3] = {0, 0, 0};
    int swaps[3] = {0, 0, 0};
    clock_t start[3];

    cout << "Generated array: ";
    for (int i = 0; i < size; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;
    start[0] = clock();
    quicksort(array1, 0, size - 1, comparisons[0], swaps[0]);
    clock_t end_quick = clock() - start[0];
    start[1] = clock();
    mergesort(array2, 0, size - 1, comparisons[1], swaps[1]);
    clock_t end_merge = clock() - start[1];
    start[2] = clock();
    bucketsort(array3, size, comparisons[2], swaps[2]);
    clock_t end_bucket = clock() - start[2];

    cout << "--------Targets: random arrays-------" << endl;
    if (argc > 1 && (string(argv[1]) == "-w" || string(argv[1]) == "--write")) {
        cout << "Sorted array, quicksort: ";
        for (int i = 0; i < size; i++) {
            cout << array1[i] << " ";
        }
        cout << endl;
        cout << "Sorted array, mergesort: ";
        for (int i = 0; i < size; i++) {
            cout << array2[i] << " ";
        }
        cout << endl;
        cout << "Sorted array, bucketsort: ";
        for (int i = 0; i < size; i++) {
            cout << array3[i] << " ";
        }
        cout << endl;
    }
    cout << "Quicksort: " << comparisons[0] << " comparisons, " << swaps[0] << " swaps, time: " << end_quick << " ticks" << endl;
    cout << "Mergesort: " << comparisons[1] << " comparisons, " << swaps[1] << " swaps, time: " << end_merge << " ticks" << endl;
    cout << "Bucketsort: " << comparisons[2] << " comparisons, " << swaps[2] << " swaps, time: " << end_bucket << " ticks" << endl;
    cout << "--------Target: sorted arrays-------" << endl;
    start[0] = clock(); comparisons[0] = 0; swaps[0] = 0;
    quicksort(array1, 0, size - 1, comparisons[0], swaps[0]);
    end_quick = clock() - start[0];
    cout << "Quicksort: " << comparisons[0] << " comparisons, " << swaps[0] << " swaps, time: " << end_quick << " ticks" << endl;
    start[1] = clock(); comparisons[1] = 0; swaps[1] = 0;
    mergesort(array2, 0, size - 1, comparisons[1], swaps[1]);
    end_merge = clock() - start[1];
    cout << "Mergesort: " << comparisons[1] << " comparisons, " << swaps[1] << " swaps, time: " << end_merge << " ticks" << endl;
    start[2] = clock(); comparisons[2] = 0; swaps[2] = 0;
    bucketsort(array3, size, comparisons[2], swaps[2]);
    end_bucket = clock() - start[2];
    cout << "Bucketsort: " << comparisons[2] << " comparisons, " << swaps[2] << " swaps, time: " << end_bucket << " ticks" << endl;
    if (argc > 1 && (string(argv[1]) == "-w" || string(argv[1]) == "--write")) {
        cout << "Sorted array, quicksort: ";
        for (int i = 0; i < size; i++) {
            cout << array1[i] << " ";
        }
        cout << endl;
        cout << "Sorted array, mergesort: ";
        for (int i = 0; i < size; i++) {
            cout << array2[i] << " ";
        }
        cout << endl;
        cout << "Sorted array, bucketsort: ";
        for (int i = 0; i < size; i++) {
            cout << array3[i] << " ";
        }
        cout << endl;
    }

    cout << "--------Target: reverse arrays sorted-------" << endl;
    reversearray(array1, size);
    reversearray(array2, size);
    reversearray(array3, size);
    start[0] = clock(); comparisons[0] = 0; swaps[0] = 0;
    quicksort(array1, 0, size - 1, comparisons[0], swaps[0]);
    end_quick = clock() - start[0];
    start[1] = clock(); comparisons[1] = 0; swaps[1] = 0;
    mergesort(array2, 0, size - 1, comparisons[1], swaps[1]);
    end_merge = clock() - start[1];
    start[2] = clock(); comparisons[2] = 0; swaps[2] = 0;
    bucketsort(array3, size, comparisons[2], swaps[2]);
    end_bucket = clock() - start[2];
    cout << "Quicksort: " << comparisons[0] << " comparisons, " << swaps[0] << " swaps, time: " << end_quick << " ticks" << endl;
    cout << "Mergesort: " << comparisons[1] << " comparisons, " << swaps[1] << " swaps, time: " << end_merge << " ticks" << endl;
    cout << "Bucketsort: " << comparisons[2] << " comparisons, " << swaps[2] << " swaps, time: " << end_bucket << " ticks" << endl;
    if (argc > 1 && (string(argv[1]) == "-w" || string(argv[1]) == "--write")) {
        cout << "Sorted array, quicksort: ";
        for (int i = 0; i < size; i++) {
            cout << array1[i] << " ";
        }        cout << endl;
        cout << "Sorted array, mergesort: ";
        for (int i = 0; i < size; i++) {
            cout << array2[i] << " ";
        }
        cout << endl;
        cout << "Sorted array, bucketsort: ";
        for (int i = 0; i < size; i++) {
            cout << array3[i] << " ";
        }
        cout << endl;
    }

    delete[] array1;
    delete[] array2;
    delete[] array3;
    return 0;
}