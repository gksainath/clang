#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        return -1;
    }

    return stack[top--];
}

int main() {
    int n, i;
    int list[MAX];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("Invalid number of elements\n");
        return 0;
    }

    printf("Enter elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &list[i]);
        push(list[i]);
    }

    printf("Reversed list: ");

    for (i = 0; i < n; i++) {
        list[i] = pop();
        printf("%d ", list[i]);
    }

    printf("\n");

    return 0;
}