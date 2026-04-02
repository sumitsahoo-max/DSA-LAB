#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    char team[50];
    float avg;
    struct node *next;
};

struct node *head = NULL;

void create(int n) {
    struct node *temp, *ptr;
    int i;

    for (i = 0; i < n; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter player name: ");
        getchar();  // clear buffer
        fgets(temp->name, 50, stdin);
        temp->name[strcspn(temp->name, "\n")] = 0;

        printf("Enter team name: ");
        fgets(temp->team, 50, stdin);
        temp->team[strcspn(temp->team, "\n")] = 0;

        printf("Enter batting average: ");
        scanf("%f", &temp->avg);

        temp->next = NULL;

        if (head == NULL)
            head = temp;
        else {
            ptr = head;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = temp;
        }
    }
}

void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("No players available\n");
        return;
    }

    printf("\nPlayers with batting average >= 50:\n");

    while (temp != NULL) {
        if (temp->avg >= 50)
            printf("%s | %s | %.2f\n", temp->name, temp->team, temp->avg);
        temp = temp->next;
    }
}

int main() {
    int n;

    printf("Enter number of players: ");
    scanf("%d", &n);

    create(n);
    display();

    return 0;
}