
#include<stdio.h>
int fact(int n)
{
    if (n==0 || n==1)
    {
        return 1;
    }
    return n*fact(n-1);
    // else
    // {
    // }
}
int main()
{

    int num;
    printf("Enter a number :\n");
    // int res;
    // res=fact(num);
    scanf("%d",&num);
    printf("The factorial of %i = %i",num,fact(num));
    return 0;
}
