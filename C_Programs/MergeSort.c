#include<stdio.h> 
#define MAX 20 

void mergeSort(int arr[],int low,int mid,int high) { 
int i,m,k,l,temp[MAX]; 
l=low; 
i=low; 
m=mid+1; 
while((l<=mid)&&(m<=high)) { // merging two sorted arrays 
if(arr[l]<=arr[m]) { 
temp[i]=arr[l]; 
l++; 
} 
else { 
temp[i]=arr[m]; 
m++; 
} 
i++;
} 
if(l>mid) {
for(k=m;k<=high;k++) { 
temp[i]=arr[k]; 
i++; 
}
} 
else {
for(k=l;k<=mid;k++) 
{temp[i]=arr[k]; 
i++; 
}
} 
for(k=low;k<=high;k++) {
arr[k]=temp[k]; 
} 
} 

void partition(int arr[],int low,int high) {
int mid; 
if(low<high) {
mid=(low+high)/2; 
partition(arr,low,mid); 
partition(arr,mid+1,high); 
mergeSort(arr,low,mid,high); 
} 
} 

void main() { 
int ar[MAX], i,n; 
printf("Enter number of elements:"); 
scanf("%d",&n); 
printf("Enter elements:");
for(i=0;i<n;i++) 
scanf("%d",&ar[i]); 
partition(ar,0,n-1); 
printf("Sorted array is :"); 
for(i=0;i<n;i++) 
printf("%d ",ar[i]); 
} 
