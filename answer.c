#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node
{
    int c;
    int e;
    struct node *link;
};

struct node *create(struct node *);
void display(struct node *);
struct node *getnode(int,int);
struct node *findlast(struct node *);
struct node *addpoly(struct node *,struct node *,struct node *);
void evaluate(struct node *start);
int power(int x,int e);
void main()
{
    struct node *start1=NULL,*start2=NULL,*start3=NULL;
    int choice;
    while(1)
    {
        printf("\n1. Create Poly");
        printf("\n2. Display Poly");
        printf("\n3. Addition of Two poly");
        printf("\n4. Evaluation ");
        printf("\n0. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter First Poly :");
                start1=create(start1);
                printf("\nEnter Second Poly :");
                start2=create(start2);
                break;
            case 2:
                printf("\nFirst Poly : ");
                display(start1);
                printf("\nSecond Poly : ");
                display(start2);
                break;
            case 3:
                start3=addpoly(start1,start2,start3);
                display(start3);
                break;
            case 4:
                printf("\nFirst Polynimial Evaluation : \n");
                evaluate(start1);
                printf("\nFirst Polynimial Evaluation : \n");
                evaluate(start2);
                break;
            case 0:
                exit(0);
                break;

            default:
                printf("\nWrong choice!!");
        }
    }
}

struct node *getnode(int coeff,int exp)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->c=coeff;
    temp->e=exp;
    temp->link=NULL;
    return(temp);
}


struct node *findlast(struct node *start)
{
    struct node *ptr;
    for(ptr=start;ptr->link!=NULL;ptr=ptr->link);
    return(ptr);
}


struct node *create(struct node *start)
{
    struct node *ptr,*temp;
    int coeff,exp,n,i;
    printf("\nEnter Number of terms of Polynomial : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nEnter Coefficient and Exponent : ");
        scanf("%d%d",&coeff,&exp);
        temp=getnode(coeff,exp);
        if(start==NULL)
            start=temp;
        else
        {
            ptr=findlast(start);
            ptr->link=temp;
        }
    }
    return(start);
}    



void display(struct node *start)
{
    struct node *ptr;
    for(ptr=start;ptr!=NULL;ptr=ptr->link)
    {
        if(ptr->e!=0)
            printf("%dX^%d+",ptr->c,ptr->e);
        else
            printf("%d",ptr->c);
    }
}


struct node *addpoly(struct node *start1,struct node * start2,struct node *start3)
{
    struct node *ptr1,*ptr2,*ptr3,*temp;
    ptr1=start1;
    ptr2=start2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->e==ptr2->e)
        {
            temp=getnode(ptr1->c + ptr2->c,ptr1->e);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->e > ptr2->e)
        {
            temp=getnode(ptr1->c,ptr1->e);
            ptr1=ptr1->link;
        }
        else
        {
            temp=getnode(ptr2->c,ptr2->e);
            ptr2=ptr2->link;
        }
        if(start3==NULL)
            start3=temp;
        else
        {
            ptr3=findlast(start3);
            ptr3->link=temp;
        }
        ptr3=ptr3->link;
    }
    while(ptr1!=NULL)
    {
        temp=getnode(ptr1->c,ptr1->e);
        ptr3->link=temp;
        ptr1=ptr1->link;
        ptr3=ptr3->link;
    }
    while(ptr2!=NULL)
    {
        temp=getnode(ptr2->c,ptr2->e);
        ptr3->link=temp;
        ptr2=ptr2->link;
        ptr3=ptr3->link;
    }    
    return(start3);
}


void evaluate(struct node *start)
{
    struct node *ptr;
    int x,ans=0;
    printf("\nEnter the value of Variable(x) : ");
    scanf("%d",&x);
    for(ptr=start;ptr!=NULL;ptr=ptr->link)
        ans+=ptr->c*power(x,ptr->e);
    printf("Answer = %d ",ans);
}

int power(int x,int e)
{
    int result=1;
    while (e != 0)
        {
            result =result *  x;
            --e;
        }
    return(result);
}