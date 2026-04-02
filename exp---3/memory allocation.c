#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int pno;
    char name[50];
    float cost;
};

void display(struct Product p[], int n) {
    for (int i = 0; i < n; i++)
        if (p[i].cost >= 100 && p[i].cost <= 1000)
            printf("%d %s %.2f\n", p[i].pno, p[i].name, p[i].cost);
}

int main() {
    struct Product *p;
    int n;

    printf("Enter number of products: ");
    scanf("%d", &n);

    p = (struct Product *)malloc(n * sizeof(struct Product));

    // Check memory allocation
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter product number: ");
        scanf("%d", &p[i].pno);

        getchar(); // clear newline

        printf("Enter product name: ");
        fgets(p[i].name, 50, stdin);
        p[i].name[strcspn(p[i].name, "\n")] = 0;

        printf("Enter cost: ");
        scanf("%f", &p[i].cost);
    }

    printf("\nProducts with cost between 100 and 1000:\n");
    display(p, n);

    free(p);
    return 0;
}