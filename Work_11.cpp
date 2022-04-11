//
// Created by Admin on 4/11/2022.
//

#include <iostream>

using namespace std;

int main() {
    int x = 0, counter = 0;
    cout << "Enter x: ";
    cin >> x;

    while (x > 0) {
        if ((x % 10) % 2 == 0) counter++;
        x /= 10;
    }

    cout << "Result = " << counter;
}