#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void enqueue()
{
 struct node* ptr=(struct node*)malloc(sizeof(struct node));
 int data;

 if (ptr==NULL)
 {
     printf("\noverflow\n");
 }
 else{
     printf("\nEnter the data :\n");
     scanf("%i", &data);
     ptr->data=data;
     ptr->next=NULL;
     if (front==NULL&& rear==NULL)
     {
         front=ptr;
         rear=ptr;
     }
     else
     {
         struct node *temp;
         temp=rear;
         temp->next=ptr;
         rear=ptr;

     }
 }


}
void dequeue()
{

 	struct node *temp;
	if(front==NULL)
	{
		printf("\nUnderflow:queue is empty\n");
	}
	else
	{
		if(front!=rear)
		{
			temp=front;
			front=temp->next;
			free(temp);
		}
		else
		{
			temp=front;
			front=NULL;
			rear=NULL;
			free(temp);
		}
	}
 
}
void printlist()
{

struct node *outputlink;
if(front ==NULL && rear==NULL)
{
    printf("\nQueue is empty\n");
}
else
{
    outputlink=front;
    printf("\nThe list of element :\n");
while(outputlink !=NULL)
{
    printf("%i   ", outputlink->data);
    outputlink=outputlink->next;
}
}
}
int main()

{

    char choice = 'y';
    int  ch;
    while (1)
    {
        printf("\n press 1::enqueue 2::dequeue 3::display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printlist();
            break;
        default:
            printf("\nInvalid operation\n");
            break;
        }
        getchar();
        printf("\ndo you want to continue(y/n)");
        scanf("%c", &choice);
        if (choice !='y')
        {
            break;
        }
    }
}
