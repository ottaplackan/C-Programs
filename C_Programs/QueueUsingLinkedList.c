#include<stdio.h> 
#include<stdlib.h> 

struct node { 
int data; 
struct node *addr; 
}; 

struct node *front=NULL,*rear=NULL; 
int notExit = 1; 
struct node *createnode(int item); 
void enqueue(); 
void dequeue(); 
void display_queue(); 

struct node *createnode(int item) { 
struct node *nn; 
nn = (struct node*)malloc(sizeof(struct node)); 
nn->data = item; 
return nn; 
} 

void enqueue() { 
int item; 
struct node *nn; 
printf("Enter the element: "); 
scanf("%d",&item); 
nn = createnode(item); 
if(front == NULL) { 
front=nn; 
}
else { 
rear=front; 
while(rear->addr != NULL) { 
rear=rear->addr; 
} 
rear->addr=nn; 
} 
display_queue(); 
} 

void dequeue() { 
if(front == NULL) { 
printf("\nQueue is Empty!"); 
} 
else { 
printf("\n%d is deleted!",front->data); 
front=front->addr; 
display_queue(); 
} 
} 

void display_queue() { 
if(front == NULL) { 
printf("\nQueue is Empty!"); 
} 
else { 
rear=front; 
printf("\nQueue: "); 
while(rear != NULL) { 
printf("%d ",rear->data); 
rear=rear->addr; 
} 
} 
} 

void main() { 
int opt; 
while(notExit == 1) { 
printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit.\n"); 
printf("Enter the operator: "); 
scanf("%d",&opt); 
switch(opt) { 
case 1: 
enqueue(); 
break; 
case 2: 
dequeue(); 
break; 
case 3: 
display_queue(); 
break; 
case 4: 
notExit=0; 
printf("\nExited!"); 
break; 
default: 
printf("\nEnter a valid operator!"); 
} 
} 
} 
