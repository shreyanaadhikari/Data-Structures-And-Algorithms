#include <stdio.h>

int power(int base,int n)
{
    if(n==0)
        return 1;
    else
        return base * power(base,n-1);
}

int main()
{
    int base,n;

    printf("Enter base and exponent: ");
    scanf("%d%d",&base,&n);

    printf("Result = %d", power(base,n));

    return 0;
}
