#include <stdio.h>
int main ()
{
    int i,n;
    printf("Enter the number you want multiplication table of");
    scanf("%d",&n);
    for(i=1;i<=20;i++)
    {
        printf("%d X %d = %d",n,i,n*i);
        printf("\n");
    }
    return 0;
}