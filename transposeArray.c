#include<stdio.h>
#include<conio.h>
void main()
{
  int arr[100][100],m,n,i,j,tmp=0;
  clrscr();
  printf("Emter rows and columns of matrix : ");
  scanf("%d %d",&m,&n);
  printf("Enter elements of matrix : ");
  for(i=0;i<m;i++)
  {
    printf("enter %d row : ",i+1);
    for(j=0;j<n;j++)
    {
      scanf("%d",&arr[i][j]);
    }
  }
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }

   for(i=0;i<m;i++)
  {
    for(j=0;j<i;j++)
    {
	tmp=arr[i][j];
	arr[i][j]=arr[j][i];
	arr[j][i]=tmp;

    }
    printf("\n");
  }

  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
  getch();
}