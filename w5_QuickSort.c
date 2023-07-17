#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[10000];
void quicksort(int first,int last){
   int i, j, pivot, temp;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(a[i]<=a[pivot]&&i<last)
         i++;
         while(a[j]>a[pivot])
         j--;
         if(i<j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }
      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(first,j-1);
      quicksort(j+1,last);
   }
}
int main(){
   int i, n;
   clock_t start, end;
   printf("Enter number of elements\n");
   scanf("%d",&n);
   for(i=0;i<n;i++){
   	a[i]=rand()%100;
   } 
   printf("Before sorting\n");
   for(i=0;i<n;i++){
   	printf("%d\t",a[i]);
   }
   start = clock();   
   quicksort(0,n-1);
   end = clock(); 
   printf("\nAfter sorting\n");
   for(i=0;i<n;i++)
   	printf("%d\t",a[i]);
   printf("\nTime = %f\n", ((double)(end-start))/CLOCKS_PER_SEC);
   return 0;
}
