#include <iostream>
#include <vector>

using namespace std;

// Funkcja pomocnicza do scalania dwóch posortowanych części
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Tworzenie tymczasowych tablic
    vector<int> L(n1);
    vector<int> R(n2);

    // Kopiowanie danych do tablic pomocniczych
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Scalanie tymczasowych tablic z powrotem do arr[]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozostałych elementów L[], jeśli są
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Kopiowanie pozostałych elementów R[], jeśli są
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Rekurencyjna funkcja sortująca przez scalanie
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sortowanie dwóch połówek
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Scalanie posortowanych połówek
        merge(arr, left, mid, right);
    }
}

// Funkcja pomocnicza do wypisywania tablicy
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Tablica przed sortowaniem:\n";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Tablica po sortowaniu przez scalanie:\n";
    printArray(arr);

    return 0;
}
