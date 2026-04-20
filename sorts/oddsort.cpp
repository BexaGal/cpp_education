#include <iostream>
#include <random>
using namespace std;

void oddsort(float* arr, unsigned int num){ // сортировка нечётных элементов
    bool swapped;
    for (unsigned int i = 1; i < num - 1; i = i + 2) {
        swapped = false;
        for (unsigned int j = 1; j < num - i - 1; j = j + 2) {
            if (arr[j] > arr[j + 2]) {
                swap(arr[j], arr[j + 2]);
                swapped = true;
            }
            cout << "iteration " << i << " " << j << " complete\n";
        }
        if (!swapped) {
            break;
        }
    }
}

int main(int argc, char* argv[]){
    random_device rd;
    mt19937 gen(rd()); 
    uniform_real_distribution<> dis(0.0f, 100.0f);
    unsigned int n = 0;
    cin >> n;
    float* array = new float[n];

    for(unsigned int i = 0; i < n; i++) array[i] = dis(gen);
    cout << "array generated\n";
    oddsort(array, n);
    cout << "sorting complete\n";
    for(unsigned int i = 0; i < n; i++) cout << array[i] << " | ";
    cout << "\n";

    delete[] array;
    return 0;
}