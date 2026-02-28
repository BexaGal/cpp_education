#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(){
    string name;
    const string departments[] = {"IT", "Accounting", "Logistics", "Administration"};
    const string position[] = {"Intern", "Specialist", "Senior Specialist", "Head"};
    int depstate = 0;
    int posstate = 0;
    int years = 0;
    int kpi = 0;
    int overtime = 0;
    int lates = 0;
    bool violation = false;

    cout << "Enter your name: "; cin >> name;
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ". " << departments[i] << endl;
    }
    cout << "Select your department: "; cin >> depstate; depstate--;
    if(depstate < 0 || depstate > 3){
        cout << "Invalid department selected." << endl;
        return 1;
    }

    for (int i = 0; i < 4; i++)    {
        cout << i + 1 << ". " << position[i] << endl;
    }if(posstate < 0 || posstate > 3){
        cout << "Invalid position selected." << endl;
        return 1;
    }

    cout << "Select your position: "; cin >> posstate; posstate--;
    cout << "Enter your years of service: "; cin >> years;
    if(years < 0){
        cout << "Invalid years of service." << endl;
        return 1;
    }

    cout << "Enter your KPI score: "; cin >> kpi;
    if (kpi < 0 || kpi > 100){
        cout << "Invalid KPI score." << endl;
        return 1;
    }

    cout << "Enter your number of overtime hours: "; cin >> overtime;
    cout << "Enter your number of lates: "; cin >> lates;
    char violation_input;
    violat:
    cout << "Have you committed any violations? (Y/N): "; cin >> violation_input;
    switch (violation_input)
    {    case 'Y':
        violation = true;
        break;
    case 'N':
        violation = false;
        break;
    default:
        cout << "Invalid input." << endl;
        goto violat;
    }

    double salary = 0;

    switch (posstate)
    {
    case 0:
        salary = 3000000;
        break;
    case 1:
        salary = 5000000;
        break;
    case 2:
        salary = 7000000;
        break;
    case 3:
        salary = 10000000;
        break;

    default:
        cout << "Invalid position selected." << endl;
        return 1;
    }

    double base_salary = salary;

    double ypay = 0;

    if (years > 1 && years <= 3){
        ypay = 0.05;
    }else if(years > 3 && years <= 7){
        ypay = 0.1;
    }else if(years > 7){
        ypay = 0.15;
    }

    double kpi_bonus = 0;

    if (kpi >= 90){
        kpi_bonus = 0.20;
    }else if(kpi >= 80 && kpi < 90){
        kpi_bonus = 0.15;
    }else if(kpi >= 70 && kpi < 80){
        kpi_bonus = 0.10;
    }else if(kpi >= 60 && kpi < 70){
        kpi_bonus = 0.05;
    }

    double overtime_pay = overtime * (base_salary * 0.02);

    salary += overtime_pay;

    double extrad = 1;
    if (kpi < 60 && violation){
        extrad = extrad - 0.15;
    }else if (kpi < 60 && !violation){
        extrad = extrad - 0.05;
    }else if (kpi >= 60 && violation){
        extrad = extrad - 0.10;
    }

    double penalty = base_salary - (base_salary * extrad + base_salary * 0.05 * lates);
    
    const double tax = 0.12;
    salary = (base_salary + base_salary * ypay + base_salary * kpi_bonus + overtime_pay - penalty);
    cout << "-------------------------------------" << endl;
    cout << "Employee Name: " << name << endl;
    cout << "Department: " << departments[depstate] << endl;
    cout << "Position: " << position[posstate] << endl;
    cout << fixed << "Base Salary: " << base_salary << endl;
    cout << fixed << "Additional payment for years of service: " << base_salary * ypay << endl;
    cout << fixed << "KPI Bonus: " << base_salary * kpi_bonus << endl;
    cout << fixed << "Overtime Pay (btw 2 percents hourly overtime pay is a crime): " << overtime_pay << endl;
    cout << fixed << "Penalty total: " << penalty << endl;
    cout << fixed << "Total Salary pre tax: " << salary << endl;
    cout << fixed << "Income tax: " << tax * 100 << "%" << endl;
    cout << fixed << "Total Salary after tax: " << salary * (1 - tax) << endl;

    return 0;
}