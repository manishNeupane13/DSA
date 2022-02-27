#include<stdio.h>

#define size 5
int top=-1;

int array[size];

int isempty()
{
    if(top==-1)
    return 1;
    else
    return 0;
   
}
int isfull()
{
    if(top==size)
    return 1;
    else
    return 0;

}
int push(int data)
{
    if (isfull()==0)
    top +=1;
    array[top]=data;
}
int pop()
{
    int data;
    if(isempty()==0)
    {
    data=array[top];
    top -=1;
    printf("value of top %i =",top);
    return data;
    }
}
int peek()
{
return array[top];
}
int main()


{

push(2);
push(3);
push(4);
push(5);

printf("element at top :%i\n", peek());
printf("Stack full: %s\n", isfull() ? "true" : "false");
printf("Stack empty: %s\n", isempty() ? "true" : "false");
while (isempty()==0)
{
    int data=pop();
    printf("After poping : %i\n", data);
}
printf("Stack full: %s\n", isfull() ? "true" : "false");
printf("Stack empty: %s\n", isempty() ? "true" : "false");
}
