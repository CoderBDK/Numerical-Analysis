#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x - 4;
}
void secant(double x0, double x1, double tol) {
    double x2;
    do {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        if (fabs(x2 - x1) < tol) break;
        x0 = x1;
        x1 = x2;
    } while (1);
    printf("Secant Method Root: %lf\n", x2);
}

int main() {
    double x0_secant = 1, x1_secant = 3, tol_secant = 0.01;
    printf("Applying Secant Method:\n");
    secant(x0_secant, x1_secant, tol_secant);
    return 0;
}
