#include<stdio.h>
void main()
{
    int n,fact=1,i;
    printf("Enter the number : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        fact*=i;
    }
    printf("factorial is %d : ",fact);
}