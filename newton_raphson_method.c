#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x - 4;
}
double f_prime(double x) {
    return 2*x;
}
void newton_raphson(double x0, double tol) {
    double x1;
    do {
        x1 = x0 - f(x0) / f_prime(x0);
        if (fabs(x1 - x0) < tol) break;
        x0 = x1;
    } while (1);
    printf("Root: %lf\n", x1);
}

int main() {
  
    double a = 0, b = 3, tol = 0.01;
    printf("Newton-Raphson Method:\n");
    newton_raphson(1, tol);
  
    return 0;
}
