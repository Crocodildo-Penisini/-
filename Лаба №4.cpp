#include <iostream>
#include <cstdlib>
#include <time.h>
#define N 15
#define M (10*N)%51

using namespace std;

void printarray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << endl;
    }
}
void selectSort(int a[], int size) {
    int k, x;
    for (int i = 0; i < size; i++) {
        k = i; x = a[i];
        for (int j = i + 1; j < size; j++)
            if (a[j] < x) {
                k = j; x = a[j];
            }
        a[k] = a[i]; a[i] = x;
    }
}
void insertSort(int a[], int size) {
    int buff = 0;
    int i, j;
    for (int i = 0; i < size; i++) {
        buff = a[i];
        for (j = i - 1; j >= 0 && a[j] > buff; j--)
            a[j + 1] = a[j];
        a[j + 1] = buff;
    }
}
void boobleSort(int a[], int size) {
    int i, j;
    int buff = 0;
    for (i = 0; i < size - 1; i++) {
        for (j = size - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                buff = a[j];
                a[j] = a[j - 1];
                a[j - 1] = buff;
            }
        }

    }
}

int main() {
    srand(time(NULL));
    int s[M], a[M], b[M];
    for (int i = 0; i < M; i++) {
        s[i] = a[i] = b[i] = 20 * N - rand() % (40 * N + 1);

    }
    printarray(a, M);
    cout << endl;

    selectSort(a, M);
    cout << "selectSort" << endl;
    printarray(a, M);
    insertSort(b, M);
    cout << "insertSort" << endl;
    printarray(b, M);
    boobleSort(s, M);
    cout << "boobleSort" << endl;
    printarray(s, M);

    return 0;
}
