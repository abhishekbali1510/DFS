#include<stdio.h>
int arr[10],top=0,n;
void push()
{
    int x;
    if(top==10)
    {
        printf("stack overflow");
    }
    else
    {
        printf("Enter the item ");
        scanf("%d",&x);
        arr[top++]=x;
    }
}
void pop()
{
    
    if(top==0)
    {
        printf("stack underflow");
    }
    else
    {
        top--;
    }
}
void display()
{
    int i;
    for(i=0;i<top;i++)
    {
        printf("%d  ",arr[i]);
    }
}
void main()
{
    
    while(1)
    {
        
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");

        scanf("%d",&n);
        if(n==1)
            push();
        else if(n==2)
            pop();
        else if(n==3)
            display();
        else
            printf("Wrong choice");
        
    }
}