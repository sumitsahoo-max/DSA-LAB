#include <stdio.h>

void merge(int A[], int B[], int C[]) {
    int i = 0, j = 0, k = 0;

    while (i < 5 && j < 5) {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    while (i < 5)
        C[k++] = A[i++];

    while (j < 5)
        C[k++] = B[j++];
}

int main() {
    int A[5], B[5], C[10];

    printf("Enter 5 sorted elements of array A:\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &A[i]);

    printf("Enter 5 sorted elements of array B:\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &B[i]);

    merge(A, B, C);

    printf("Merged array:\n");
    for (int i = 0; i < 10; i++)
        printf("%d ", C[i]);

    return 0;
}