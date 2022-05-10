#include<stdio.h>
#include<conio.h>
void main()
{

    int arr[100],n,i,min,minpos,j;
    clrscr();
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    // input of elements
    printf("Enter the elements");
    for(i=0;i<n;i++)
    {
	scanf("%d",&arr[i]);
    }

    // selection sort
    for(i=0;i<n-1;i++)
    {
	min=arr[i];
	minpos=i;
	for(j=i+1;j<n;j++)
	{
	    if(arr[j]<min)
	    {
		min=arr[j];
		minpos=j;
	    }
	}
       arr[minpos]=arr[i]; //swapping of min element
       arr[i]=min;
    }
    printf("sorted array \n");
    for(i=0;i<n;i++)
	printf("%d ",arr[i]);
    getch();
}
