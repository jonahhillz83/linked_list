/*
 *
 *Lab4
 *Program:Binary search
 *Author: Pratyush Nepal
 *Ref:http:book
 *
 */
#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};

typedef struct node *nodeptr;

nodeptr getnode();
void insertatfront(nodeptr*,int);
int removefromfront(nodeptr*);
void freenode(nodeptr);
void displaylist(nodeptr);

int main()
{
    nodeptr p;
    p=NULL;
    insertatfront(&p,32);
    insertatfront(&p,25);
    insertatfront(&p,37);
    displaylist(p);
    printf("removed=%d",removefromfront(&p));
    printf("removed=%d\n",removefromfront(&p));
    displaylist(p);
}

nodeptr getnode()
{
    return (nodeptr*)malloc(sizeof(nodeptr));
}
void freenode(nodeptr p)
{
    free(p);
}
void insertatfront(nodeptr* p,int x)
{
    nodeptr q;
    q= getnode();
    q->info =x;
    q->next = *p;
    *p=q;

}
void displaylist(nodeptr p)
{
    nodeptr ptr= p;
  while(ptr!=NULL)
  {
      printf("%d\n",ptr->info);
      ptr = ptr->next;
  }

}
int removefromfront(nodeptr*p)
{
    nodeptr q;
    int x;
    q=*p;
    *p=q->next;
    x=q->info;
    return x;
}

