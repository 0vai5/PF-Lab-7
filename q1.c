#include <stdio.h>

int main() {
    int matrix[3][3];
    int transpose[3][3];
    int cofactor[3][3];
    int adjoint[3][3];
    float inverse[3][3];
    int temp[2][2];
    int i, j, k, l;
    int rowTemp, colTemp;
    int determinant, minor, sign;

    printf("Enter values for a 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            transpose[i][j] = matrix[j][i];
        }
    }

    printf("\nTranspose Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d \t", transpose[i][j]);
        }
        printf("\n");
    }

    determinant = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
                - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
                + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    printf("\nDeterminant: %d\n", determinant);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            k = 0;
            l = 0;

            for (rowTemp = 0; rowTemp < 3; rowTemp++) {
                for (colTemp = 0; colTemp < 3; colTemp++) {
                    if (rowTemp != i && colTemp != j) {
                        temp[k][l] = matrix[rowTemp][colTemp];
                        l++;
                        if (l == 2) {
                            l = 0;
                            k++;
                        }
                    }
                }
            }

            minor = temp[0][0] * temp[1][1] - temp[0][1] * temp[1][0];

            if ((i + j) % 2 == 0)
                sign = 1;
            else
                sign = -1;

            cofactor[i][j] = sign * minor;
        }
    }

    printf("\nCofactor Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d \t", cofactor[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            adjoint[i][j] = cofactor[j][i];
        }
    }

    printf("\nAdjoint Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d \t", adjoint[i][j]);
        }
        printf("\n");
    }

    if (determinant == 0) {
        printf("\nInverse does not exist (determinant is 0).\n");
    } else {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                inverse[i][j] = (float)adjoint[i][j] / determinant;
            }
        }

        printf("\nInverse Matrix:\n");
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%.2f \t", inverse[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
