
// Created by Admin on 4/3/2022.
//
#include <iostream>
#include <cmath>

using namespace std;

double function(int x, int y) {
    if (x < 0) return y - x;
    if (x >= 0 && y < 0) return y * y - x;
    return sin(y);
}

int main() {
    int x = 0, y = 0;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    cout << "result: " << function(x, y) << endl;
}

