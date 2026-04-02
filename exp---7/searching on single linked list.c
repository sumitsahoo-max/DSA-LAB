#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_pos() {
    struct node *temp, *ptr;
    int x, pos, i;

    printf("Enter value and position: ");
    scanf("%d%d", &x, &pos);

    temp = (struct node*)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    temp->data = x;

    if (pos == 1) {
        temp->next = head;
        head = temp;
        return;
    }

    ptr = head;
    for (i = 1; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->next;

    if (ptr == NULL) {
        printf("Invalid position\n");
        free(temp);
        return;
    }

    temp->next = ptr->next;
    ptr->next = temp;
}

void search() {
    struct node *temp = head;
    int key, pos = 1;

    printf("Enter value to search: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Not found\n");
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
        printf("\n1.Insert Position  2.Search  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert_pos(); break;
            case 2: search(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}