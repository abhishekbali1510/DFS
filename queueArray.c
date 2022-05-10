#include<stdio.h>
int arr[5],front=0,rear=0,n,capacity=5,elements=0;
void insert()
{
    int x;
    if(elements==capacity)
    {
	printf("queue overflow");
    }
    else
    {
	printf("Enter the item ");
	scanf("%d",&x);
	arr[rear]=x;
	elements++;
	rear=(rear+1)%10;
    }
}
void Delete()
{

    if(elements==0)
    {
	printf("queue underflow");
    }
    else
    {
	elements--;
	front=(front+1)%10;
    }
}
void display()
{
    int i;
    for(i=front;i!=rear;)
    {
	printf("%d  ",arr[i]);
	i=(i+1)%10;
    }
}
void main()
{
    clrscr();
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
	else if(n==4)
		exit(0);
        else
            printf("Wrong choice");
        
    }
}