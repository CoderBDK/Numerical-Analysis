#include <stdio.h>
#include <stdlib.h>

void gauss_jordan_elimination(double A[3][3], double b[3], double x[3], int n) {
    int i, j, k;
    double temp;

    double augmented_matrix[3][4];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            augmented_matrix[i][j] = A[i][j];
        }
        augmented_matrix[i][n] = b[i];
    }


    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (augmented_matrix[i][i] < augmented_matrix[j][i]) {
                for (k = 0; k <= n; k++) {
                    temp = augmented_matrix[i][k];
                    augmented_matrix[i][k] = augmented_matrix[j][k];
                    augmented_matrix[j][k] = temp;
                }
            }
        }

        temp = augmented_matrix[i][i];
        for (k = 0; k <= n; k++) {
            augmented_matrix[i][k] /= temp;
        }

        for (j = 0; j < n; j++) {
            if (j != i) {
                temp = augmented_matrix[j][i];
                for (k = 0; k <= n; k++) {
                    augmented_matrix[j][k] -= augmented_matrix[i][k] * temp;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        x[i] = augmented_matrix[i][n];
    }
}

int main() {
    double A[3][3] = {
            {2, 3, -1},
            {4, 1, 2},
            {-2, 5, 3}
    };
    double b[3] = {1, 2, 3};
    double x[3];

    int n = 3;
    gauss_jordan_elimination(A, b, x, n);

    printf("Solution: \n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %lf\n", i + 1, x[i]);
    }

    return 0;
}
