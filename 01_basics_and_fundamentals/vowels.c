#include <stdio.h>
int main()
{
    char vorc;
printf(" input the character\n");
scanf("%c",&vorc);
switch (vorc)
{
case 'a': case 'e': case 'i': case 'o': case 'u': case 'A': case 'E': case 'I': case 'O': case 'U':
printf("it is a vowel");
    break;

default:
 if ((vorc >= 'a' && vorc <= 'z') || (vorc >= 'A' && vorc <= 'Z'))
                printf("%c is a consonant.\n", vorc);
            else
                printf("Not an alphabet.\n");
    break;
}
return 0;
}