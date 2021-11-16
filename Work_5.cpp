//
// Created by Admin on 11/16/2021.
//
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

/*Задан двумеpный массив А из N строк и М столбцов. Составить программу для сортировки методами: пузырьковой,
 * быстрой сортировки, а также сортировка выбором. Вывести на экран неупорядоченную и упорядоченную матрицы,
 * число сравнений (перестановок) элементов в каждом методе сортировки и время, которое было потрачено на сортировку.
 * Упорядочить каждый четный столбец массива по убыванию суммы значений элементов матрицы.*/

void QuickSort(int *ar, int l, int r) {
    int mid = ar[(l + r) / 2];
    int i = l, j = r;
    do {
        while (ar[i] < mid) i++;
        while (mid < ar[j]) j--;
        if (i <= j) {
            int temp = ar[i];
            ar[i++] = ar[j];
            ar[j--] = temp;
        }
    } while (i <= j);
    if (l < j)
        QuickSort(ar, l, j);
    if (i < r)
        QuickSort(ar, i, r);
}


int main() {
    int m = 0, n = 0;
    cout << "Enter M number:";
    cin >> m;
    cout << "Enter N number:";
    cin >> n;
    int array[m][n];
    int bubbleArray[m][n];
    int fastArray[m][n];
    srand(time(0));
    cout << "Original array:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int number = (rand() % 100 + 10);
            array[i][j] = number;
            cout << setw(5) << array[i][j];
        }
        cout << endl;
    }

    //bubble sort
    for (int a = 0; a < m; a++) {
        int ar[n];
        for (int b = 0; b < n; b++) {
            ar[b] = array[a][b];
        }
        for (int i = 0; i < n; i++) {
            bool b = false;
            for (int j = 0; j < n; j++) {
                if (ar[j] > ar[j + 1]) {
                    int Tmp = ar[j];
                    ar[j] = ar[j + 1];
                    ar[j + 1] = Tmp;
                    b = true;
                }
            }
            if (!b) break;
        }
        for (int b = 0; b < n; b++) {
            bubbleArray[a][b] = ar[b];
        }
    }

    cout << "Edited array (bubble sort):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << bubbleArray[i][j];
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
    cout << "Original array (again):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << array[i][j];
        }
        cout << endl;
    }


    for (int a = 0; a < m; a++) {
        int ar[n];
        for (int b = 0; b < n; b++) {
            ar[b] = array[a][b];
        }
        QuickSort(ar, 0, n);
        for (int b = 0; b < n; b++) {
            fastArray[a][b] = ar[b];
        }
    }
    cout << "Edited array (fast sort):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << fastArray[i][j];
        }
        cout << endl;
    }


    cout << "-------------------------" << endl;
    cout << "Original array (again):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << array[i][j];
        }
        cout << endl;
    }
}
