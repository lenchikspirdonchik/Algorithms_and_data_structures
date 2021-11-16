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
int bubbleSort(int *arr, int n, int iterCount) {
    int counter = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                ++counter;
                iterCount++;
            }
        }
    }
    return iterCount;
}

int qsortRecursive(int *mas, int size, int iterCount) {
    int i = 0;
    int j = size - 1;
    int mid = mas[size / 2];

    do {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
            iterCount++;
        }
    } while (i <= j);
    if (j > 0) {
        qsortRecursive(mas, j + 1, iterCount);
    }
    if (i < size) {
        qsortRecursive(&mas[i], size - i, iterCount);
    }
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
    unsigned int start_time = clock();
    for (int a = 0; a < m; a++) {
        int ar[n];
        for (int b = 0; b < n; b++) {
            ar[b] = array[a][b];
        }
        iterationCount += bubbleSort(ar, n, iterationCount);
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
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "program running time = " << search_time << endl;
    cout << "Iteration count = " << iterationCount << endl;
    for (int i = 0; i < m; i += 2) {
        for (int l = i + 2; l < m; l += 2) {
            int sumOne = 0, sumTwo = 0;
            for (int j = 0; j < n; ++j) {
                sumOne += bubbleArray[i][j];
                sumTwo += bubbleArray[l][j];
            }
            if (sumOne < sumTwo) {
                for (int j = 0; j < n; ++j) {
                    int b = bubbleArray[i][j];
                    bubbleArray[i][j] = bubbleArray[l][j];
                    bubbleArray[l][j] = b;
                }
            }
        }
    }
    cout << "Edited array (2):" << endl;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += bubbleArray[i][j];
            cout << setw(5) << bubbleArray[i][j];
        }
        cout << "\t" << sum << endl;
    }

    //Quick sort
    cout << "\n-------------------------" << endl;
    cout << "Original array (again):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << array[i][j];
        }
        cout << endl;
    }
    start_time = clock();
    iterationCount = 0;
    for (int a = 0; a < m; a++) {
        int ar[n];
        for (int b = 0; b < n; b++) {
            ar[b] = array[a][b];
        }
        iterationCount += qsortRecursive(ar, n, iterationCount);
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
    end_time = clock();
    search_time = end_time - start_time;
    cout << "program running time = " << search_time << endl;
    cout << "Iteration count = " << iterationCount << endl;
    for (int i = 0; i < m; i += 2) {
        for (int l = i + 2; l < m; l += 2) {
            int sumOne = 0, sumTwo = 0;
            for (int j = 0; j < n; ++j) {
                sumOne += quickArray[i][j];
                sumTwo += quickArray[l][j];
            }
            if (sumOne < sumTwo) {
                for (int j = 0; j < n; ++j) {
                    int b = quickArray[i][j];
                    quickArray[i][j] = quickArray[l][j];
                    quickArray[l][j] = b;
                }
            }
        }
    }
    cout << "Edited array (2):" << endl;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += bubbleArray[i][j];
            cout << setw(5) << bubbleArray[i][j];
        }
        cout << "\t" << sum << endl;
    }

    //Choices sort
    cout << "\n-------------------------" << endl;
    cout << "Original array (again):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << array[i][j];
        }
        cout << endl;
    }
    start_time = clock();
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
    end_time = clock();
    search_time = end_time - start_time;
    cout << "program running time = " << search_time << endl;
    cout << "Iteration count = " << iterationCount << endl;

    for (int i = 0; i < m; i += 2) {
        for (int l = i + 2; l < m; l += 2) {
            int sumOne = 0, sumTwo = 0;
            for (int j = 0; j < n; ++j) {
                sumOne += choicesArray[i][j];
                sumTwo += choicesArray[l][j];
            }
            if (sumOne < sumTwo) {
                for (int j = 0; j < n; ++j) {
                    int b = choicesArray[i][j];
                    choicesArray[i][j] = choicesArray[l][j];
                    choicesArray[l][j] = b;
                }
            }
        }
    }
    cout << "Edited array (2):" << endl;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += choicesArray[i][j];
            cout << setw(5) << choicesArray[i][j];
        }
        cout << "\t" << sum << endl;
    }
}
