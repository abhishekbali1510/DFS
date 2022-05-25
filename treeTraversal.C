#include<stdio.h>
#include<stdlib.h>
struct node
{
  int  data;
  struct node *right;
  struct node *left;
};


struct node* insertData(struct node* root)
{
  int data;
  struct node *temp,*prv;
  struct node *newnode=(struct node*)malloc(sizeof(struct node *));
  printf("enter the data : ");
  scanf("%d",&data);
  newnode->data=data;
  newnode->left=NULL;
  newnode->right=NULL;
  if(root==NULL)
  {
     root=newnode;
  }
  else
  {
    temp=root;
    while(temp)
    {
      prv=temp;
      if(data<temp->data)
      {
	temp=temp->left;
      }
      else
      {
	temp=temp->right;
      }
    }
    if(data>prv->data)
	prv->right=newnode;
    else
	prv->left=newnode;

  }
  return root;
}

//inorder traversal left->root->right
void inorder(struct node *ptr)
{
  if(ptr==NULL)
   return;
  inorder(ptr->left);
  printf("%d ",ptr->data);
  inorder(ptr->right);
}

//preorder traversal root->left->right
void preorder(struct node *ptr)
{
  if(ptr==NULL)
   return;
  printf("%d ",ptr->data);
  preorder(ptr->left);
  preorder(ptr->right);
}

//postorder traversal left->right->root
void postorder(struct node *ptr)
{
  if(ptr==NULL)
   return;
  postorder(ptr->left);
  postorder(ptr->right);
  printf("%d ",ptr->data);
}


int main()
{
    struct node *root=NULL;
   while(1)
   {
     int ch;

     printf("Enter your choice : \n");
     printf("1. Insert Data : \n");
     printf("2. Preorder traversal\n");
     printf("3. Postorder traversal\n");
     printf("4. Inorder traversal\n");
     scanf("%d",&ch);
     switch(ch)
     {
	case 1: root=insertData(root);
		break;
	case 2: preorder(root);
			printf("\n");
			break;
	case 3: postorder(root);
			printf("\n");
			break;
	case 4: inorder(root);
			printf("\n");
			break;
	case 0: exit(0);
			break;
     }
   }
	return 0;
}
