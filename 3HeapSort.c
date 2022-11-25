#include<stdio.h>

void heapify(int *arr,int i,int n)
{
    int left=i*2+1;
    int right=i*2+2;
    int largest=i;
    if(left>n||right>n)
        return;
    if(left<n && arr[left]>arr[largest])
        largest=left;
    if(right<n && arr[right]>arr[largest])
        largest=right;

    int temp=arr[largest];
    arr[largest]=arr[i];
    arr[i]=temp;

    if(largest!=i)
        heapify(arr,largest,n);
}

void heapSort(int *arr,int n)
{
    int i=0;
    for(int i=n/2;i>=0;i--)         //Build Heap
        heapify(arr,i,n);
    printf("Build Heap : ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    for(i=0;i<n;i++)
    {
        int temp=arr[0];
        arr[0]=arr[n-1-i];
        arr[n-1-i]=temp;
        heapify(arr,0,n-1-i);
    }
    
}

void main()
{
    int n,i;
    printf("Enter number of elments : ");
    scanf("%d",&n);

    int arr[100];
    printf("Enter elments : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    heapSort(arr,n);

     printf("Heap Sort: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    

}