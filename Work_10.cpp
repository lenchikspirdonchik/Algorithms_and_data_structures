//
// Created by Admin on 4/11/2022.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x = 0;
    int n = 0;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter n: ";
    cin >> n;
    double result = x;

    for (int i = 2; i <= n; i++)
        result += (i * pow(x, i));

    cout << "Result = " << result;
}
