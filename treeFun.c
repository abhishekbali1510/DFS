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

// queue for level order
struct node * arr[100];
int front=0,rear=0,n,capacity=100,elements=0;
void insert(struct node * x)
{
    if(elements==capacity)
    {
      printf("queue overflow");
    }
    else
    {
    arr[rear]=x;
    elements++;
    rear=(rear+1)%10;
    }
}

struct node * Delete()
{
    struct node * temp;
    if(elements==0)
    {
        return NULL;
    }
    else
    {
        temp=arr[front];
        elements--;
        front=(front+1)%10;
    }
    return temp;
}

int check()
{
    if(elements==0)
        return 0;
    return 1;
}

void lvlorder(struct node *ptr)
{
    if(ptr)
        insert(ptr);
    while(check())
    {
        ptr=Delete();
        printf("%d ",ptr->data);
        if(ptr->left)
            insert(ptr->left);
        if(ptr->right)
            insert(ptr->right);
    }
}

int max=0;
int findMax(struct node * root)
{

  if(root==NULL)
    return 0;
  int left=findMax(root->left);
  int right=findMax(root->right);
  if(left>right)
    max=left;
  else max=right;
  if(root->data>max)
    return root->data;
  else
    return max;
}

int sizeOfTree(struct node * root)
{
  if(root==NULL)
    return 0;
  return sizeOfTree(root->left)+1+sizeOfTree(root->right);
}

struct node * stack[100];
int top=0,n;
void push(struct node * x)
{
    if(top==100)
    {
        printf("stack overflow");
    }
    else
    {
        arr[top++]=x;
    }
}
struct node * pop()
{
    
    if(top==0)
    {
        printf("stack underflow");
    }
    else
    {
        
        top--;
        return arr[top];
    }
}

void levelOrderReverse(struct node* root)
{
  if(root)
    insert(root);
  while(check())
  {
    root=Delete();
    push(root);
    
    if(root->right)
      insert(root->right);
    if(root->left)
      insert(root->left);
    
  }
  while(top!=0)
  {
    printf("%d ",pop()->data);
  }
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
     printf("5. level order traversal\n");
     printf("6. find max\n");
     printf("7. size of Tree\n");
     printf("8. level order traversal Reverse\n");
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
  case 5: lvlorder(root);
      printf("\n");
      break;
  case 6: printf("%d ",findMax(root));
      printf("\n");
      break;
  case 7: printf("%d ",sizeOfTree(root));
      printf("\n");
      break;
  case 8: levelOrderReverse(root);
      printf("\n");
      break;
	case 0: exit(0);
			break;
     }
   }
	return 0;
}
