#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int x, y, n;
    cin >> x >> y >> n;
    float* cutters = new float[n];
    int* dumplings = new int[n];

    for(int i = 0, a; i < n; i++){
        cin >> a;
        cutters[i] = a*a*M_PI;
    }
    float area = x*y;
    bool operated = false;
    while(true){
        operated = false;
        for(int i = 0; i < n; i++){
            if(cutters[i] <= area){
                area = area - cutters[i];
                dumplings[i]++;
                operated = true;
            }
        }
        if (!operated) break;
    }

    cout << "dumplings: \n";
    for(int i = 0; i < n; i++){
        cout << dumplings[i] << "\n";
    }

    cout << "Remaining area: " << area << "\n";

    delete[] cutters;
    delete[] dumplings;
    return 0;
}