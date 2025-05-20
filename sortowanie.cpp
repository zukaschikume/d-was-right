#include <iostream>
using namespace std;
 
void merge(int tab[], int l, int m, int r) {
    // K1: lSize ← m - l + 1
    int lSize = m - l + 1;
 
    int rSize = r - m;
 
    //Tablice pomocnicze
    int* tabL = new int[lSize];
    int* tabR = new int[rSize];
 
    //Kopiowanie danych do tablicy pomocniczej tabL
    for (int x = 0; x < lSize; x++) {
        tabL[x] = tab[l + x];
    }
 
      //Kopiowanie danych do tablicy pomocniczej tabR
    for (int y = 0; y < rSize; y++) {
        tabR[y] = tab[m + 1 + y];
    }
 
    // Inicjalizacja indeksów
    int indexL = 0;
    int indexR = 0;
    int currIndex = l;
 
    // Scalanie tabL i tabR z powrotem do tab[]
    while (indexL < lSize && indexR < rSize) {
        if (tabL[indexL] <= tabR[indexR]) {
            tab[currIndex] = tabL[indexL];
            indexL++;
        } else {
            tab[currIndex] = tabR[indexR];
            indexR++;
        }
        currIndex++;
    }
 
    // Kopiowanie pozostałości z tabL (jeśli są)
    while (indexL < lSize) {
        tab[currIndex++] = tabL[indexL++];
    }
 
    // K14: Kopiowanie pozostałości z tabR (jeśli są)
    while (indexR < rSize) {
        tab[currIndex++] = tabR[indexR++];
    }
 
    // Zwolnienie pamięci
    delete[] tabL;
    delete[] tabR;
}
 
// Funkcja rekurencyjna sortująca tablicę
void mergeSort(int tab[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        // Sortowanie lewej i prawej części
        mergeSort(tab, l, m);
        mergeSort(tab, m + 1, r);
 
        // Scalanie posortowanych części
        merge(tab, l, m, r);
    }
}
 

int main() {
    int tab[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(tab) / sizeof(tab[0]);
 
    cout << "Przed sortowaniem:\n";
    for (int i = 0; i < size; i++) {
        cout << tab[i] << " ";
    }
    cout << "\n";
 
    mergeSort(tab, 0, size - 1);
 
    cout << "Po sortowaniu:\n";
    for (int i = 0; i < size; i++) {
        cout << tab[i] << " ";
    }
    cout << "\n";
 
    return 0;
}
