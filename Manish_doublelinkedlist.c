#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;

    struct node *next;
};
struct node *head=NULL;

 void InsertAtBeginnig()
 {
  struct node *firstnode;
  firstnode=(struct node*)malloc(sizeof(struct node));
  int item;
  printf("Enter the element you want to insert :\n");
  scanf("%i",&item);
  firstnode->data=item;
  firstnode->next=head;
  firstnode->prev=NULL;
  if(head !=NULL)
  {
      head->prev=firstnode;
  }
  head=firstnode;

 }
 void InsertAtPos()
 {
     struct node *positionnode;
     struct node *tempnode=head;
     int item,pos;
     printf("\nEnter the element you want to insert :\n");
     scanf("%i",&item);
     printf("Enter the position of element where you want to inset :\n");
     scanf("%i",&pos);
     int i=1;
     if (pos==1)
     {
         InsertAtBeginnig();
     }
     else 
     {
     while(i <(pos-1))
     {
         tempnode=tempnode->next;
         i++;
     }
     positionnode->data=item;
     positionnode->next=tempnode->next;
     (tempnode->next)->prev=positionnode;
      tempnode->next=positionnode;

     positionnode->prev=tempnode;

     }
    



 }
 void InsertATEnd()
 {
     struct node *endnode;
     endnode=(struct node *)malloc(sizeof(struct node));
     struct node *tempnode = head;
     int item, pos;
     printf("\nEnter the element you want to insert :\n");
     scanf("%i", &item);
     while(tempnode->next!=NULL)
     {
         tempnode=tempnode->next;
     }
     endnode->data=item;
     endnode->next=NULL;
     tempnode->next=endnode;
     endnode->prev=tempnode;
     


 }
 void search()
 {
     struct node *tempnode;
    
    tempnode=head;
     if (head !=NULL)
     {
         int key, i = 1;
         printf("\nEnter the element you want to search :\n");
         scanf("%i", &key);
         while (tempnode !=NULL)
         {
             if (tempnode->data == key)
             {
                 printf("\n %i element is found at position : %i\n ",key,i);
                 break;

             }
             else
             {
                 i++;
                 tempnode=tempnode->next;
             }
         }
         
      
     }
     else{
         printf("\nEmpty list \n");
     }
     
 }
 void display()
 {
     struct node *outputlink;
     outputlink=head;
     printf("\nThe list of elements :\n");
     while(outputlink !=NULL)
     {
         printf(" %i ",outputlink->data);
         outputlink=outputlink->next;

     }
     
 }
 void deleteAtBeginning()
 {
     struct node *tempnode;
     struct node *currentnode;
     tempnode=head;
     currentnode=tempnode->next;
     currentnode->prev=NULL;
     head=currentnode;
     printf("\n Deletion at firstplace Sucessfull.\n");
     
     
 }
 void deleteAtPos()
 {
   

     
         struct node *tempnode;
         struct node *currentnode;
         tempnode=head;
         int pos,i=1;
         printf("\nEnter the Element position you want to delete :");
         scanf("%i",&pos);
         while(i < pos-1)
         {
             tempnode=tempnode->next;
             i++;
         }
        currentnode=tempnode->next;
        tempnode->next=currentnode->next;
        (currentnode->next)->prev=tempnode;
         free(currentnode);
         printf("\n Deletion at %i posistion is sucessfull .\n",pos);
     
 }
 void deleteAtEnd()
 {
     struct node *tempnode;
     struct node *currentnode;
     tempnode = head;
     while(tempnode->next->next!=NULL)
     {
         tempnode=tempnode->next;
     }
     currentnode=tempnode->next;
     tempnode->next=currentnode->next;

     free(currentnode);
     printf("\n Deletion at Last place is Sucessfull.\n");
 }
 int main()
 {
InsertAtBeginnig();
InsertAtBeginnig();
InsertAtBeginnig();
display();
InsertAtPos();
display();
InsertATEnd();
display();
search();
deleteAtBeginning();
display();
deleteAtPos();
display();
deleteAtEnd();
display();


 }
