#include<stdio.h>
#include<conio.h>
void main()
{

    int arr[100],n,i,temp,j;
    clrscr();
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    // input of elements
    printf("Enter the elements");
    for(i=0;i<n;i++)
    {
	scanf("%d",&arr[i]);
    }

    // Insertion sort
    for(i=1;i<n;i++)
    {
	for(j=i;j>0;j--)
	{
		if(arr[j]<arr[j-1])
		{
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
		}
		else
		{
		  break;
		}
	}
    }


    printf("sorted array \n");
    for(i=0;i<n;i++)
	printf("%d ",arr[i]);
    getch();
}
