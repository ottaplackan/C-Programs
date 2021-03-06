#include<stdio.h> 

int queue[5]; 
int rear=-1; 
int front=-1; 
int notExit = 1; 

void enqueue() { 
int item;
printf("Enter the number to insert: "); 
scanf("%d",&item); 
if(rear == 4) { 
printf("Queue overflow"); 
} 
else if(front==-1 && rear==-1) { 
front=rear = 0; 
queue[rear] = item; 
} 
else { 
int i = rear; 
while(i>=0 && queue[i]>item) { 
queue[i+1] = queue[i]; 
i--; 
} 
queue[i+1] = item; 
rear++; 
} 
return; 
} 

void dequeue() { 
if(front==-1 && rear==-1) { 
printf("Queue is empty!"); 
} 
else if(front == rear) { 
int item = queue[front]; 
printf("%d is deleted from queue",item); 
front=rear = -1; 
} 
else { 
int item = queue[rear]; 
printf("%d is deleted from queue",item); 
rear--; 
} 
} 

void display_queue() { 
if(front==-1 && rear==-1) { 
printf("Queue is empty!"); 
} 
else { 
printf("Queue: "); 
for(int i=rear;i>=front;i--) { 
printf("%d\t",queue[i]); 
} 
printf("\n"); 
} 
} 

void main() { 
while(notExit == 1) { 
int opt; 
printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit"); 
printf("\nEnter the operation you want to Perform: "); 
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
printf("Exited"); 
break; 
default: 
printf("Enter a valid operation!"); 
} 
} 
} 
