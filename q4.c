#include <stdio.h>

int main() {
    int arr[3][3][3];
    int i, j, l;
    int sum[3];
    int grandTotal = 0, max, min, maxLayer;
    float average;

    printf("Input for the Matrix:\n");
    for (l = 0; l < 3; l++) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("Layer %d, Row %d, Col %d: ", l + 1, i, j);
                scanf("%d", &arr[l][i][j]);
            }
        }
    }

    printf("\nMatrix Layers:\n");
    for (l = 0; l < 3; l++) {
        printf("\nLayer %d:\n", l + 1);
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%d \t", arr[l][i][j]);
            }
            printf("\n");
        }
    }

    printf("\nLayer-wise Totals:\n");
    for (l = 0; l < 3; l++) {
        sum[l] = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                sum[l] += arr[l][i][j];
            }
        }
        printf("Layer %d total: %d\n", l + 1, sum[l]);
    }

    for (l = 0; l < 3; l++) {
        grandTotal += sum[l];
    }

    max = arr[0][0][0];
    min = arr[0][0][0];
    for (l = 0; l < 3; l++) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (arr[l][i][j] > max) max = arr[l][i][j];
                if (arr[l][i][j] < min) min = arr[l][i][j];
            }
        }
    }

    average = (float)grandTotal / 27;

    maxLayer = 0;
    for (l = 1; l < 3; l++) {
        if (sum[l] > sum[maxLayer]) maxLayer = l;
    }

    printf("\nOverall Insights:\n");
    printf("Grand Total: %d\n", grandTotal);
    printf("Average: %.2f\n", average);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Layer with highest total: Layer %d (%d)\n", maxLayer + 1, sum[maxLayer]);

    return 0;
}
