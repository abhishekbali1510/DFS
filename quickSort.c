#include<stdio.h>

int findPivot(int *arr,int low,int high)
{
    int pivot=low,temp;
    while(low<=high)
    {
        while(arr[low]<=arr[pivot])
            low++;

        while(arr[high]>arr[pivot])
            high--;

        if(low<high)
        {
            temp=arr[low];
            arr[low]=arr[high];
            arr[high]=temp;
        }

    }
// placing pivot to right position
    temp=arr[pivot];
    arr[pivot]=arr[high];
    arr[high]=temp;
    return high;


}

void quickSort(int *arr,int low,int high)
{
    if(low>=high)
        return;     //termination case
    int pivot=findPivot(arr,low,high);
    quickSort(arr,low,pivot-1);
    quickSort(arr,pivot+1,high);

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

    quickSort(arr,0,n-1);

    printf("Sorted array : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}