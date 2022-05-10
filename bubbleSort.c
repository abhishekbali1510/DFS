#include<stdio.h>
#include<conio.h>
void main()
{

  int arr[100],n,i,j,tmp;
  clrscr();
  printf("Emter size of array : ");
  scanf("%d",&n);
  printf("Enter elements of array : ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
       tmp=arr[j];
       arr[j]=arr[j+1];
       arr[j+1]=tmp;
      }
    }
  }
  for(i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
  getch();
}