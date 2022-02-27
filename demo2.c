#include<stdio.h>

int main()
{
    int *p;
    int d;
    printf("Enter the data : ");
    
    scanf("%i" ,&d);

    p=&d;
    printf("%i",*p);

}