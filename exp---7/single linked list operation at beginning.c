#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begin() {
    struct node *temp;
    int x;

    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &x);

    temp->data = x;
    temp->next = head;
    head = temp;
}

void delete_first() {
    struct node *temp;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch;

    while (1) {
        printf("\n1.Insert Beginning  2.Delete First  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert_begin(); break;
            case 2: delete_first(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}