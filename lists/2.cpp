#include <algorithm>
#include <iostream>
#include <list>
using namespace std;
int main(){
    list<int> numbers{};
    unsigned int n = 0;
    cout << "List size: ";
    cin >> n;
    divset:
    int divider = 1;
    cout << "Set divider: ";
    cin >> divider;
    if (divider == 0){
        cout << "Divider must not be zero\n";
        goto divset;
    }
    for (unsigned int i = 0; i < n; i++){
        int var = 0;
        cin >> var;
        numbers.push_back(var);
    }

    list<int> divisable{};

    for (auto i = numbers.begin(); i != numbers.end(); i++){
        if (*i % divider == 0){
            divisable.push_back(*i);
        }
    }
    auto iter = numbers.begin();
    while (iter != numbers.end()){
        if (*iter % divider == 0){
            iter = numbers.erase(iter);
        }else{
            iter++;
        }
    }

    for (auto i = numbers.begin(); i != numbers.end(); i++){
        cout << *i << " ";
    }
    cout << "\n";
    for (auto i = divisable.begin(); i != divisable.end(); i++){
        cout << *i << " ";
    }
    cout << "\n";
    return 0;
}