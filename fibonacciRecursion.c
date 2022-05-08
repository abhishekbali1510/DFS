#include<stdio.h>

int fibo(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    return fibo(n-1)+fibo(n-2);
}

void main()
{
    int n;
    printf("Enter the term you want to find : ");
    scanf("%d",&n);
    printf("fibbonaci's %d term is : %d",n,fibo(n));
}