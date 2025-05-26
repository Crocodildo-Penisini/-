#include <iostream>
#include <cmath>
using namespace std;

bool readData(double& start, double& end, double& step, int& n) {
    cout << "Input start, end of interval, step and value of n: ";
    cin >> start >> end >> step >> n;
    if (start >= end || step <= 0 || n == 0) {
        cerr << "Wrong data" << endl;
        return false;
    }
    return true;
}
double calculateY(double x, int n) {
    if (x <= 0) {
        double sumResult = 0;
        for (int i = 2; i <= n - 1; i++)
        {
            sumResult += (x - 1) / i;
        }
        return sumResult;
    }
    else {
        double productResult = 1.0;
        for (int i = 0; i <= n - 1; i++) {
            double sum = 0.0;
            for (int j = 0; j <= i; j++)
                {
                    sum += (i + 1) / (j + x);
                }
            productResult *= sum;
        }
        return productResult;
    }
}
void outputData(double start, double end, double step, int n)
{
    cout << "x\ty" << endl;
    for (double x = start; x <= end; x += step)
    {
        cout << x << "\t" << calculateY(x, n) << endl;
    }
}
int main() {
    double start, end, step;
    int n;
    if (readData(start, end, step, n)) {
        outputData(start, end, step, n);
        return 0;
    }
    return -1;
}
