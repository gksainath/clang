#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, passMark, i;
    int *marks;

    printf("Enter number of students: ");
    scanf("%d", &n);

    marks = (int *)calloc(n, sizeof(int));

    if (marks == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter pass mark: ");
    scanf("%d", &passMark);

    for (i = 0; i < n; i++) {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%d", &marks[i]);
    }

    printf("Failed students:\n");

    for (i = 0; i < n; i++) {
        if (marks[i] < passMark)
            printf("Student %d: %d\n", i + 1, marks[i]);
    }

    free(marks);

    return 0;
}