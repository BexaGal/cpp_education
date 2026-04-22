#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ofstream out;
    out.open("bexa.txt");
    if(out.is_open()){
        out << "Hello to all students in the room!\n";
    }
    if(out.is_open()){
        out << "Next entry:\n";
    }
    out.close();
    ifstream in;
    string line;
    in.open("bexa.txt");
    if(in.is_open()){
        while(getline(in, line)){
            cout << line << endl;
        }
    }
    return 0;
}