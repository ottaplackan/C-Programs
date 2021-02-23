#include<stdio.h> 
#include<stdlib.h>

struct node { 
int data; 
struct node *addr; 
}; 

struct node *a[30]; 
int queue[50], front=-1, rear=-1; 
int visited[30]={0}; 
struct node *create_node(int item) { 
struct node *nn; 
nn = (struct node*)malloc(sizeof(struct node)); 
nn->data = item; 
return nn; 
} 

void enqueue(int item) { 
if(rear == 49) { 
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

int dequeue() { 
int item; 
if(front == -1 && rear == -1) { 
printf("Queue is Empty\n"); 
} 
else if(front == rear) { 
front = rear =-1; 
item = queue[front]; 
} 
else { 
front++; 
item = queue[front]; 
} 
return item; 
} 

void depth_first_search() { 
int element; 
struct node *s; 
enqueue(0); 
while(front != -1 && rear != -1) { 
element = dequeue(); 
if(visited[element] == 0) { 
printf("%d",element); 
visited[element] = 1; 
s = a[element]; 
s = s->addr; 
while(s != NULL) { 
if(visited[s->data] == 0) { 
enqueue(s->data); 
} 
s = s->addr; 
} 
} 
} 
} 

void create_list(int nodes) { 
int n, data; 
struct node *h; 
for(int i=0;i<nodes;i++) { 
a[i] = create_node(i); 
} 
for(int i=0;i<nodes;i++) { 
h = a[i]; 
printf("Enter the number of adjacent nodes of %d: ",i); 
scanf("%d",&n); 
for(int j=0;j<n;j++) { 
printf("Enter the elements: "); 
scanf("%d",&data); 
h->addr = create_node(data); 
h=h->addr; 
} 
} 
printf("\nDepth First Search: "); 
depth_first_search(); 
} 

void main() { 
int n; 
printf("Enter the number of nodes: "); 
scanf("%d",&n); 
create_list(n); 
} 
