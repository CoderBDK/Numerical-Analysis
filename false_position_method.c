#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x - 4;
}

void false_position(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) { printf("False position method fails.\n"); return; }
    double c;
    while ((b - a) >= tol) {
        c = b - (f(b) * (b - a)) / (f(b) - f(a));
        if (f(c) == 0.0) break;
        else if (f(c) * f(a) < 0) b = c;
        else a = c;
    }
    printf("Root: %lf\n", c);
}

int main() {
    
    double a = 0, b = 3, tol = 0.01;
    printf("False Position Method:\n");
    false_position(a, b, tol);

    return 0;
}
