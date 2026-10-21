#include <stdio.h>

int main() {
    int matrix1[3][3], matrix2[3][3], matrix3[3][3];
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter the number of rows for matrix 1: ");
    scanf("%d", &r1);
    printf("Enter the number of cols for matrix 1: ");
    scanf("%d", &c1);
    printf("Enter the number of rows for matrix 2: ");
    scanf("%d", &r2);
    printf("Enter the number of cols for matrix 2: ");
    scanf("%d", &c2);

    if (r1 < 1 || r1 > 3 || c1 < 1 || c1 > 3 ||
        r2 < 1 || r2 > 3 || c2 < 1 || c2 > 3) {
        printf("Rows and columns must be between 1 and 3.\n");
        return 0;
    }

    if (c1 != r2) {
        printf("Multiplication not possible: cols of matrix 1 must equal rows of matrix 2.\n");
        return 0;
    }

    printf("\nEnter elements of matrix 1:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("\nEnter elements of matrix 2:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            matrix3[i][j] = 0;
            for (k = 0; k < c1; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("\nMatrix 1 (%dx%d):\n", r1, c1);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("%d \t", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2 (%dx%d):\n", r2, c2);
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d \t", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("\nResult Matrix (%dx%d):\n", r1, c2);
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d \t", matrix3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
