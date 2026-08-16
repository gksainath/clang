#include<stdio.h>
void selectionsort(int a[], int n);
int smallest(int a[], int n, int k);
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
 selectionsort(x, n);
 printf("After sorting elements are:\n");
 for(i = 0; i < n; i++)
 {
 printf("%d ", x[i]);
 }
 return 0;
}
void selectionsort(int a[], int n)
{
 int pos, i, temp;
 for(i = 0; i < n - 1; i++)
 {
 pos = smallest(a, n, i);
 temp = a[i];
 a[i] = a[pos];
 a[pos] = temp;
 }
}
int smallest(int a[], int n, int k)
{
 int i, pos = k, small = a[k];
 for(i = k + 1; i < n; i++)
 {
 if(a[i] < small)
 {
 small = a[i];
 pos = i;
 }
 }
 return pos;