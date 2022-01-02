#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node* link;
};
typedef struct node* NODE;

NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("No memory allocated");
        return NULL;
    }
    return x;
}

NODE insert_rear(NODE first, int elem)
{
    NODE temp,cur,prev;
    temp=getnode();
    temp->info=elem;
    temp->link=NULL;
    cur=first;
    prev=NULL;
    if(first==NULL)
        return temp;
    else
    {
        while(cur!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=temp;
        return first;
    }
}

void display(NODE first)
{
    NODE cur;
    cur=first;
    if(first==NULL)
    {
        printf("No elements");
        return;
    }
    printf("Elements are:\n");
    while(cur!=NULL)
    {
        printf("%d\n", cur->info);
        cur=cur->link;
    }
}

void merge(NODE first1, NODE first2)
{
    NODE cur=first1;
    NODE prev=NULL;
    while(cur!=NULL)
    {
        prev=cur;
        cur=cur->link;
    }
    prev->link=first2;
}

int main()
{
    NODE first1=NULL, first2=NULL;
    int n,m,item1,item2;
    printf("Enter number of nodes for both SLL:\n");
    scanf("%d%d", &n, &m);
    printf("Enter the elements for the first SLL:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &item1);
        first1=insert_rear(first1,item1);
    }
    printf("Enter the elements for the second SLL:\n");
    for(int j=0;j<m;j++)
    {
        scanf("%d", &item2);
        first2=insert_rear(first2,item2);
    }
    merge(first1,first2);
    display(first1);
    return 0;
}