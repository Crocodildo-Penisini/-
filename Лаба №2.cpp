#include <iostream>
#include <fstream>
using namespace std;

void delMemory(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

double calculateY(double x, int n) {
    if (x <= 0) {
        double sumResult = 0;
        for (int i = 2; i <= n - 1; i++) {
            sumResult += (x - 1) / i;
        }
        return sumResult;
    }
    else {
        double productResult = 1.0;
        for (int i = 0; i <= n - 1; i++) {
            double sum = 0.0;
            for (int j = 0; j <= i; j++) {
                sum += (i + 1.0) / (j + x);
            }
            productResult *= sum;
        }
        return productResult;
    }
}

int main() {
    int rows, cols;

    ifstream inFile("input.txt");
    if (!inFile) {
        cout << "Could not open input.txt" << endl;
        return 1;
    }

    inFile >> rows >> cols;

    int n;
    cout << "Input value of n: ";
    cin >> n;

    if (n <= 0) {
        cerr << "Invalid value of n" << endl;
        return 1;
    }

    double** result = new double* [rows];
    for (int i = 0; i < rows; i++) {
        result[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            double x;
            if (!(inFile >> x)) {
                cerr << "Not enough x values in input.txt" << endl;
                return 1;
            }
            result[i][j] = calculateY(x, n);
        }
    }

    inFile.close();

    ofstream outFile("output.txt");
    if (!outFile) {
        cout << "Could not open output.txt for writing" << endl;
        delMemory(result, rows);
        return 1;
    }

    cout << "\nOutput of the second array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << result[i][j] << " ";
            outFile << result[i][j] << " ";
        }
        cout << "\n";
        outFile << "\n";
    }

    outFile.close();
    delMemory(result, rows);
    return 0;
}
