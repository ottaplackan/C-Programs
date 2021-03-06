#include<stdio.h> 

struct node { 
int data; 
struct node *addr; 
}; 

struct node *top = NULL; 

struct node *createnode(int item) { 
struct node *nn; 
nn = (struct node*)malloc(sizeof(struct node)); 
nn->data = item; 
return nn; 
} 

void push(struct node *nn, int item) { 
nn = createnode(item); 
if(top == NULL) { 
nn->addr = NULL; 
top = nn; 
} else { 
nn->addr = top; 
top = nn; 
} 
} 

void pop() { 
if(top == NULL) { 
printf("\nStack is Empty!"); 
} else { 
struct node *p=top; 
p=p->addr; 
top=p; 
} 
} 

int check_bracket(char expression[]) { 
struct node *nn; 
int length = strlen(expression); 
for(int i=0;i<length;i++) { 
if(expression[i] == '(') { 
push(nn, expression[i]); 
} 
if(expression[i] == ')') { 
if(top == NULL) { 
printf("\nThe no. of ) is more than ("); 
return 0; 
} 
else { 
pop(); 
} 
} 
} 
if(top == NULL) { 
return 1; 
} else { 
return 0; 
} 
} 

void main() { 
char expression[100]; 
int check; 
printf("\nEnter the expression to check: "); 
scanf("%s",&expression); 
check = check_bracket(expression); 
if(check == 1) { 
printf("\nThe expression %s is valid and brackets are properly closed\n\n",expression); 
} else { 
printf("\nThe expression %s is not valid and brackets are not properly closed!\n\n",expression); 
} 
} 
