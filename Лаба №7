#include <iostream>
#include <time.h>
#include<cstdlib>
#include <ctime>
#define N 135000
using namespace std;

void heapify(int arr[], int n, int i)
{

    int largest = i;

    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int partition(int arr[], int low, int high)
{
    int middle = (high + low) / 2;

    swap(arr[high], arr[middle]);

    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        const int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int* s = new int[N];
    int* a = new int[N];
    int* b = new int[N];
    srand((unsigned int)time(NULL));
    for (int i = 0; i < N; i++)
    {
        a[i] = b[i] = s[i] = 20 * N - rand() % 40 * N + 1;
    }
    cout << endl;
    unsigned int start_time = clock();
    heapSort(a, N);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    double timeInSeconds = search_time / (double)CLOCKS_PER_SEC;
    cout << "Sorting time (HeapSort) " << timeInSeconds << endl;

    start_time = clock();
    quickSort(b, 0, N - 1);
    end_time = clock();
    search_time = end_time - start_time;
    timeInSeconds = search_time / (double)CLOCKS_PER_SEC;
    cout << "Sorting time (QuickSort) " << timeInSeconds << endl;

    start_time = clock();
    mergeSort(s, 0, N - 1);
    end_time = clock();
    search_time = end_time - start_time;
    timeInSeconds = search_time / (double)CLOCKS_PER_SEC;
    cout << "Sorting time (MergeSort) " << timeInSeconds << endl;
}
