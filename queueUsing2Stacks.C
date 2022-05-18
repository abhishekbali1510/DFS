#include<stdio.h>
#include<conio.h>

struct node
{
  int data;
  struct node* next;
}*s1,*s2;



void enqueue()
{
  int value,x;
  struct node* temp;
   struct node *actualnode=(struct node*)malloc(sizeof(struct node*));
  printf("Enter the data you want to insert : ");
  scanf("%d",&value);
  //transfer all from s2 to s1
  while(s2!=NULL)
  {

      struct node *newnode=(struct node*)malloc(sizeof(struct node*));
      temp=s2;
      s2=s2->next;
      x=temp->data;
      free(temp);
      newnode->data=x;
      if(s1==NULL)
      {
	s1=newnode;
	newnode->next=NULL;
      }
      else
      {
	newnode->next=s1;
	s1=newnode;
      }
  }
  // actual data goes to s1 top

      actualnode->data=value;
      if(s1==NULL)
      {
	s1=actualnode;
	actualnode->next=NULL;
      }
      else
      {
	actualnode->next=s1;
	s1=actualnode;
      }

}


void dequeue()
{
int x;
struct node* temp;
//transfer everything from s1 to s2
  while(s1!=NULL)
  {
      struct node *newnode=(struct node*)malloc(sizeof(struct node*));
      temp=s1;
      s1=s1->next;
      x=temp->data;
      free(temp);

      newnode->data=x;
      if(s2==NULL)
      {
	s2=newnode;
	newnode->next=NULL;
      }
      else
      {
	newnode->next=s2;
	s2=newnode;
      }
  }
  // actual deletion
     if(s2==NULL)
     {
	printf("Underflow\n");
     }
     else
     {
	temp=s2;
	s2=s2->next;
	free(temp);
     }

}

void display()
{
   struct node *temp;
   //print all if it is in stack1
   if(s1!=NULL)
   {
     temp=s1;
     while(temp!=NULL)
     {
	printf("%d ",temp->data);
	temp=temp->next;
     }

   }
   //print all if it is in stack2
   else if(s2!=NULL)
   {
     temp=s2;
     while(temp!=NULL)
     {
	printf("%d ",temp->data);
	temp=temp->next;
     }


   }
   //both stacks empty
   else
   {
	printf("nothing to show !!!!!");
   }

}

void main()
{
  int choice;
  clrscr();
  while(1){
  printf("Enter your choice\n");
  printf("1. EnQueue\n");
  printf("2. DeQueue\n");
  printf("3. Display\n");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1:enqueue();
	   break;
    case 2:dequeue();
	   break;
    case 3:display();
	  break;
    case 0:exit(0);
	   break;
  }
 }
}