#include <stdio.h>
int sum(int n)
{
    if(n==0)
    return 0;
    return n+sum(n-1);

}

int main()
{
    int num;
    printf("Enter the n-term natural number to find sum : \n ");
    scanf("%d",&num);
    // sum(num);
    printf("The sum of first  %i term natural  number = %i ",num,sum(num));
    return 0;
}