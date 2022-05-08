#include<stdio.h>
int arr[10],front=0,rear=0,n;
void insert()
{
    int x;
    if(rear==10)
    {
        printf("queue overflow");
    }
    else
    {
        printf("Enter the item ");
        scanf("%d",&x);
        arr[rear++]=x;
    }
}
void Delete()
{
    
    if(rear==front)
    {
        printf("queue underflow");
    }
    else
    {
        front++;
    }
}
void display()
{
    int i;
    for(i=front;i<rear;i++)
    {
        printf("%d  ",arr[i]);
    }
}
void main()
{
    
    while(1)
    {
        
        printf("1.insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");

        scanf("%d",&n);
        if(n==1)
            insert();
        else if(n==2)
            Delete();
        else if(n==3)
            display();
        else
            printf("Wrong choice");
        
    }
}