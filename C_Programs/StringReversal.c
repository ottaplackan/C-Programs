#include<stdio.h> 

struct node { 
int data; 
struct node *addr; 
}; 

struct node *top = NULL; 

struct node *createnode(char item) { 
struct node *nn; 
nn = (struct node*)malloc(sizeof(struct node)); 
nn->data = item; 
return nn; 
} 

void push(struct node *nn, char item) { 
nn = createnode(item); 
if(top == NULL) { 
nn->addr = NULL; 
top = nn; 
} 
else { 
nn->addr = top; 
top = nn; 
} 
} 

char pop() { 
char str; 
if(top == NULL) { 
printf("\nStack is Empty!"); 
} 
else { 
struct node *p=top; 
str = p->data; 
p=p->addr; 
top=p; 
} 
return str; 
} 

void main() { 
struct node *nn; 
char item, str[100]; 
int length; 
printf("\nEnter the String to reverse: "); 
scanf("%s",&str); 
length = strlen(str); 
for(int i=0;i<length;i++) { 
push(nn, str[i]); 
} 
printf("\nThe Reversed String is: "); 
for(int i=0;i<length;i++) { 
item = pop(); 
printf("%c",item); 
} 
printf("\n"); 
} 
