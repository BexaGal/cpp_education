#include <iostream>
#include <random>
using namespace std;

bool predicate(int x) {
    return x >= 0;
}

bool check_EE(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (predicate(matrix[i][j])) {
                return true;
            }
        }
    }
    return false;
}

bool check_AA(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!predicate(matrix[i][j])) {
                return false;
            }
        }
    }
    return true;
}

bool check_EA(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        bool posstate = true;
        for (int j = 0; j < cols; j++) {
            if (!predicate(matrix[i][j])) {
                posstate = false;
                break;
            }
        }
        if (posstate) {
            return true;
        }
    }
    return false;
}

bool check_AE(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        bool posstate = false;
        for (int j = 0; j < cols; j++) {
            if (predicate(matrix[i][j])) {
                posstate = true;
                break;
            }
        }
        if (!posstate) {
            return false;
        }
    }
    return true;
}

int main(){
    int size1, size2;
    cout << "Enver number of lines M: "; cin >> size1;
    cout << "Enver number of columns N: "; cin >> size2;
    if(size1 <= 0 || size2 <= 0){
        cout << "Invalid size." << endl;
        return 1;
    }

    random_device rd;
    mt19937 gen(rd());
    // Лимит от -50 до 50
    uniform_int_distribution<> dis(-50, 51);

    int** matrix = new int*[size1];
    for (int i = 0; i < size1; i++){
        matrix[i] = new int[size2];
    }
    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size2; j++){
            matrix[i][j] = dis(gen);
        }
    }

    int posnums = 0;
    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size2; j++){
            if (predicate(matrix[i][j])){
                posnums++;
            }
        }
    }

    int maxlinewithpos = 0;
    int posses;
    int curmaxpos = 0;
    int totalneg = 0;
    int totalpos = 0;
    for (int i = 0; i < size1; i++){
        posses = 0;
        for (int j = 0; j < size2; j++){
            if (predicate(matrix[i][j])){
                posses++;
                totalpos++;
            }
            else{
                totalneg++;
            }
        }
        if (posses > curmaxpos) {
            maxlinewithpos = i;
            curmaxpos = posses;
        }
    }

    cout << "Generated matrix: " << endl;
    for (int i = 0; i < size1; i++){
        for (int j = 0; j < size2; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "EE: " << (check_EE(matrix, size1, size2) ? "true" : "false") << endl;
    cout << "AA: " << (check_AA(matrix, size1, size2) ? "true" : "false") << endl;
    cout << "EA: " << (check_EA(matrix, size1, size2) ? "true" : "false") << endl;
    cout << "AE: " << (check_AE(matrix, size1, size2) ? "true" : "false") << endl;

    cout << "Number of positive elements: " << posnums << endl;
    cout << "Line with the most positive elements: " << maxlinewithpos + 1 << endl;
    if (totalneg == 0){
        cout << "Matrix is positive" << endl;
    }else if (totalpos == 0){
        cout << "Matrix is negative" << endl;
    }else{
        cout << "Matrix is mixed" << endl;
    }

    for(int i = 0; i < size1; i++){
        delete[] matrix[i];
    }
    delete[] matrix;

}