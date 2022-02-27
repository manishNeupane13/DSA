#include<stdio.h>
#define size 10
int top=-1;
void push(int arr[], int elem)
{
    if (top == size - 1)
    {
        printf("\n Stack overflow");
    }
    else
    {
        top++;
        arr[top] =elem;
    }
}
void pop(int arr[])
{   
    int data;
    if(top==-1)
    {
        printf("\n STack is empty : ");

    }
    else 
    {
        data= arr[top];
        top--;
        printf("\n Elements to be deleted = %i",data);
 }
}
void peek(int arr[])
{
    if (top==-1)
    {
    printf("\n Stack is empty");
    }
    else
    {
    printf("\nElement at top = %d ",arr[top]);
    }
}
void display(int arr[])
{  
    int i;
    printf("\nElement in stack :\n");
    for(i=top;i>-1;i--)
    {
        printf("%d\n", arr[i]);
    }
}
int main()
{
    int array[size], item , choose;
    char ch ='y';

   
    
    do
    {
        printf("Enter 1: To push 2: To pop 3: To peek 4:To display ");
        scanf("%i", &choose);
        switch (choose)
        {
        case 1:
            printf("\n Enter the element to be pushed : ");
            scanf("%d", &item);
            push(array, item);
            break;

        case 2:
            pop(array);
            break;
        
        case 3:
            peek(array);
            break;
        case 4:
            display(array);
            break;
        default:
            printf("\n Invalid operation");
            break;
       }
       getchar();
       printf("\nDO you want to continue (y/n)?\n :");
       scanf("%c", &ch);
    } while (ch == 'y');
    return 0;
   
   
   
    
   
}
