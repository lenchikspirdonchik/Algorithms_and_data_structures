//
// Created by Admin on 4/3/2022.
//
#include <iostream>

using namespace std;

bool getMin(int first, int second) {
    if (first < second) return true;
    return false;
}

int main() {
    double x = 0, y = 0, z = 0;
    cout << "Enter x:";
    cin >> x;
    cout << "Enter y:";
    cin >> y;
    cout << "Enter z:";
    cin >> z;
    if ((x + y) < 1) {
        if (getMin(x, y))
            x = (y + z) / 2;
        else
            y = (y + z) / 2;
    } else if (getMin(x, y))
        x = y * y;
    else
        y = y * y;

    cout << "x= "<<to_string(x)<<" y= "<<to_string(y)<<" z= "<<to_string(z)<<endl;
}