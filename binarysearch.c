#include <stdio.h>
int binarysearch(int x[], int n, int ele);
int main()
{
 int a[50], n, se, i, pos;
printf("Enter the size of the list: ");
 scanf("%d", &n);
 printf("Enter elements in sorted order:\n");
 for (i = 0; i < n; i++)
 {
 scanf("%d", &a[i]);
 }
 printf("Enter searching element: ");
 scanf("%d", &se);
 pos = binarysearch(a, n, se);
 if (pos != -1)
 printf("Element %d is found at position %d", se, pos + 1);
 else
 printf("Element is not found");
 return 0;
}
int binarysearch(int x[], int n, int ele)
{
 int low = 0, high = n - 1, mid;
 while (low <= high)
 {
 mid = (low + high) / 2;
 if (ele == x[mid])
 return mid;
 else if (ele > x[mid])
 low = mid + 1;
 else
 high = mid - 1;
 }
 return -1;
}