#include <iostream>
#include "output_table.h"

using namespace std;

double calculateY(double x, int n) {
    if (x <= 0) {
        double sum = 0;
        for (int i = 2; i <= n - 1; ++i) {
            sum += (x - 1) / i;
        }
        return sum;
    }
    else {
        double product = 1.0;
        for (int i = 0; i <= n - 1; ++i) {
            double innerSum = 0.0;
            for (int j = 0; j <= i; ++j) {
                innerSum += (i + 1) / (j + x);
            }
            product *= innerSum;
        }
        return product;
    }
}

double squareX(double x, int n) {
    return x * x + n;
}

int main() {
    double start, end, step;
    int n;

    cout << "Enter start, end, step, and n: ";
    cin >> start >> end >> step >> n;

    cout << "\nTable for calculateY:" << endl;
    outputTable(start, end, step, n, calculateY);

    cout << "\nTable for squareX:" << endl;
    outputTable(start, end, step, n, squareX);

    return 0;
}
