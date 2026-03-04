#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Employee {
    int id;
    char name[50];
    char position[30];
    double salary;
    bool isActive;
};

void addEmployee(const char* filename, Employee emp) {
    ofstream out(filename, ios::binary | ios::app);
    out.write((char*)&emp, sizeof(Employee));
    out.close();
}

void readAll(const char* filename) {
    ifstream in(filename, ios::binary);
    Employee emp;
    while(in.read((char*)&emp, sizeof(Employee))) {
        cout << "ID: " << emp.id << " | Name: " << emp.name << " | Salary: " << emp.salary << endl;
    }
    in.close();
}

int main() {
    Employee e1 = {101, "Aliyev Akmal", "Dev", 12000000, true};
    Employee e2 = {102, "Karimov Aziz", "Manager", 15000000, true};

    addEmployee("employees.dat", e1);
    addEmployee("employees.dat", e2);

    cout << "Данные из бинарного файла:" << endl;
    readAll("employees.dat");

    // Текстовое сравнение
    ofstream txt("employees.txt");
    txt << e1.id << " " << e1.name << " " << e1.salary << endl;
    txt.close();

    cout << "\nПроверьте размеры файлов в директории: .dat vs .txt" << endl;
    return 0;
}