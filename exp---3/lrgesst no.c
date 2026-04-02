#include <stdio.h>
#include <stdlib.h>

int largest(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int main() {
    int *a, n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    // Check if memory allocation failed
    if (a == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Largest element: %d\n", largest(a, n));

    free(a);
    return 0;
}