#include <stdio.h>
void bubblesort(int a[], int n);
int main()
{
 int a[50], n, i;
 printf("Enter size of the list: ");
 scanf("%d", &n);
 printf("Enter elements:\n");
 for (i = 0; i < n; i++)
 {
 scanf("%d", &a[i]);
 }
 bubblesort(a, n);
 printf("After sorting, list of elements are:\n");
 for (i = 0; i < n; i++)
 {
 printf("%d ", a[i]);
 }
 return 0;
}
void bubblesort(int a[], int n)
{
 int i, j, temp;
 for (i = 0; i < n - 1; i++)
 {
 for (j = 0; j < n - i - 1; j++)
 {
 if (a[j] > a[j + 1])
 {
 temp = a[j];
 a[j] = a[j + 1];
 a[j + 1] = temp;
 }
 }
 }
}