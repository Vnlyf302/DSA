#include<stdio.h>
const pie= 22/7;
int Area(int rad)
{
    float area;
    area= pie* pow(rad, 2);
    return area;
}

void main()
{
    int rad;
    float area;
    printf("Enter the radius of Circle: ");
    scanf("%d",&rad);
    area=Area(rad);
    printf("Area is %0.2f",area);
}
