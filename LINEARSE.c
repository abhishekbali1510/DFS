#include<stdio.h>
#include<conio.h>
void main()
{
  int arr[100],n,i,elem,found=0,foundpos=-1;
  printf("Emter size of array : ");
  scanf("%d",&n);
  printf("Enter elements of array : ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("Enter the element you want to search : ");
  scanf("%d",&elem);
  for(i=0;i<n;i++)
  {
    if(arr[i]==elem)
    {
	found=1;
	foundpos=i+1;
	break;
    }
  }
  if(found==1)
  {
    printf("Element found at %d position",foundpos);
  }
  else
  {
    printf("Element not found");
  }
  getch();
}