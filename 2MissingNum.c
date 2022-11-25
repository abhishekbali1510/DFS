#include<stdio.h>
#include<stdlib.h>

int findMissing(int *arr,int n)
{
    int lowInd=0,highInd=n-1;
    int low=1,high=n;
    if(arr[highInd]==high)
        return -1;
    while(high>low)
    {
        int midInd=(lowInd+highInd)/2;
        int mid=(low+high)/2;
        if(arr[midInd]>mid)
            {
                high=mid;
                highInd=midInd;

            }
        else
            {
                low=mid+1;
                lowInd=midInd+1;
            }
    }
    return arr[lowInd]-1;
}
void main()
{
    int n,i;
    printf("Enter number of ELements ");
    scanf("%d",&n);
    int arr[100];
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d",findMissing(arr,n));
}