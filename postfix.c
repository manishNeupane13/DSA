#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
    
};
struct data 
{
  char name;
  char id;
};

int isfull(struct stack *stack)
{
    return stack->top==stack->size-1;
}
int isempty(struct stack *stack)
{
    if(stack->top==-1)
    return 1;
    else
    return 0;
}

void push(struct  stack *stack,char item)
{
    
        
        stack->arr[++stack->top] = item;
       

   

}

char pop(struct  stack *stack )
{
    
    return stack->arr[stack->top--];
    


}
char stacktop(struct stack*stack)
{
return stack->arr[stack->top];
}

int isoperator(char ch)
{
 if(ch=='+'|| ch=='-'|| ch=='/'|| ch=='*')
 
     return 1;
 else
 return 0;
}
int precedence(char ch)
{
    if (ch=='*'||ch =='/')
    return 3;
    else if(ch=='+' || ch =='-' )
    return 2;
    else
    return 0;
}

  int main()
  {
      struct stack *stack=(struct stack*)malloc(sizeof(struct stack));
      stack->top= -1;
      stack->size=10;
      stack->arr=(char*)malloc((stack->size)*sizeof(char));
     char *infix="a+b/c-d";
     char *postfix=(char*)malloc ((strlen(infix)+1)*sizeof(char*));
     int i=0; //for infix count
     int j=0; //for profix count
     
 while (infix[i]!='\0')
 {
     

     if(isoperator(infix[i])==0)
     {
            postfix[j]=infix[i];
            i++;
            j++;
     }
     else
     {
       if (precedence(infix[i])>precedence(stacktop(stack)))
       {
           push(stack,infix[i]);
           printf("\nexcute pre");
           i++;
       }
       else
       {
       postfix[j]=pop(stack);
       printf("\nnopre");
       j++;
       }
     }
 } 
 while(isempty(stack)==0)
 {
     postfix[j]=pop(stack);
     j++;
     printf("excute pre");
 } 
 

 printf("post expression = %s",postfix);
 
  } 
      
// //   }

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

//     struct stack
// {
//     int size;
//     int top;
//     char *arr;
// };

// int stackTop(struct stack *sp)
// {
//     return sp->arr[sp->top];
// }

// int isEmpty(struct stack *ptr)
// {
//     if (ptr->top == -1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int isFull(struct stack *ptr)
// {
//     if (ptr->top == ptr->size - 1)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// void push(struct stack *ptr, char val)
// {
//     if (isFull(ptr))
//     {
//         printf("Stack Overflow! Cannot push %d to the stack\n", val);
//     }
//     else
//     {
//         ptr->top++;
//         ptr->arr[ptr->top] = val;
//     }
// }

// char pop(struct stack *ptr)
// {
//     if (isEmpty(ptr))
//     {
//         printf("Stack Underflow! Cannot pop from the stack\n");
//         return -1;
//     }
//     else
//     {
//         char val = ptr->arr[ptr->top];
//         ptr->top--;
//         return val;
//     }
// }

// int precedence(char ch)
// {
//     if (ch == '*' || ch == '/')
//         return 3;
//     else if (ch == '+' || ch == '-')
//         return 2;
//     else
//         return 0;
// }

// int isOperator(char ch)
// {
//     if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
//         return 1;
//     else
//         return 0;
// }
// char *infixToPostfix(char *infix)
// {
//     struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
//     sp->size = 10;
//     sp->top = -1;
//     sp->arr = (char *)malloc(sp->size * sizeof(char));
//     char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
//     int i = 0; // Track infix traversal
//     int j = 0; // Track postfix addition
//     while (infix[i] != '\0')
//     {
//         if (!isOperator(infix[i]))
//         {
//             postfix[j] = infix[i];
//             j++;
//             i++;
//         }
//         else
//         {
//             if (precedence(infix[i]) > precedence(stackTop(sp)))
//             {
//                 push(sp, infix[i]);
//                 i++;
//             }
//             else
//             {
//                 postfix[j] = pop(sp);
//                 j++;
//             }
//         }
//     }
//     while (!isEmpty(sp))
//     {
//         postfix[j] = pop(sp);
//         j++;
//     }
//     postfix[j] = '\0';
//     return postfix;
// }
// int main()
// {
//     char *infix = "x-y/z-k*d";
//     printf("postfix is %s", infixToPostfix(infix));

//     return 0;
// }