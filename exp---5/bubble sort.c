#include <stdio.h>
#include <string.h>

void bubble(char s[]) {
    int n = strlen(s), i, j;
    char temp;

    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (s[j] > s[j + 1]) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
}

int main() {
    char s[100];

    printf("Enter a string: ");
    scanf("%s", s);

    bubble(s);

    printf("Sorted string: %s\n", s);

    return 0;
}