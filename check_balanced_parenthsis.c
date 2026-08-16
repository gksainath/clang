#include <stdio.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    char expression[MAX];
    int i, balanced = 1;

    printf("Enter expression: ");
    scanf("%s", expression);

    for (i = 0; expression[i] != '\0'; i++) {

        if (expression[i] == '(' ||
            expression[i] == '{' ||
            expression[i] == '[') {

            push(expression[i]);
        }

        else if (expression[i] == ')' ||
                 expression[i] == '}' ||
                 expression[i] == ']') {

            if (top == -1 ||
                !isMatching(pop(), expression[i])) {

                balanced = 0;
                break;
            }
        }
    }

    if (top != -1)
        balanced = 0;

    if (balanced)
        printf("Balanced parentheses\n");
    else
        printf("Not balanced\n");

    return 0;
}