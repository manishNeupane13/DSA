#include <stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
    char name[10];
    int val;
    struct node *next;

};
struct node *head;

void insert()
{
  
    char name[10];
    int val;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the name of student:\n");
    scanf("%s", &name);
    printf("\nEnter the roll number of student :\n");
    scanf("%i", &val);

    strcpy(temp->name, name);
    temp->val = val;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }


}
void writeLinkedList()
{

    struct node *temp = head;

    FILE *file;
    file = fopen("hello.txt", "a");
    if (file == NULL)
    {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit(1);
    }

    // writing all the nodes of the linked list to the file
    while (temp != NULL)
    {
        // fwrite(temp, sizeof(struct node), 1, file);
        // 
        fprintf(file, "%i ", temp->val);
        fprintf(file, "%s ", temp->name);
        temp = temp->next;
    }

    if (fwrite != 0)
    {
        printf("Linked List stored in the file successfully\n");
    }
    else
    {
        printf("Error While Writing\n");
    }

    fclose(file);
}
void read()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    ;
    struct node *head; // points to the first node of the linked list in the file
    struct node *last; // points to the last node of the linked list in the file
    last = head = NULL;

    FILE *file;
    file = fopen("hello.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "\nCouldn't Open File'\n");
        exit(1);
    }

    // reading nodes from the file
    // nodes are read in the same order as they were stored
    // we are using the data stored in the file to create a new linked list

    fread(temp, sizeof(int), 1, file);
    fread(temp,sizeof(char),30,file);
    

      
        if (head == NULL)
        {
            head = last = (struct node *)malloc(sizeof(struct node));
        }
        else
        {
            last->next = (struct node *)malloc(sizeof(struct node));
            last = last->next;
        }
        last->val = temp->val;
        strcpy(last->name, temp->name);
        printf("form read rollno =%i ",last->val);
        printf("form read name = %s \n", last->name);
        last->next = NULL;
    

    fclose(file);
}
void display()
{
    struct node *temp = head;
    printf("\nLinkedList: ");
    while (temp != NULL)
    {
        printf("%d %s -> ", temp->val, temp->name);
        temp = temp->next;
    }
    printf("NULL\n\n");

}

int main()
{
insert();
writeLinkedList();
display();
read();
display();


}