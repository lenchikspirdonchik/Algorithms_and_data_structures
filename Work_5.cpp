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
void bubbleSort(int *arr, int n) {
    int counter = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ++counter;
            }
        }
    }
}

int QuickSort(int *ar, int l, int r, int iterCount) {
    int mid = ar[(l + r) / 2];
    int i = l, j = r;
    do {
        while (ar[i] < mid) i++;
        while (mid < ar[j]) j--;
        if (i <= j) {
            int temp = ar[i];
            ar[i++] = ar[j];
            ar[j--] = temp;
            iterCount++;
        }
    } while (i < j);
    if (l < j)
        QuickSort(ar, l, j, iterCount);
    if (i < r)
        QuickSort(ar, i, r, iterCount);
    return iterCount;
}


int main() {
    int m = 0, n = 0;
    cout << "Enter M number:";
    cin >> m;
    cout << "Enter N number:";
    cin >> n;
    int array[m][n];
    int bubbleArray[m][n];
    int quickArray[m][n];
    int choicesArray[m][n];
    int iterationCount = 0;
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
        bubbleSort(ar, n);
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
    cout << "Iteration count = " << iterationCount << endl;


    //Quick sort
    cout << "\n-------------------------" << endl;
    cout << "Original array (again):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << array[i][j];
        }
        cout << endl;
    }

    iterationCount = 0;
    for (int a = 0; a < m; a++) {
        int ar[n];
        for (int b = 0; b < n; b++) {
            ar[b] = array[a][b];
        }
        iterationCount += QuickSort(ar, 0, n, iterationCount);
        for (int b = 0; b < n; b++) {
            quickArray[a][b] = ar[b];
        }
    }
    cout << "Edited array (Quick sort):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << quickArray[i][j];
        }
        cout << endl;
    }
    cout << "Iteration count = " << iterationCount << endl;

    //Choices sort
    cout << "\n-------------------------" << endl;
    cout << "Original array (again):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << array[i][j];
        }
        cout << endl;
    }
    iterationCount = 0;

    for (int a = 0; a < m; a++) {
        int ar[n];
        for (int b = 0; b < n; b++) {
            ar[b] = array[a][b];
        }
        for (int i = 0; i < n - 1; i++) {
            int min = i;
            for (int j = i + 1; j < n; j++) {
                if (ar[j] < ar[min])
                    min = j;
                iterationCount++;
            }

            int tmp = ar[min];
            ar[min] = ar[i];
            ar[i] = tmp;
        }
        for (int b = 0; b < n; b++) {
            choicesArray[a][b] = ar[b];
        }
    }
    cout << "Edited array (Choices sort):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << choicesArray[i][j];
        }
        cout << endl;
    }
    cout << "Iteration count = " << iterationCount << endl;
}
