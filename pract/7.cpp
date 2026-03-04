#include <iostream>

using namespace std;

struct car {
    string brand;
    string model;
    int year;
    double milage;
    double fuelrate;
    double dailyrent;
    bool isavailable;
};

int main(){
    int numcars = 0;
    cout << "Enter number of cars: "; cin >> numcars;
    if(numcars <= 0){
        cout << "Invalid number of cars." << endl;
        return 1;
    }
    car* cars = new car[numcars];
    for (int i = 0; i < numcars; i++){
        cout << "Car " << i + 1 << ":" << endl;
        cout << "Brand: "; cin >> cars[i].brand;
        cout << "Model: "; cin >> cars[i].model;
        cout << "Year: "; cin >> cars[i].year;
        cout << "Milage: "; cin >> cars[i].milage;
        cout << "Fuel rate (liters per 100 km): "; cin >> cars[i].fuelrate;
        cout << "Daily rent price: "; cin >> cars[i].dailyrent;
        char availability_input;
        avail:
        cout << "Is the car available? (Y/N): "; cin >> availability_input;
        switch (availability_input)
        {
        case 'Y':
            cars[i].isavailable = true;
            break;
        case 'N':
            cars[i].isavailable = false;
            break;
        default:
            cout << "Invalid input. Please enter Y or N." << endl;
            goto avail;
        }
    }

    car newestcar;
    for (int i = 0; i < numcars; i++){
        if (i == 0 || cars[i].year > newestcar.year){
            newestcar = cars[i];
        }
    }
    car mostruncar;
    for (int i = 0; i < numcars; i++){
        if (i == 0 || cars[i].milage > mostruncar.milage){
            mostruncar = cars[i];
        }
    }
    car mostecocar;
    for (int i = 0; i < numcars; i++){
        if (i == 0 || cars[i].fuelrate < mostecocar.fuelrate){
            mostecocar = cars[i];
        }
    }
    double averagemilage = 0;
    for (int i = 0; i < numcars; i++){
        averagemilage += cars[i].milage;
    }
    averagemilage /= numcars;
    int carsavailablecount = 0;
    for (int i = 0; i < numcars; i++){
        if (cars[i].isavailable){
            carsavailablecount++;
        }
    }
    int maxrentforseven = 0;
    for (int i = 1; i < numcars; i++){
        maxrentforseven += cars[i].dailyrent;
    }
    maxrentforseven *= 7;

    // output all cars
    cout << "All cars in the system:" << endl;
    for (int i = 0; i < numcars; i++){
        cout << "Car " << i + 1 << ": " << cars[i].brand << " " << cars[i].model << ", Year: " << cars[i].year << ", Milage: ";
        cout << cars[i].milage << ", Fuel rate: " << cars[i].fuelrate << " L/100km, Daily rent: " << cars[i].dailyrent << ", Available: " << (cars[i].isavailable ? "Yes" : "No") << endl;
    }

    // output old cars (older than 10 years)
    cout << "Cars older than 10 years:" << endl;
    for (int i = 0; i < numcars; i++){
        if (cars[i].year < 2016){
            cout << "Car " << i + 1 << ": " << cars[i].brand << " " << cars[i].model << ", Year: " << cars[i].year << ", Milage: " << cars[i].milage;
            cout << ", Fuel rate: " << cars[i].fuelrate << " L/100km, Daily rent: " << cars[i].dailyrent << ", Available: " << (cars[i].isavailable ? "Yes" : "No") << endl;
        }
    }

    // output cars with fuel rate less than 8L/100km
    cout << "Cars with fuel rate less than 8L/100km:" << endl;
    for (int i = 0; i < numcars; i++){
        if (cars[i].fuelrate < 8){
            cout << "Car " << i + 1 << ": " << cars[i].brand << " " << cars[i].model << ", Year: " << cars[i].year;
            cout << ", Milage: " << cars[i].milage << ", Fuel rate: " << cars[i].fuelrate << " L/100km, Daily rent: " << cars[i].dailyrent << ", Available: " << (cars[i].isavailable ? "Yes" : "No") << endl;
        }
    }

    cout << "Unavailable cars:" << endl;
    for (int i = 0; i < numcars; i++){
        if (!cars[i].isavailable){
            cout << "Car " << i + 1 << ": " << cars[i].brand << " " << cars[i].model << ", Year: " << cars[i].year;
            cout << ", Milage: " << cars[i].milage << ", Fuel rate: " << cars[i].fuelrate << " L/100km, Daily rent: " << cars[i].dailyrent << ", Available: " << (cars[i].isavailable ? "Yes" : "No") << endl;
        }
    }
    cout << "-----Sorting/filtering interface-----" << endl;
    string command;
    while (true){
        cout << "Command: "; cin >> command;
        if (command == "exit"){
            break;
        }else if (command == "help"){
            cout << "Available commands:" << endl;
            cout << "exit - exit the program" << endl;
            cout << "help - show this message" << endl;
            cout << "sort_year - sort cars by year in descending order" << endl;
            cout << "sort_rent - sort cars by milage in ascending order" << endl;
            cout << "find_brand - find cars by brand" << endl;
        }else if (command == "sort_year"){
            // sort cars by year in descending order
            for (int i = 0; i < numcars - 1; i++){
                for (int j = 0; j < numcars - i - 1; j++){
                    if (cars[j].year < cars[j + 1].year){
                        swap(cars[j], cars[j + 1]);
                    }
                }
            }
            for (int i = 0; i < numcars; i++){
                cout << "Car " << i + 1 << ": " << cars[i].brand << " " << cars[i].model << ", Year: " << cars[i].year;
                cout << ", Milage: " << cars[i].milage << ", Fuel rate: " << cars[i].fuelrate << " L/100km, Daily rent: " << cars[i].dailyrent << ", Available: " << (cars[i].isavailable ? "Yes" : "No") << endl;
            }
        }else if (command == "sort_rent"){
            // sort cars by milage in ascending order
            for (int i = 0; i < numcars - 1; i++){
                for (int j = 0; j < numcars - i - 1; j++){
                    if (cars[j].milage > cars[j + 1].milage){
                        swap(cars[j], cars[j + 1]);
                    }
                }
            }
            for (int i = 0; i < numcars; i++){
                cout << "Car " << i + 1 << ": " << cars[i].brand << " " << cars[i].model << ", Year: " << cars[i].year;
                cout << ", Milage: " << cars[i].milage << ", Fuel rate: " << cars[i].fuelrate << " L/100km, Daily rent: " << cars[i].dailyrent << ", Available: " << (cars[i].isavailable ? "Yes" : "No") << endl;
            }
        }else if (command == "find_brand"){
            string brand;
            cout << "Enter brand: "; cin >> brand;
            cout << "Cars with brand \"" << brand << "\":" << endl;
            for (int i = 0; i < numcars; i++){
                if (cars[i].brand == brand){
                    cout << "Car " << i + 1 << ": " << cars[i].brand << " " << cars[i].model << ", Year: " << cars[i].year;
                    cout << ", Milage: " << cars[i].milage << ", Fuel rate: " << cars[i].fuelrate << " L/100km, Daily rent: " << cars[i].dailyrent << ", Available: " << (cars[i].isavailable ? "Yes" : "No") << endl;
                }
            }
        }else{
            cout << "Unknown command. Type \"help\" for a list of commands." << endl;
        }

    }

    delete[] cars;
    return 0;
}