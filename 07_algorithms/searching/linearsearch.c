#include <stdio.h>
int linearsearch(int a[], int n, int ele);
int main()
{
 int a[50], n, se, pos, i;
 printf("Enter the size of the list: ");
 scanf("%d", &n);
 printf("Enter elements:\n");
 for (i = 0; i < n; i++)
 {
 scanf("%d", &a[i]);
 }
 printf("Enter searching element: ");
 scanf("%d", &se);
 pos = linearsearch(a, n, se);
 if (pos != -1)
 printf("Element %d is found at position %d", se, pos + 1);
 else
 printf("Element is not found");
 return 0;
}
int linearsearch(int a[], int n, int ele)
{
 int i;
 for (i = 0; i < n; i++)
 {
 if (ele == a[i])
 return i;
 }
 return -1;
}