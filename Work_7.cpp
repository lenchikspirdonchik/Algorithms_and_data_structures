//
// Created by Admin on 3/16/2022.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double m = 0, n = 0;
    cout << "Enter m:";
    cin >> m;
    cout << "Enter n:";
    cin >> n;

    double numerator = sqrt(abs(m - n)) - (sin(m) * cos(n));
    double denominator = log(tan(m / n)) + pow(M_E, pow(m, 1));
    cout << "numerator = " << numerator << endl;
    cout << "denominator = " << denominator << endl;
    double resG = numerator / denominator;
    cout << "G = " << resG;
}