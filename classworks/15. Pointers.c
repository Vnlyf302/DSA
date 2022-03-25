#include<stdio.h>
int main()
{
    int m,n;
    m=50;
    n=5;
    int *p=&m;
    int *q=&n;

    printf("The value of a is %d",m);
    printf("\nThe value of a is %d",*p);

    printf("\nAddress of m is %x",&m);
    printf("\nAddress of p is %x",&p);
}
