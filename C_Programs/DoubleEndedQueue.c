#include<stdio.h> 

int rear=-1, front=-1; 
int queue[5]; 
int notExit = 1; 

void enqueue_rear() { 
if(rear == 4) { 
printf("Element can't be inserted through rear end!\n"); 
} 
else { 
int item; 
printf("Enter the item to insert: "); 
scanf("%d",&item); 
if(rear == -1) { 
front=0; 
} 
queue[rear+=1] = item; 
} 
} 

void enqueue_front() { 
if(front < 1) { 
printf("Element can't be inserted through front end!\n"); 
} 
else { 
int item; 
printf("Enter the item to insert: "); 
scanf("%d",&item); 
front--; 
queue[front] = item; 
} 
} 

void dequeue_rear() { 
if(front == -1) { 
printf("Queue underflow!\n"); 
} 
else { 
int item = queue[rear]; 
printf("The element %d is deleted from queue\n",item); 
if(front == rear) { 
front=rear = -1; 
} 
else { 
rear--; 
} 
} 
} 

void dequeue_front() { 
if(front == -1) { 
printf("Queue underflow!\n"); 
} 
else { 
int item = queue[front]; 
printf("The element %d is deleted from queue\n",item); 
if(front == rear) { 
front=rear = -1; 
} 
else { 
front++; 
} 
} 
} 

void display_queue() { 
if(front != -1) { 
printf("\nQueue is:\t"); 
for(int i=front;i<=rear;i++) { 
printf("%d\t",queue[i]); 
} 
printf("\n"); 
} 
else { 
printf("\nQueue is empty!\n"); 
} 
} 

void main() { 
while(notExit == 1) { 
int opt; 
printf("\n1. Insert at rear \n2. Insert at front \n3. Delete from rear \n4. Delete from front \n5. Display \n6. Exit\n"); 
printf("Enter the operation: "); 
scanf("%d",&opt); 
switch(opt) { 
case 1: 
enqueue_rear(); 
break; 
case 2: 
enqueue_front(); 
break; 
case 3: 
dequeue_rear(); 
break; 
case 4: 
dequeue_front(); 
break; 
case 5: 
display_queue(); 
break; 
case 6: 
notExit = 0; 
printf("Exited"); 
break; 
default: 
printf("Invalid operator!"); 
} 
} 
} 
