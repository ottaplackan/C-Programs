#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *lc;
    struct node *rc;
};

struct node* root=NULL;
struct node *ptr,*p;
void display(struct node* ptr) {
    if(ptr!=NULL) {
        display(ptr->lc);
        printf("%d ",ptr->data);
        display(ptr->rc);
    }
}

struct node* create_node(int item) {
    struct node* nn;
    nn=(struct node*)malloc(sizeof(struct node));
    nn->lc=NULL;
    nn->rc=NULL;
    nn->data=item;
    return nn;
}

void insert(struct node *tt) {
    if(root==NULL)
        root=tt;
    else {
        ptr=root;
        while(ptr!=NULL) {
            if(ptr->data>=tt->data) {
                p=ptr;
                ptr=ptr->lc;
            }
            else {
                p=ptr;
                ptr=ptr->rc;
            }
        }
        if(p->data>=tt->data)
            p->lc=tt;
        else
            p->rc=tt;
    }
}

struct node* search(int item) {
    ptr=root;
    while((ptr!=NULL)&&(ptr->data!=item)) {
        p=ptr;
        if(ptr->data<item)
            ptr=ptr->rc;
        else
            ptr=ptr->lc;
    }
    return ptr;
}

void delete(struct node* ptr) {
    if((ptr->lc==NULL)&&(ptr->rc==NULL)) {
        if(ptr==root)
            root=NULL;
        else {
            if(p->rc==ptr)
                p->rc=NULL;
            else
                p->lc=NULL;
        }
    }
    else if((ptr->lc!=NULL)&&(ptr->rc==NULL)) {
        if(p->lc==ptr)
            p->lc=ptr->lc;
        else
            p->rc=ptr->lc;
    }
    else if((ptr->lc==NULL)&&(ptr->rc!=NULL)) {
        if(p->lc==ptr)
            p->lc=ptr->rc;
        else
            p->rc=ptr->rc;
    }
    else {
        struct node *p1;
        p=ptr;
        p1=ptr->rc;
        while(p1->lc!=NULL) {
            p=p1;
            p1=p1->lc;
        }
        ptr->data=p1->data;
        delete(p1);
    } 
}

void main() {
    int data, ch;
    struct node* s;
    do {
        printf("1.Insertion\n2.Search\n3.Deletion\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                s=create_node(data);
                insert(s);
                printf("%d is inserted\n\n",data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d",&data);
                s=search(data);
                if(s==NULL)
                    printf("%d element NOT found.\n\n",data);
                else 
                    printf("%d found.\n\n",s->data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d",&data);
                s=search(data);
                if(s==NULL)
                    printf("%d is NOT found!\n\n",data);
                else {
                    delete(s);
                    printf("%d is deleted\n\n",data);
                }
                break;
            case 4:
                if(root==NULL)
                    printf("Empty List.");
                else
                    display(root);
                printf("\n\n");
                break;
            case 5:
                printf("Exit.");
                break;
            default:
                printf("Invalid Choice.\n\n");
        }
    }while(ch!=5);
}
