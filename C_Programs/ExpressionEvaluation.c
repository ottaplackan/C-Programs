#include<stdio.h> 

int stack[20]; 
top=-1; 

void push(int x) { 
top++; 
stack[top]=x; 
} 

int pop() { 
int x=stack[top]; 
top--; 
return x; 
} 

void main() { 
char exp[30]; 
int i,j,k; 
printf("Enter the postfix expression: "); 
fflush(stdout); 
gets(exp); 
for(i=0;exp[i]!='\0';i++) { 
if(isalpha(exp[i])) { 
printf("Enter the value of %c: ",exp[i]); 
scanf("%d",&j); 
push(j); 
} 
else { 
j=pop(); 
k=pop(); 
switch(exp[i]) { 
case '+': push(j+k); 
break; 
case '-': push(k-j); 
break; 
case '*': push(k*j); 
break; 
case '/': push(k/j); 
break; 
} 
} 
} 
j=pop(); 
printf("The result is %d",j); 
fflush(stdout); 
} 
