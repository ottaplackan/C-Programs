#include<stdio.h> 
#include<stdlib.h> 

struct node { 
int data; 
struct node *addr; 
}; 

struct node *a[30]; 
int stack[50], top=-1, visited[30]={0}; 

struct node *create_node(int item) { 
struct node *nn; 
nn = (struct node*)malloc(sizeof(struct node)); 
nn->data = item; 
return nn; 
} 

void push(int item) { 
if(top >= 49) { 
printf("Stack overflow!"); 
} else { 
stack[++top] = item; 
} 
} 

int pop() { 
int item; 
if(top == -1) { 
printf("Stack underflow!"); 
} else { 
item = stack[top]; 
top--; 
} 
return item;
} 

void depth_first_search() { 
int element; 
struct node *s; 
push(1); 
while(top > -1) { 
element = pop(); 
if(visited[element] == 0) { 
printf("%d",element); 
visited[element] = 1; 
s = a[element]; 
s = s->addr; 
while(s != NULL) { 
if(visited[s->data] == 0) { 
push(s->data); 
} 
s = s->addr; 
} 
} 
}
} 

void adj_list(int nodes) { 
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
adj_list(n); 
} 
