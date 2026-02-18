#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
int main(){
    list<int> numbers{5, 2, 1, 4, 8, 19};
    int orig = numbers.size();
    auto iter = numbers.begin();
    for (iter; iter != numbers.end(); iter++){
        cout << *iter << " ";
    }
    cout << endl;
    int resr = 3;
    numbers.resize(resr);

    for (auto i = numbers.begin(); i != numbers.end(); i++){
        cout << *i << " ";
    }
    cout << endl;

    for (int i = orig; i > resr; i--){
        iter--;
    }

    for (resr; resr != orig; resr++){
        numbers.resize(resr, *iter);
        iter++;
    }

    for (auto i = numbers.begin(); i != numbers.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}