#include<stdio.h>
#include<stdlib.h>
// structure 
struct node
{
    int coefficient;
    int power;
    struct node *next;
};


// inputting the polynomial
struct node* input(struct node* head)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node*));

    printf("Enter the coef : ");
    scanf("%d",&newnode->coefficient);
    printf("Enter the power : ");
    scanf("%d",&newnode->power);
    struct node *temp=head;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
    return head;
}

//  display polynomial
void display(struct node *head)
{
    struct node *tmp=head;
    if(tmp==NULL)
    {
        printf("No node found");
    }
    else
    {
        while(tmp!=NULL)
        {
            printf("%dx^%d ",tmp->coefficient,tmp->power);
            tmp=tmp->next;
        }
    }
    
    printf("\n");
}


// Addition fx
struct node* sum(struct node* head1,struct node* head2)
{
    struct node* ptr1=head1,*ptr2=head2,*sum=NULL,*temp;
    while(ptr1&&ptr2)
    {
        struct node *newnode=(struct node*)malloc(sizeof(struct node*));

        if(ptr1->power>ptr2->power)
        {
            newnode->coefficient=ptr1->coefficient;
            newnode->power=ptr1->power;
            ptr1=ptr1->next;
        }
        else if(ptr2->power>ptr1->power)
        {
            newnode->coefficient=ptr2->coefficient;
            newnode->power=ptr2->power;
            ptr2=ptr2->next;
        }
        else
        {
            newnode->coefficient=ptr1->coefficient+ptr2->coefficient;
            newnode->power=ptr1->power;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        if(sum==NULL)
        {
            sum=newnode;
            temp=sum;
            newnode->next=NULL;
        }
        else
        {
            temp->next=newnode;
            newnode->next=NULL;
            temp=temp->next;
        }
    }

    // if one polynomial checks for remaining other one
    
    while(ptr1)
    {
        struct node *newnode=(struct node*)malloc(sizeof(struct node*));
        newnode->coefficient=ptr1->coefficient;
        newnode->power=ptr1->power;
        ptr1=ptr1->next;
        
        temp->next=newnode;
        newnode->next=NULL;
        temp=temp->next;
    }

    while(ptr2)
    {
        struct node *newnode=(struct node*)malloc(sizeof(struct node*));
        newnode->coefficient=ptr2->coefficient;
        newnode->power=ptr2->power;
        ptr2=ptr2->next;
        
        temp->next=newnode;
        newnode->next=NULL;
        temp=temp->next;
    
    }

    return sum;
}

void main()
{
    int n1,n2,i;
    struct node *head1=NULL,*head2=NULL,*head3;
    printf("number of terms in 1st equation : ");
    scanf("%d",&n1);

    printf("number of terms in 2nd equation : ");
    scanf("%d",&n2);

    printf("Enter the first polynomial : ");
    i=0;
    while(i<n1)
    {
        head1=input(head1);
        i++;
    }

    printf("Enter the second polynomial : ");
    i=0;
    while(i<n2)
    {
        head2=input(head2);
        i++;
    }
    display(head1);
    display(head2);
    head3=sum(head1,head2);
    display(head3);

}