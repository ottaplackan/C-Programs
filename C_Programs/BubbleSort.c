#include<stdio.h> 

void bubble_sort(int ar[], int n) { 
int temp; 
for(int i=0;i<n;i++ ) { 
for(int j=0;j<n-i-1;j++) { 
if(ar[j] > ar[j+1]) { 
temp = ar[j]; 
ar[j] = ar[j+1]; 
ar[j+1] = temp; 
} 
} 
for(int k=0;k<n;k++) { 
printf("%d ",ar[k]); 
} 
printf("\n"); 
} 
} 

void main() { 
int ar[20],n; 
printf("Enter the number of items in the array: "); 
scanf("%d",&n); 
printf("Enter the items in the array: "); 
for(int i=0;i<n;i++) { 
scanf("%d",&ar[i]); 
} 
bubble_sort(ar, n); 
} 
