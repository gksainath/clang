#include <stdio.h>

int main() {
    int a[20], b[20], sum[20], diff[20];
    int n1, n2, max, i;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &n1);

    printf("Enter coefficients of first polynomial:\n");
    for (i = n1; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter degree of second polynomial: ");
    scanf("%d", &n2);

    printf("Enter coefficients of second polynomial:\n");
    for (i = n2; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &b[i]);
    }

    max = n1 > n2 ? n1 : n2;

    for (i = 0; i <= max; i++) {
        sum[i] = a[i] + b[i];
        diff[i] = a[i] - b[i];
    }

    printf("\nAddition: ");

    for (i = max; i >= 0; i--) {
        if (sum[i] != 0) {
            if (i == 0)
                printf("%d", sum[i]);
            else
                printf("%dx^%d ", sum[i], i);
        }
    }

    printf("\nSubtraction: ");

    for (i = max; i >= 0; i--) {
        if (diff[i] != 0) {
            if (i == 0)
                printf("%d", diff[i]);
            else
                printf("%dx^%d ", diff[i], i);
        }
    }

    printf("\n");

    return 0;
}