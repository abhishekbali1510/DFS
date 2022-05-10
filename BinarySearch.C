#include<stdio.h>
#include<conio.h>
int binsrch(int *arr,int low,int high,int key)
{
    int mid=(low+high-1)/2;
    if(arr[mid]==key)
	return mid;
    if(low>=high)
	return -1;
    if(key>arr[mid])
	return binsrch(arr,mid+1,high,key);
    else
	return binsrch(arr,low,mid-1,key);
}
int main()
{

    int arr[100],n,i,key,pos;
    clrscr();
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the elements(sorted)");
    for(i=0;i<n;i++)
    {
	scanf("%d",&arr[i]);
    }

    printf("Enter the element you want to search : ");
    scanf("%d",&key);
    pos=binsrch(arr,0,n,key);
    if(pos==-1)
    {
	printf("not found");
    }
    else
    {
	printf("Element at %d ",pos+1);
    }
    getch();
    return 0;
}
