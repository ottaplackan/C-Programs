#include<stdio.h>
#include <stdlib.h>
int count=1;
typedef struct node {
 int data;
 struct node*left;
 struct node*right;
}node;
void insert(node**bt,int n) {
    if(*bt==NULL) {
        (*bt)=(node*)malloc(sizeof(node));
        (*bt)->data=n;
        (*bt)->left=NULL;
        (*bt)->right=NULL;
        count++;
    }
    else {
        if(count%2==0)
        insert(&((*bt)->left),n);
        else
        insert(&((*bt)->right),n);
    }
}

void inorder(node*bt) {
    if(bt!=NULL) {
        inorder(bt->left);
        printf("%d\t",bt->data);
        inorder(bt->right);
    }
}

void preorder(node*bt) {
    if(bt!=NULL) {  
        printf("%d\t",bt->data);
        preorder(bt->left);
        preorder(bt->right);
    }
}

void postorder(node*bt) {
    if(bt!=NULL) {
        postorder(bt->left);
        postorder(bt->right);
        printf("%d\t",bt->data);
    }
}

void main() {
    node*bt=NULL;
    insert(&bt,1);
    insert(&bt,2);
    insert(&bt,3);
    insert(&bt,4);
    insert(&bt,5);
    insert(&bt,6);
    printf("Inorder Traversal:\n");
    inorder(bt);
    printf("\n");
    printf("Preorder Traversal:\n");
    preorder(bt);
    printf("\n");
    printf("Postorder Traversal:\n");
    postorder(bt);
}
