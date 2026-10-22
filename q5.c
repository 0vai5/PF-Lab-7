#include <stdio.h>

int main() {
    int arr[3][3][3];
    int i, j, l;
    int a, b, same;
    int count = 0;

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

    printf("\nLayer Comparison:\n");
    for (a = 0; a < 2; a++) {
        for (b = a + 1; b < 3; b++) {

            same = 1;

            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (arr[a][i][j] != arr[b][i][j]) {
                        same = 0;
                    }
                }
            }

            if (same == 1) {
                printf("Layer %d and Layer %d are IDENTICAL\n", a + 1, b + 1);
                count++;
            } else {
                printf("Layer %d and Layer %d are DISTINCT\n", a + 1, b + 1);
            }
        }
    }

    printf("\nIdentical pairs: %d out of 3\n", count);

    if (count == 3)
        printf("All layers are identical.\n");
    else if (count == 0)
        printf("All layers are distinct.\n");
    else
        printf("Some layers are identical.\n");

    return 0;
}
