#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_end() {
    struct node *temp, *ptr;
    int x;

    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &x);

    temp->data = x;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        return;
    }

    ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = temp;
}

void delete_last() {
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
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
        printf("\n1.Insert End  2.Delete Last  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert_end(); break;
            case 2: delete_last(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}