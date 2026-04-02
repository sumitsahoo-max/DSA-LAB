#include <stdio.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int ch, x, val;

    do {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            push(x);
        }
        else if (ch == 2) {
            val = pop();
            if (val != -1)
                printf("Popped: %d\n", val);
        }
        else if (ch == 3) {
            display();
        }

    } while (ch != 4);

    return 0;
}