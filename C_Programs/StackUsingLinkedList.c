#include<stdio.h> 
#include<stdlib.h> 

struct node { 
int data; 
struct node *addr; 
}; 

struct node *top = NULL; 
int notExit = 1; 
struct node *createnode(int item); 
void push(struct node *nn); 
void display(); 
void pop(); 

struct node *createnode(int item) { 
struct node *nn; 
nn = (struct node*)malloc(sizeof(struct node)); 
nn->data = item; 
return nn; 
} 

void push(struct node *nn) { 
int item; 
printf("Enter the element: "); 
scanf("%d",&item); 
nn = createnode(item); 
if(top == NULL) { 
nn->addr = NULL; 
top = nn; 
} 
else { 
nn->addr = top; 
top = nn; 
} 
display(); 
} 

void pop() { 
if(top == NULL) { 
printf("\nStack is Empty!"); 
} 
else { 
struct node *p=top; 
printf("\n%d is deleted!",p->data); 
p=p->addr; 
top=p; 
display(); 
} 
}

void display() { 
if(top == NULL) { 
printf("\nStack is Empty!\n"); 
} 
else { 
struct node *p=top; 
printf("\nStack: "); 
while(p->addr != NULL) { 
printf("%d ",p->data); 
p=p->addr; 
} 
printf("%d\n",p->data); 
} 
} 

void main() { 
int opt; 
struct node *nn; 
while(notExit == 1) { 
printf("\n1. Push \n2. Pop \n3. Display \n4. Exit."); 
printf("\nEnter the operator: "); 
scanf("%d",&opt); 
switch(opt) { 
case 1: 
push(nn); 
break; 
case 2: 
pop(); 
break; 
case 3: 
display(); 
case 4: 
notExit=0; 
printf("Exited!"); 
break; 
default: 
printf("Enter a valid operator!"); 
} 
} 
}
