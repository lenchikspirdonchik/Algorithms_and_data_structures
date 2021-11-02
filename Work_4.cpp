//
// Created by Admin on 11/2/2021.
//
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    int m = 0, n = 0;
    int buffArray[2][3];
    cout << "Enter M and N numbers:";
    cin >> m;
    cin >> n;
    int array[m][n];
    buffArray[0][0] = INT16_MIN; // max
    buffArray[1][0] = INT16_MAX; // min
    srand(time(0));
    cout << "Original array:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int number = (rand() % 1000 + 10);
            array[i][j] = number;
            cout << setw(5) << array[i][j];

            if (number > buffArray[0][0]) {
                buffArray[0][0] = number;
                buffArray[0][1] = i;
                buffArray[0][2] = j;
            }

            if (number < buffArray[1][0]) {
                buffArray[1][0] = number;
                buffArray[1][1] = i;
                buffArray[1][2] = j;
            }

        }
        cout << endl;
    }

    cout << "\nMax and Min value and their location:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << setw(5) << buffArray[i][j];
        }
        cout << endl;
    }


}
