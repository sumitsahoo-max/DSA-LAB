#include <stdio.h>

int isSparse(int a[4][4]) {
    int z = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (a[i][j] == 0)
                z++;
    return z > 8;
}

void store(int a[4][4], int b[][2], int *c) {
    *c = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (a[i][j] != 0) {
                b[*c][0] = i;
                b[*c][1] = j;
                (*c)++;
            }
}

void disp(int b[][2], int c) {
    for (int i = 0; i < c; i++)
        printf("%d %d\n", b[i][0], b[i][1]);
}

int main() {
    int a[4][4], b[16][2], c;

    printf("Enter 4x4 matrix elements:\n");
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);

    if (isSparse(a)) {
        printf("Sparse matrix (row, column of non-zero elements):\n");
        store(a, b, &c);
        disp(b, c);
    } else {
        printf("Not a sparse matrix\n");
    }

    return 0;
}