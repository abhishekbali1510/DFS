#include<stdio.h>

int solution1(int *arr,int n)               // O(n^3) solution
{
    int i,j,k,sum=0,maxSum=-1;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            sum=0;
            for(k=i;k<=j;k++)
            {
                sum+=arr[k];
            }
            if(sum>maxSum)
                maxSum=sum;
        }
    }
    return maxSum;
}


int solution2(int *arr,int n)           // O(n^2)
{
    int i,j,sum,maxSum=-1;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i;j<n;j++)
        {
            sum+=arr[j];
            if(sum>maxSum)
                maxSum=sum;
        }
    }
    return maxSum;
}   

int solution3(int *arr,int left,int right)              //O(nlogn)
{
    int center=0,maxLeft,maxRight,center2Left=0,maxCenter2Left=0,i,center2Right=0,maxCenter2Right=0,greater;
    if(left==right)
        if(arr[left]>0)
            return arr[left];
        else
            return 0;
    center=(left+right)/2;
    maxLeft =solution3(arr,left,center );
    maxRight=solution3(arr,center+1,right );

    for(i=center;i>=left;i--)
    {
        center2Left+=arr[i];
        if(center2Left>maxCenter2Left)
            maxCenter2Left=center2Left;
    }

    for(i=center+1;i<=right;i++)
    {
        center2Right+=arr[i];
        if(center2Right>maxCenter2Right)
            maxCenter2Right=center2Right;
    }

    if(maxLeft>maxRight)
        greater=maxLeft;
    else
        greater=maxRight;
    if(greater>(maxCenter2Left+maxCenter2Right))
        return greater;
    else 
        return maxCenter2Left+maxCenter2Right;

}

int solution4(int *arr,int n)               // O(n)
{
    int i,sum=0,maxSum=-1;
    for(i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum<0)
            sum=0;
        if(sum>maxSum)
            maxSum=sum;
    }
    return maxSum;
}
void main()
{
    int arr[100],n,i;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    printf("Enter elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("O(n^3) Approach : %d\n",solution1(arr,n));   
    printf("O(n^2) Approach : %d\n",solution2(arr,n));   
    printf("O(nlogn) Approach : %d\n",solution3(arr,0,n-1));   
    printf("O(n) approach : %d\n",solution4(arr,n));   
}