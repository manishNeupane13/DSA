#include<stdio.h>
void digit(int n)
{
    if (n>0)
    {
    
    printf("%i  ", ((n)%10));
    digit(n/10);

    }
    
}
int main()
{
    
    int num;
    printf("Enter the  number having more than one digit  : \n ");
    scanf("%d", &num);
    digit(num);
}