#include <iostream>
#include "output_table.h"

using namespace std;

void outputTable(double start, double end, double step, int n, MathFunc func) {
    cout << "x\t\ty(x)" << endl;
    for (double x = start; x <= end; x += step) {
        cout << x << "\t" << func(x, n) << endl;
    }
}
