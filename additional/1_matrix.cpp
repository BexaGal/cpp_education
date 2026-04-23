#include <iostream>

using namespace std;

// Finds minimal element of matrix using basic sweep
int findmin(unsigned int** arr, unsigned int n1 = 1, unsigned int n2 = 1){
    int minim = arr[0][0];
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++)
            if(arr[i][j]){
                if(minim > arr[i][j]){minim = arr[i][j];}
            }
    }
    return minim;
}
// Sweeps matrix for largest element
int findmax(unsigned int** arr, unsigned int n1 = 1, unsigned int n2 = 1){
    int maxim = arr[0][0];
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++)
            if(arr[i][j]){
                if(maxim < arr[i][j]){maxim = arr[i][j];}
            }
    }
    return maxim;
}
// Prints matrix adding forward spaces to uniformly display matrix
void printmatrix(unsigned int** arr, unsigned int n1 = 1, unsigned int n2 = 1, bool pretty = false){
    unsigned int maximum = findmax(arr, n1, n2);    // Getting maximum element
    unsigned int len = 0;                           // Length of that number
    unsigned int blanks = 0;                        // Blanks to fill the spaces with
    while(maximum > 0){                             // Counting length of the maximum element
        maximum /= 10;
        len++;
    }
    unsigned int tempnum = 0;                       // Current number will be saved here
    unsigned int templen = 0;                       // Current number's length will be here
    for(int i = 0; i < n1; i++){                    // Basic sweep
        if (pretty && i == 0) {cout << "/";}                // If pretyy flag is on output matrix with brackets
        else if (pretty && i == n1 - 1) {cout << "\\";}
        else if (pretty) {cout << "|";}
        for(int j = 0; j < n2; j++){
            tempnum = arr[i][j];                    // We save current number to tempnum buffer so it can be safelly trimmed for counting
            templen = 0;
            while(tempnum > 0){                     // Counting the length of current numer 
                tempnum /= 10;
                templen++;
            }
            blanks = len - templen;                 // Getting number of blank spaces to fill the gaps with
            for(unsigned int k = 0; k < blanks; k++){       // Outputting these blanks
               cout << " ";
            }
            cout << arr[i][j] << " ";               // Output the current number
        }
        if (pretty && i == 0) {cout << "\\";}
        else if (pretty && i == n1 - 1) {cout << "/";}
        else if (pretty) {cout << "|";}
        cout << "\n";                               // Next row on a new line
    }
}

int main(int argc, char* argv[]){

    bool help_flag = false;
    bool pretty_flag = false;
    bool simple_flag = false;
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--help" || arg == "-h") {
            help_flag = true;
        } else if (arg == "--pretty" || arg == "-p") {
            pretty_flag = true;
        } else {
            cout << "Unknown argument: " << arg << endl;
            return 1;
        }
    }

    if(help_flag){
        cout << "MATRIX DATA OUTPUT\nBY BEXA\n\n";
        cout << "-h --help : Output this message.\n";
        cout << "-p --pretty : Print the matrix with brackets.\n\n\n";
        cout << "Celebrating people approaching the Moon again!\n";
        return 0;
    }

    unsigned int rows = 0; unsigned int columns = 0;
    cout << "Enter dimentions: "; cin >> rows >> columns;
    if(rows < 1 || columns < 1){
        cout << "ERROR: dimensions must be larger than 0\n";
        return 1;
    }
    unsigned int** matrix = new unsigned int*[rows];        // Declaring memory space for the matrix as pointer to pointers
    for(int i = 0; i < rows; i++){
        matrix[i] = new unsigned int[columns];              // These are the columns. Matrix stores pointers to these columns
    }


    for(int i = 0; i < rows; i++){                          // Populating the matrix
        for(int j = 0; j < columns; j++){
            cout << "Enter row " << i << " ";
            cout << "Column " << j <<": "; cin >> matrix[i][j];
        }
    }
    cout << "Matrix:\n";
    printmatrix(matrix, rows, columns, pretty_flag);                     // Printing the matrix

    cout << "Minimal element: " << findmin(matrix, rows, columns) << endl;  // Printing the minimal element

    for(int i = 0; i < rows; i++){                          // Deletion routine
        delete[] matrix[i];                                 // Each column must be deleted separately, since deletion of "pointer to pointers"
    }                                                       // leaves pointers to columns ontouched, dangling in heap.
    delete[] matrix;                                        // Deletion of the original matrix.

    return 0;
}