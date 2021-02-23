#include<stdio.h> 

int queue[5]; 
int front = -1; 
int rear = -1; 
int notExit = 1; 

void enqueue(int item) { 
if(rear == 4) { 
printf("\nQueue Overflow\n"); 
} 
else if(front == -1 && rear == -1) { 
front = rear = 0; 
queue[rear] = item; 
} 
else { 
rear++; 
queue[rear] = item; 
}
} 

void dequeue() { 
if(front == -1 && rear == -1) { 
printf("Queue is Empty\n"); 
} 
else if(front == rear) { 
printf("Deleted item is: %d\n",queue[front]); 
front = rear =-1; 
} 
else { 
printf("Deleted item is: %d\n",queue[front]); 
front++; 
} 
} 

void display() { 
if(front == -1 && rear == -1) { 
printf("Queue is Empty\n"); 
} 
else { 
for(int i=front; i<rear+1; i++) { 
printf("%d\t", queue[i]); 
} 
} 
} 

void main() { 
while(notExit == 1) { 
int opt, item; 
printf("\nEnter the option:\n"); 
printf("1. Insert\n2. Delete\n3. Print\n4. Exit\n"); 
scanf("%d",&opt); 
switch(opt) { 
case 1: 
printf("Enter the item to insert: "); 
scanf("%d",&item); 
enqueue(item); 
break; 
case 2: 
dequeue(); 
break; 
case 3: 
display(); 
break; 
case 4: 
notExit = 0; 
printf("\nExited"); 
break; 
default: 
printf("Enter a valid operator"); 
} 
} 
} 
