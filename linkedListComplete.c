#include<stdio.h>
#include<stdlib.h>
// structure 
struct node
{
    int data;
    struct node *next;
};

// traversing
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
            printf("%d  ",tmp->data);
            tmp=tmp->next;
        }
    }
    
    printf("\n");
}

// Insertion at Beginning
struct node* insertBeg(struct node *head)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node*));

    printf("Enter the data : ");
    scanf("%d",&newnode->data);

    struct node *tmp=head;
    head=newnode;
    newnode->next=tmp;

    return head;

}

// Insertion at End
struct node* insertEnd(struct node *head)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node*));

    printf("Enter the data : ");
    scanf("%d",&newnode->data);
    struct node* temp=head;
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

// Insert at Position
struct node* insertPos(struct node *head)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node*));
    int pos,i=2;
    printf("Enter the data : ");
    scanf("%d",&newnode->data);

    printf("Enter the position : ");
    scanf("%d",&pos);

    struct node* temp=head;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else if(pos==1)
    {
        newnode->next=head;
        head=newnode;

    }
    else
    {
        while(temp->next!=NULL&&i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    return head;

}

// Delete from Beginning
struct node* deleteBeg(struct node* head)
{
    struct node* temp=head;
    if(head==NULL)
    {
        printf("No nodes present to delete !!!");
    }
    else
    {
        head=head->next;
        free(temp);
        
    }
    display(head);
    return head;
    
}


// Delete from End
struct node* deleteEnd(struct node* head)
{
    struct node* temp=head;
    struct node* ptr=head;
    if(head==NULL)
    {
        printf("No nodes present to delete !!!");
    }
    else if(temp->next==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL)
        {
            ptr=temp;
            temp=temp->next;

        }
        ptr->next=NULL;
        free(temp);
    }
    display(head);
    return head;
    
}

// Delete from Position
struct node* deletePos(struct node* head)
{
    struct node* temp=head;
    struct node* ptr=head;
    int pos,i=1;
    printf("Enter the Position : ");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("No nodes present to delete !!!\n");
    }
    else if(pos==1)
    {
        head=head->next;
        free(temp);
    }
    else
    {
        while(temp->next!=NULL&&i<pos)
        {
            ptr=temp;
            temp=temp->next;
            i++;

        }
        if(i<pos)
        {
            printf("No node at that position !!\n");
        }
        else
        {
            ptr->next=temp->next;
            free(temp);
            
        }
        
    }
    display(head);
    return head;
    
}

// searching in list
void search(struct node *head)
{
    int data,i=1;
    struct node* temp=head;
    printf("Enter the data you want to search : ");
    scanf("%d",&data);
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            printf("found at %d node \n",i);
            return;
        }
        temp=temp->next;
        i++;
        
    }
    printf("not found");

}


void main()
{
    struct node* head;
    int choice;

    
    while(1)
    {
        printf("\n");
        printf("Enter the choice : \n");
        printf("0. Exit\n");
        printf("1. Display whole list\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Search an Element\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
                    break;
            
            case 1: display(head);      
                    break;
            
            case 2: head = insertBeg(head);
                    break;

            case 3: head = insertEnd(head);
                    break;
                
            case 4: head = insertPos(head);
                    break;

            case 5: head = deleteBeg(head);
                    break;
                    
            case 6: head = deleteEnd(head);
                    break;

            case 7: head = deletePos(head);
                    break;

            case 8: search(head);
                    break;
        }
    }
}