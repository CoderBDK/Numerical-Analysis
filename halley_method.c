#include <stdio.h>
#include <math.h>

double f(double x) {
    return x*x - 4;
}
double f_prime(double x) {
    return 2*x;
}
double f_double_prime(double x) {
    return 2;
}

void halley(double x0, double tol) {
    double x1;
    do {
        double f_val = f(x0);
        double f_prime_val = f_prime(x0);
        double f_double_prime_val = f_double_prime(x0);

        x1 = x0 - (2 * f_val) / (f_prime_val + sqrt(f_prime_val * f_prime_val - 2 * f_val * f_double_prime_val));

        if (fabs(x1 - x0) < tol) break;
        x0 = x1;
    } while (1);
    printf("Halley’s Method Root: %lf\n", x1);
}
int main() {
    double x0_halley = 1, tol_halley = 0.01;
    printf("\nApplying Halley’s Method:\n");
    halley(x0_halley, tol_halley);
    return 0;
}
