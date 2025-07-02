#include <stdio.h>

int main() {
    int r, c, i, j;
    int mat1[100][100], mat2[100][100], sum[100][100];

    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    printf("Sum of the matrices:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}
