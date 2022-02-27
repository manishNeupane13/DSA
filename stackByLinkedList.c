#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *head; 
void push()
{
        int item;
        struct node *pushnode;
        pushnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element you want to enter :\n");
        scanf("%i",&item);
        pushnode->data=item;
        pushnode->next=head;
        head=pushnode;

}
void pop()
{
    if (head == NULL)
    {
        printf("\n No elements to pop out. \n");
    }
    else
    {

        struct node *tempnode;
        struct node *currentnode;
        tempnode = head;
        currentnode = tempnode->next;
        head = currentnode;
        printf("\nThe popping of element %i is sucessfull.\n", tempnode->data);
        free(tempnode);
    }
}
    
    
    void display()
    {
    	 if (head ==NULL)
    {
        printf("\n No elements to pop out. \n");
    }
    else
    {
        struct node *outputlist;
        outputlist=head;
        printf("\n The list of elements inside the stack = ");
        while(outputlist !=NULL)
        {
            printf("%i ", outputlist->data);
            outputlist=outputlist->next;
        }

    }
}
    void peek()
    {
    	 if (head ==NULL)
    {
        printf("\n No elements to pop out. \n");
    }
    else
    {
        struct node *peek;
        peek=head;
        printf("The element at the top of stack = %i ",peek->data);
    }
	}

int main()
{
    char runoption;
    do
    {
    int choose;
     printf("Enter :\n1. To push Elements inside\n2. To  pop Elements outside\n3. To peek\n4. To display whole stack .\n");
     scanf("%i",&choose);
     switch (choose)
     {
     case 1: push();
     break;
     case 2: pop();
     break;
     case 3: peek();
     break;
     case 4: display();
     break;
     default:
     printf("\nOOPS !!! Invalid Inupt.\n");
         break;
     }
    getchar();
    printf("\nDo you want to continue(Y/N) ?  ");
    scanf("%c",&runoption);
    }
    while(runoption =='y');
    return 0;
}

