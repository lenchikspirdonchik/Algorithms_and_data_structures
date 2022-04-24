//
// Created by Admin on 4/20/2022.
//

#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    int capacity = 0, result1 = 0, result2 = 0, result3 = 0;
    cout << "Enter array's capacity:";
    cin >> capacity;
    int array[capacity];
    const int *a = array;
    int *p = array;
    for (int i = 0; i < capacity; i++) {
        int buff = 0;
        cin >> buff;
        array[i] = buff;
    }
    cout << "initial data:" << endl;
    for (int i = 0; i < capacity; i++)
        cout << "array[" << i << "] = " << array[i] << endl;

    cout<< "Прогоняем массив от 0, до конца, с ходом +2 для анализа только четных индексов. Если остаток от деления числа == 0 -> число четное.\nСкладываем его с общим счетчиком" << endl;

    //first method
    for (int i = 0; i < capacity; i += 2) {
        if (array[i] % 2 == 0)
            result1 += array[i];
    }
    cout << "\nresult 1 = " << result1 << endl;

    //second method
    for (int i = 0; i < capacity; i += 2) {
        if (a[i] % 2 == 0)
            result2 += a[i];
    }

    cout << "\nresult 2 = " << result2 << endl;

    //third method
    for (int i = 0; i < capacity; i += 2) {
        if (p[i] % 2 == 0)
            result3 += a[i];
    }

    cout << "\nresult 3 = " << result3 << endl;
}

