#include<stdio.h>

void merge(int *,int,int,int);  //declaration of merge

void mergeSort(int *arr,int low,int high)
{
    int mid;
    if(low>=high)
        return;
    mid=(low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);

}

void merge(int *arr,int low,int mid,int high)
{
    int i=low,j=mid+1,temp[100],pos=low,x;
    while((i<mid+1)&&(j<=high))
    {
        if(arr[i]>arr[j])
        {
            temp[pos++]=arr[j];
            j++;
        }
        else
        {
            temp[pos++]=arr[i];
            i++;
        }
    }

    // for remaining elements
    while(i<mid+1)  
    {
        temp[pos++]=arr[i];
        i++;
    }
    
    while(j<=high)
    {
        temp[pos++]=arr[j];
        j++;
    }

    for(x=low;x<=high;x++)
    {
        arr[x]=temp[x];
    }
    
}


void main()
{
    int n,arr[100],i;
    
    printf("Enter size of array : ");
    scanf("%d",&n);

    printf("Enter elements of array : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    mergeSort(arr,0,n-1);

    printf("Sorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}