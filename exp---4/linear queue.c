#include <stdio.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;

void insert(int x) {
    if (rear == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    queue[rear++] = x;
}

int delete() {
    if (front == rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void traverse() {
    if (front == rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i < rear; i++)
        printf("%d ", queue[i]);
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