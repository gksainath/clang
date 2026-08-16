#include<stdio.h>
#include<string.h>
int main()
{
char s1[25], s2[25];
int x;
printf("\nEnter a string :");
gets(s1);
printf("\nEnter another string :");
gets(s2);
x=strcmp(s1, s2);
if(x == 0)
puts("Two strings are equal");
else
puts("Two strings are not equal");
return 0;
}