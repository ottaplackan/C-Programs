#include<stdio.h> 

int queue[5]; 
int front = -1; 
int rear = -1; 
int notExit = 1; 

void enqueue(int item) { 
if(front == -1 && rear == -1) { 
front = rear = 0; 
queue[rear] = item; 
} 
else if(((rear+1)%5) == front) { 
printf("Queue Overflow"); 
} 
else { 
rear = (rear+1)%5; 
queue[rear] = item; 
} 
} 

void dequeue() { 
if(front == -1 && rear == -1) { 
printf("\nQueue is Empty\n"); 
} 
else if(front == rear) { 
front = rear = -1; 
} 
else { 
printf("\nDeleted item is: %d\n",queue[front]); 
front = (front+1)%5; 
} 
} 

void display() { 
int i = front; 
if(front == -1 && rear == -1) { 
printf("\nQueue is Empty\n"); 
} 
else { 
printf("\nQueue is: \n"); 
while(i != rear) { 
printf("%d\t",queue[i]); 
i = (i+1)%5; 
} 
printf("%d",queue[rear]); 
} 
} 

void main() { 
while(notExit == 1) { 
int opt, item; 
printf("\nEnter the operator: \n"); 
printf("1. Insert\n2. Delete\n3. Print\n4. Exit\n"); 
scanf("%d", &opt); 
switch(opt) { 
case 1: 
printf("Enter the element to insert: "); 
scanf("%d", &item); 
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
printf("Enter valid operator"); 
} 
}
} 
