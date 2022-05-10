#include<stdio.h>

int fact(int n)
{
    
    if(n==1)
        return 1;
    return n*fact(n-1);

}

void main()
{
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    printf("factorial is : %d",fact(n));
}