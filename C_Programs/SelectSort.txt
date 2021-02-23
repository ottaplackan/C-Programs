#include<stdio.h> 

void selection_sort(int arr[], int n) { 
int min_index, temp, i, j; 
for(i=0;i<n-1;i++) { 
min_index = i; 
for(j=i+1;j<n;j++) { 
if(arr[j] < arr[min_index]) { 
min_index = j; 
} 
} 
temp = arr[min_index]; 
arr[min_index] = arr[i]; 
arr[i] = temp; 
} 
printf("\nThe sorted array is: "); 
for(int k=0;k<n;k++) { 
printf("%d ",arr[k]); 
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
selection_sort(ar, n); 
} 
