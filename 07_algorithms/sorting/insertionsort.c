#include <stdio.h>
void insertionsort(int a[], int n);
int main()
{
 int x[50], n, i;
 printf("Enter the size of the list: ");
 scanf("%d", &n);
 printf("Enter elements:\n");
 for(i = 0; i < n; i++)
 {
 scanf("%d", &x[i]);
 }
 insertionsort(x, n);
 printf("After sorting elements are:\n");
 for(i = 0; i < n; i++)
 {
 printf("%d ", x[i]);
 }
 return 0;
}
void insertionsort(int a[], int n)
{
 int i, j, temp;
 for(i = 1; i < n; i++)
 {
 temp = a[i];
 j = i - 1;

 while((j >= 0) && (a[j] > temp))
 {
 a[j + 1] = a[j];
 j--;
 }
 a[j + 1] = temp;
 }
}