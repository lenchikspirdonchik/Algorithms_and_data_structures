//
// Created by Admin on 4/12/2022.
//
# include <iostream>
#include <cmath>

using namespace std;

int fact(int startNum, int endNum) {
    int result = 1;
    for (int i = startNum; i <= endNum; i += 2)
        result *= i;
    return result;
}

int main() {
    double E = pow(10, -5);
    double x = 0, midRes = 1, chisl = 1, znam = 1, result = 1;
    int n = 1, degree = 1;
    bool isPlus = false;
    cout << "E= " << E << endl;
    cout << "Enter x:"; //0.49487 - if more -> error
    cin >> x;
    if (x * x < 1) {
        while (E <= fabs(midRes)) {
            chisl = fact(1, n++) * pow(x, degree++);
            znam = (fact(2, n++));
            midRes = chisl / znam;
            if (!isPlus) midRes *= -1;
            isPlus = !isPlus;
            result += midRes;

            cout << chisl << "/" << znam << " = " << midRes << endl;
        }

        cout << "Result (x): " << result << endl;

        double y = 1 / (sqrt(1 + x));

        cout << "Result (y): " << y << endl;
    } else
        cout << "Error!: x^2 >=1";
}