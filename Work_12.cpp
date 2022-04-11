//
// Created by Admin on 4/11/2022.
//
#include <iostream>

using namespace std;

int main() {
    string scanner;
    cin >> scanner;
    while (scanner != ".") {
        int counter = 0, number = stoi(scanner);
        while (number > 0) {
            counter += number % 10;
            number /= 10;
        }
        cout << "Counter = " << counter << endl;
        cin >> scanner;
    }
}

