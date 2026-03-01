#include <iostream>
#include <random>
using namespace std;

int main(int argc, char* argv[]) {
    random_device rd;
    mt19937 gen(rd());
    // Лимит от 0 до 1000
    uniform_int_distribution<> dis(1, 1000);
}