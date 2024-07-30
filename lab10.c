# include <stdio.h>
# include <time.h>
#include<stdlib.h>
int a[10000],i,j,lb,ub;
void quicksort(int a[], int lb, int ub);
void main()
{
int n;
clock_t st, et;
double ts;
printf("\n Enter the number of array elements: ");
scanf("%d", &n);
printf("\nThe Random Numbers are:\n");
for(i=0; i<n; i++)
{
a[i]=rand()%100+1;
printf("%d\t",a[i]);
}
st=clock();
quicksort(a,0,n-1);
et=clock();
ts=(double)(et-st)/CLOCKS_PER_SEC;
printf("\nSorted Numbers are: \n ");
for(i=0; i<n; i++)
{
printf("%d\t", a[i]);
}
printf("\nThe time taken is %lf",ts);
}
void quicksort(int a[], int lb, int ub)
{ int mid;
 if(lb<ub)
 {
 mid = partition(a,lb,ub);
 quicksort(a,lb,mid-1);
 quicksort(a,mid+1,ub);
 }
}
int partition(int a[],int lb, int ub)
{ int i, j, pivot,temp;
 pivot = a[lb];
 i = lb;
 j = ub;
 while(i<j)
 {
 while(a[i]<=pivot)
 {
 i++;
 }
 while(a[j]>pivot)
 {
 j--;
 }
 if(i<j)
 {
 temp = a[i];
 a[i]= a[j];
 a[j] = temp;
 }
 }
 temp=a[lb];
 a[lb] = a[j];
 a[j] = temp;
 return j;
}
