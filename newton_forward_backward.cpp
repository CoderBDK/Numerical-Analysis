#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void forwardDifferenceTable(vector<vector<double>>& diffTable, vector<double>& x, vector<double>& y, int n) {
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }
}

double newtonForwardInterpolation(vector<double>& x, vector<double>& y, int n, double value) {
    vector<vector<double>> diffTable(n, vector<double>(n, 0));
    forwardDifferenceTable(diffTable, x, y, n);

    double result = y[0];
    double h = x[1] - x[0];
    double u = (value - x[0]) / h;
    double term = u;

    for (int i = 1; i < n; i++) {
        result += (term * diffTable[0][i]) / tgamma(i + 1);
        term *= (u - i);
    }
    return result;
}


void backwardDifferenceTable(vector<vector<double>>& diffTable, vector<double>& x, vector<double>& y, int n) {
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];
        }
    }
}

double newtonBackwardInterpolation(vector<double>& x, vector<double>& y, int n, double value) {
    vector<vector<double>> diffTable(n, vector<double>(n, 0));
    backwardDifferenceTable(diffTable, x, y, n);

    double result = y[n - 1];
    double h = x[1] - x[0];
    double u = (value - x[n - 1]) / h;
    double term = u;

    for (int i = 1; i < n; i++) {
        result += (term * diffTable[n - 1][i]) / tgamma(i + 1);
        term *= (u + i);
    }
    return result;
}

int main() {
    int n = 5;
    vector<double> x = {10, 20, 30, 40, 50};
    vector<double> y = {75, 85, 95, 105, 115};

    double value = 35;
    cout << "Forward Interpolation Result at x = " << value << ": "
         << newtonForwardInterpolation(x, y, n, value) << endl;

    double valueBackward = 25;
    cout << "Backward Interpolation Result at x = " << valueBackward << ": "
         << newtonBackwardInterpolation(x, y, n, valueBackward) << endl;

    return 0;
}
