#include<stdio.h>

void shellSort(int *arr,int n)
{
   int i,gap,j,temp;
   for(gap=n/2;gap>0;gap/=2)
   {
	for(i=gap;i<n;i++)
	{
	   temp=arr[i];
	   for(j=i;j>=gap&&arr[j-gap]>temp;j-=gap)
	   {
	      arr[j]=arr[j-gap];
	   }
	   arr[j]=temp;
	}
   }
}

void main()
{
  int arr[100],n,i;
  printf("Enter size of array : ");
  scanf("%d",&n);
  printf("Enter the elements of array : \n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  shellSort(arr,n);
  printf("Sorted array :\n ");
  for(i=0;i<n;i++)
  {
    printf("%d ",arr[i]);
  }
}