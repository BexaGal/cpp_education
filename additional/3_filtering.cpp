#include <iostream>

using namespace std;

int main(){
    unsigned int size = 0;
    cout <<"Array size: "; cin >> size;
    int* array = new int[size];

    for(unsigned int i = 0; i < size; i++){cin >> array[i];}

    // Outputting evens
    cout << "\nEVENS:\n";
    for(unsigned int i = 0; i < size; i++){
        if(array[i] % 2 == 0){cout << array[i] << " ";}
    }
    cout << "\n";
    //Trimming negatives (replacing with zeroes)
    for(unsigned int i = 0; i < size; i++){
        if(array[i] < 0){array[i] = 0;}
    }

    // Counting positives' sum
    unsigned int sum = 0;
    for(unsigned int i = 0; i < size; i++){
        sum += array[i];                        // Since all negatives are already zero we can just sum all
    }
    cout << "Sum of positives: " << sum << endl;

    // outputting changed array
    cout << "Positives only array:\n";
    for(unsigned int i = 0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << "\n";
    delete[] array;
    return 0;
}