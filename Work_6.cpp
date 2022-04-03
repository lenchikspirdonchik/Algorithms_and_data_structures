//
// Created by Admin on 11/29/2021.
//
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

int simpleHash(int k, int hash) {
    return k % hash;
}

void quickSort(int *arr, int low, int high) {
    int i = low;
    int j = high;
    int pivot = arr[(i + j) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (j > low) quickSort(arr, low, j);
    if (i < high) quickSort(arr, i, high);
}

int binarySearch(const int *arr, int n, int d) {
    bool flag = false;
    int left = 0;
    int right = n - 1;
    int middle = 0;

    while ((left <= right) && !flag) {
        middle = (left + right) / 2;

        if (arr[middle] == d) flag = true;
        if (arr[middle] > d) right = middle - 1;
        else left = middle + 1;
    }

    if (!flag) return -1;
    return middle;
}

int main() {
    srand(time(0));
    int n = 0, m = 0, key = 0, hashM;
    cout << "-------------------------" << endl;
    cout << "Enter M number: ";
    cin >> m;
    cout << "Enter N number: ";
    cin >> n;
    cout << "Enter Key: ";
    cin >> key;
    cout << "Enter Hash M: ";
    cin >> hashM;
    cout << "-------------------------\n" << endl;

    int **mainArray = new int *[m];
    cout << "Original array:" << endl;
    for (int i = 0; i < m; i++) {
        mainArray[i] = new int[n];
        for (int j = 0; j < n; j++) {
            mainArray[i][j] = rand() % 100 - 30;
            cout << setw(5) << mainArray[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------\n" << endl;


    //Linear Search
    unsigned int start_time = clock();
    int count = 0, an = -1, am = -1;
    cout << "Linear Search" << endl;
    for (int i = 0; i < m; i += 2) {
        for (int j = 0; j < n; j++) {
            if (mainArray[i][j] == key) {
                cout << "New match found: " << "[ " << i << ", " << j << " ]\n";
                count++;
            }
        }
    }
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << endl << "Count of found matches: " << count << endl;
    cout << "program running time = " << search_time << endl;
    cout << "-------------------------\n" << endl;



    //Binary Search

    int **sortedArray = mainArray;
    for (int k = 0; k < m; k++)
        quickSort(sortedArray[k], 0, n - 1);

    cout << "Sorted array (Quick sort):" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(5) << sortedArray[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    start_time = clock();
    for (int i = 0; i < m; i++) {
        int **buffArray = sortedArray;
        if (i % 2 == 0) {
            if (binarySearch(buffArray[i], n, key) != -1) {
                am = binarySearch(buffArray[i], n, key);
                an = i;
            }
        } else {
            int *buff = new int[n / 2];

            for (int z = 0; z < n / 2; z++) {
                buff[z] = buffArray[i][z * 2];
            }

            if (binarySearch(buff, n / 2, key) != -1) {
                am = binarySearch(buff, n / 2, key) * 2;
                an = i;
            }

            for (int z = 0; z < n / 2; z++) {
                buffArray[i][z * 2] = buff[z];
            }
        }
    }
    end_time = clock();
    search_time = end_time - start_time;


    cout << "Binary search: " << "[" << an << ", " << am << "]" << endl;
    cout << "program running time = " << search_time << endl;
    cout << "-------------------------\n" << endl;



    //Find Collisions
    start_time = clock();
    map<int, int> hashesMap;
    int collisions = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i % 2 == 0) {
                hashesMap[simpleHash(mainArray[i][j], hashM)] += 1;
                if (hashesMap[simpleHash(sortedArray[i][j], hashM)] != 1) {
                    collisions += 1;
                }
            }
        }
    }

    cout << "Collisions was found for this hashes: ";
    map<int, int>::iterator it = hashesMap.begin();
    for (; it != hashesMap.end(); it++) {
        if ((it->second) > 1) cout << it->first << " ";
    }
    end_time = clock();
    search_time = end_time - start_time;
    cout << "\n" << endl;
    cout << "Collisions count: " << collisions << endl;
    cout << "program running time = " << search_time << endl;

}