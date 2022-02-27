#include <stdio.h>
void move(int n, char src,char aux ,char dest)
{
    if (n==1)
    {

    printf("\nMove disk %i from %c to %c",n,src,dest);
    }

    else{
        //src will be same but dest will be aux and dest will aux in n-1 condition
        move(n - 1, src,dest,aux);
        printf("\nMove disk %i from %c to %c", n, src, dest);
        //src wiil be aux , dest will be same and aux will be src
        move(n-1,aux,src,dest);
    }
}


int main()
{
char source='A',dest='C',aux='B';
int n;
printf("\nEnter the number of base :\n");
scanf("%d",&n);
move(n,source,aux,dest);


}