#include <iostream>
using namespace std;
 int main (int argc, char* argv[]){
    int x, y;
    int map[4][2] = {{1, 1}, {-1,1}, {-1,-1}, {1,-1}};
    cin >> x; cin >> y;
    if (x == 0){ cout << "On line X" << endl; return 0;}
    if (y == 0){ cout << "On line Y" << endl; return 0;}
    for (int i = 0; i < 4; i++){
        if (x * map[i][0] > 0 && y * map[i][1] > 0){
            cout << "Quadrant " << i + 1 << endl;
            break;
        }
    }

    return 0;
 }