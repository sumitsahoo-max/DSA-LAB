#include <stdio.h>

#define MAX 5

int cq[MAX], front = -1, rear = -1;

void insert(int x) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;

    cq[rear] = x;
}

int delete() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    int val = cq[front];

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;

    return val;
}

void traverse() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch, x, val;

    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            insert(x);
        }
        else if (ch == 2) {
            val = delete();
            if (val != -1)
                printf("Deleted: %d\n", val);
        }
        else if (ch == 3) {
            traverse();
        }
        else {
            break;
        }
    }

    return 0;
}