// #include<stdio.h>
// #include<stdlib.h>


// struct node
// {
//  int data;
//  struct node *ptr;

// };



// int main()
// {
//      struct node *firstnode;
//      struct node *secondnode;
//      struct node *thirdnode;


//     firstnode=(struct node*)malloc(sizeof(struct node*));
//     secondnode=(struct node*)malloc(sizeof(struct node*));
//     thirdnode=(struct node*)malloc(sizeof(struct node*));



//     firstnode->data=10;
//     firstnode->ptr=secondnode;
//     secondnode->data=20;
//     secondnode->ptr=thirdnode;
//     thirdnode->data=30;
//     thirdnode->ptr=NULL;
//    printf(" fist node data = %i  second node data = %i  third node data = %i", firstnode->data, secondnode->data, thirdnode->data);
//    printf(" fist node data = %i  second node data = %i  third node data = %i", firstnode->ptr, secondnode->ptr, thirdnode->ptr);
// }
#include <stdio.h>
#include <stdlib.h>

struct node
{
   int data;
   struct node *next;
};
void display(struct node *list,int n)
{
   int i;
   printf("\nThe output is given below :\n");
   for (i = 0; i < n; i++)
   {
      printf("Data of list %i = %i \n", (i + 1), (list + i)->data);
   }
}


int main()
{
   struct node *list = (struct node *)malloc(sizeof(struct node));
   int i, data, n;
   printf("Enter the number linked list you want to created : ");
   scanf("%i", &n);
   printf("Enter the data to inserted inside the linked list : ");

   for (i = 0; i < n; i++)
   {
      scanf("%i", &data);
      (list + i)->data = data;
      (list + i)->next = (list + (i + 1));
    
   }
  display(list,n);
}