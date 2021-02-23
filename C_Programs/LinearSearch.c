#include<stdio.h> 

int notExit=1; 

void lSearch(int n, int ar[]) { 
int search_key; 
while(notExit == 1) { 
int flag=0; 
printf("\nEnter the search key: "); 
scanf("%d",&search_key);
for(int i=0;i<n;i++) { 
if(ar[i] == search_key) { 
printf("The element %d found at %d\n",search_key,i+1); 
flag=1; 
break; 
} 
} 
if(flag == 0) { 
printf("The element %d not found in search!\n",search_key); 
} 
}
} 

void main() { 
int limit, ar[150]; 
printf("Enter the array limit: "); 
scanf("%d",&limit); 
printf("Enter the elements of the array: \n"); 
for(int i=0;i<limit;i++) { 
scanf("%d",&ar[i]); 
} 
printf("\nThe elements are: "); 
for(int i=0;i<limit;i++) { 
printf("%d ",ar[i]); 
} 
lSearch(limit, ar); 
} 
