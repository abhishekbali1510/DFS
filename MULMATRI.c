#include<stdio.h>
#include<conio.h>
void main()
{
  int arr[100][100],brr[100][100],crr[100][100],m,n,y,z,i,j,sum,k;
  clrscr();


  printf("Emter rows and columns of first matrix : ");
  scanf("%d %d",&m,&n);
  printf("Emter rows and columns of second matrix : ");
  scanf("%d %d",&y,&z);


  if(n==y)   // checking the matrices are eligible for multiplication
  {

     // first matrix input
  printf("Enter elements of first matrix : ");
  for(i=0;i<m;i++)
  {
    printf("enter %d row : ",i+1);
    for(j=0;j<n;j++)
    {
      scanf("%d",&arr[i][j]);
    }
  }
	 // second matrix input
  printf("Enter elements of second matrix : ");
  for(i=0;i<y;i++)
  {
    printf("enter %d row : ",i+1);
    for(j=0;j<z;j++)
    {
      scanf("%d",&brr[i][j]);
    }
  }

  //multiplication
  for(i=0;i<m;i++)
  {
    for(j=0;j<z;j++)
    {
      sum=0;
      for(k=0;k<n;k++)
      {
	sum+=arr[i][k]*brr[k][j];
      }
       crr[i][j]=sum;
    }
  }



     //final matrix
  for(i=0;i<m;i++)
  {
    for(j=0;j<z;j++)
    {
      printf("%d ",crr[i][j]);
    }
    printf("\n");
  }
 }
 else
 {
   printf("matrices can not be multiplied ");
 }
  getch();
}