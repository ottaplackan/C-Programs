#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int top=-1;
int stack[MAX];

void push() {
    int no;
	if(top==MAX-1) {
		printf("Stack Overflow.\n");
	}
	else {
		printf("Enter element to be inserted: ");
		scanf("%d",&no);
		top++;
		stack[top]=no;
	}
}

void pop() {
    	if(top==-1) {
		printf("Underflow Condition.\n");
	}
	else {
		printf("\nDeleted element is: %d",stack[top]);
		top--;
	}
}

void display() {
      for(int i=top;i>=0;i--) {  
        printf("\n%d",stack[i]);  
    }  
    if(top == -1) {  
        printf("Stack is empty.");  
    }  
}

void main() {
    int ch;
    int item;
    do {
        printf("\nEnter your choice:\n1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1: 
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited..");
                break;
            default:
                printf("Invalid Option.\n");
        }
    }while(ch!=4);
}
