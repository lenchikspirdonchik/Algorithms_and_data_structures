#include <iostream>
#include <iomanip>
/*Задан двумеpный массив А из N строк и М столбцов. Составить программу для сортировки методами: пузырьковой,
 * быстрой сортировки, а также сортировка выбором. Вывести на экран неупорядоченную и упорядоченную матрицы, число сравнений (перестановок) элементов
 * в каждом методе сортировки и время, которое было потрачено на сортировку. Упорядочить каждый четный столбец массива по убыванию суммы значений элементов матрицы.*/
using namespace std;

int **matrixScrew(int **a, int n, int m) {
    int **b = new int *[m];
    for (int i = 0; i < m; i++) {
        b[i] = new int[n];
        for (int j = 0; j < n; j++) {
            b[i][j] = a[j][i];
        }
    }
    return b;
}

int bubbleSort(int *arr, int n) {
    int iterations = 0;

    for (int step = 0; step < n - 1; step++) {
        for (int i = 1; i < n - step; i++) {
            if (arr[i] > arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                iterations++;
            }
        }
    }

    return iterations;
}

int quickSort(int *arr, int low, int high) {
    int i = low;
    int j = high;
    int pivot = arr[(i + j) / 2];
    int iterations = 0;

    while (i <= j) {
        while (arr[i] > pivot) i++;
        while (arr[j] < pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
            iterations++;
        }
    }

    if (j > low) iterations += quickSort(arr, low, j);
    if (i < high) iterations += quickSort(arr, i, high);

    return iterations;
}

int choisesSort(int *arr, int n) {
    int ar[n];
    int iterations = 0;
    for (int b = 0; b < n; b++) {
        ar[b] = arr[b];
    }
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (ar[j] < ar[min])
                min = j;
            iterations++;
        }

        int tmp = ar[min];
        ar[min] = ar[i];
        ar[i] = tmp;
    }
    for (int b = 0; b < n; b++) {
        arr[b] = ar[n - b - 1];
    }

    return iterations;
}


int main() {
    int n = 0, m = 0;
    cout << "Enter M number:";
    cin >> m;
    cout << "Enter N number:";
    cin >> n;


    int **mainArray = new int *[n];
    int totalIterations = 0;
    cout << "Original array:" << endl;
    for (int i = 0; i < n; i++) {
        mainArray[i] = new int[m];
        for (int j = 0; j < m; j++) {
            mainArray[i][j] = rand() % 1000 - 400;
            cout << setw(5) << mainArray[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------\n" << endl;


    mainArray = matrixScrew(mainArray, n, m);

    //Bubble sort

    int **bubbleArray = mainArray;
    unsigned int start_time = clock();
    for (int k = 0; k < m; k += 2)
        totalIterations += bubbleSort(bubbleArray[k], n);

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    bubbleArray = matrixScrew(bubbleArray, m, n);
    cout << "Edited array (Bubble sort):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(5) << bubbleArray[i][j] << " ";
        cout << endl;
    }
    cout << "program running time = " << search_time << endl;
    cout << "Bubble Sort Iterations: " << totalIterations << endl;
    cout << "-------------------------\n" << endl;


//Quick sort

    int **quickArray = mainArray;
    start_time = clock();

    for (int k = 0; k < m; k += 2)
        totalIterations += quickSort(quickArray[k], 0, n - 1);

    end_time = clock();
    search_time = end_time - start_time;

    quickArray = matrixScrew(quickArray, m, n);
    cout << "Edited array (Quick sort):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(5) << quickArray[i][j] << " ";
        cout << endl;
    }
    cout << "program running time = " << search_time << endl;
    cout << "Quick Sort Iterations: " << totalIterations << endl;
    cout << "-------------------------\n" << endl;


//Choices sort

    start_time = clock();
    totalIterations = 0;
    int **choiceArray = mainArray;
    for (int k = 0; k < m; k += 2)
        totalIterations += choisesSort(choiceArray[k], n);

    end_time = clock();
    search_time = end_time - start_time;

    choiceArray = matrixScrew(choiceArray, m, n);
    cout << "Edited array (Choices sort):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << setw(5) << choiceArray[i][j] << " ";
        cout << endl;
    }

    cout << "program running time = " << search_time << endl;
    cout << "Choices Sort Iterations: " << totalIterations << endl;
    cout << "-------------------------\n" << endl;

}