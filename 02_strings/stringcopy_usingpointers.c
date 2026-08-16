#include <stdio.h>

int main() {
    char source[100], destination[100];
    char *p, *q;

    printf("Enter a string: ");
    scanf("%s", source);

    p = source;
    q = destination;

    while (*p != '\0') {
        *q = *p;
        p++;
        q++;
    }

    *q = '\0';

    printf("Copied string: %s\n", destination);

    return 0;
}