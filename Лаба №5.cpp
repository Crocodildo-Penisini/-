#include <iostream>
#include<time.h>
#include <cstdlib>
#include<ctime>
#define N 60000
using namespace std;

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

void shakerSort(int a[], int size) {
	int i, j;
	int lb = 1, ub = size - 1;
	int x;
	do
	{
		for (i = ub; i > 0; i--) {
			{
				if (a[i - 1] > a[i]) {
					x = a[i - 1]; a[i - 1] = a[i];
					a[i] = x;
					j = i;
				}
			}
		}
		lb = j + 1;
		for (i = 1; i <= ub; i++) {
			if (a[i - 1] > a[i]) {
				x = a[i - 1]; a[i - 1] = a[i];
				a[i] = x;
				j = i;
			}
		}

		ub = j - 1;
	} while (lb < ub);

}

int main() {
	int s[N], a[N], b[N], c[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		s[i] = a[i] = b[i] = c[i] = 20 * N - rand() % 40 * N + 1;

	}
	cout << endl;
	unsigned int start_time = clock();
	selectSort(a, N);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	double timeInSeconds = search_time / (double)CLOCKS_PER_SEC;
	cout << "Sorting time (SelectSort) " << timeInSeconds << endl;

	start_time = clock();
	insertSort(b, N);
	end_time = clock();
	search_time = end_time - start_time;
	timeInSeconds = search_time / (double)CLOCKS_PER_SEC;
	cout << "Sorting time (InsertSort) " << timeInSeconds << endl;

	start_time = clock();
	boobleSort(s, N);
	end_time = clock();
	search_time = end_time - start_time;
	timeInSeconds = search_time / (double)CLOCKS_PER_SEC;
	cout << "Sorting time (BubbleSort) " << timeInSeconds << endl;

	start_time = clock();
	shakerSort(c, N);
	end_time = clock();
	search_time = end_time - start_time;
	timeInSeconds = search_time / (double)CLOCKS_PER_SEC;
	cout << "Sorting time (ShakerSort) " << timeInSeconds << endl;
	return 0;
}
