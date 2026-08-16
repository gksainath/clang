#include <stdio.h>

struct Student {
    int id;
    float marks;
    char grade;
};

union Data {
    int id;
    float marks;
    char grade;
};

int main() {
    struct Student s;
    union Data u;

    s.id = 101;
    s.marks = 85.5;
    s.grade = 'A';

    printf("Structure:\n");
    printf("ID: %d\n", s.id);
    printf("Marks: %.2f\n", s.marks);
    printf("Grade: %c\n", s.grade);
    printf("Size of structure: %lu\n", sizeof(s));

    u.id = 101;
    printf("\nUnion:\n");
    printf("ID: %d\n", u.id);

    u.marks = 85.5;
    printf("Marks: %.2f\n", u.marks);

    u.grade = 'A';
    printf("Grade: %c\n", u.grade);

    printf("Size of union: %lu\n", sizeof(u));

    return 0;
}