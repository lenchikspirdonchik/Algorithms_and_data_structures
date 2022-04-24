//
// Created by Admin on 4/20/2022.
//

#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int capacity = 0, result = 0;
    cout << "Enter array's capacity:";
    cin >> capacity;
    int array[capacity];
    for (int i = 0; i < capacity; i++) {
        int buff = 0;
        cin >> buff;
        array[i] = buff;
    }
    cout << "initial data:" << endl;
    for (int i = 0; i < capacity; i++)
        cout << "array[" << i << "] = " << array[i] << endl;


}

