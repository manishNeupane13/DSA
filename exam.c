#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int rollno;
    char name[50];
    char address[50];
    char contact_num[50];
    struct node *prev;
    struct node *next;
};
struct node *head;

void Insert()
{
    struct node *insertnode;
    insertnode= (struct node *)malloc(sizeof(struct node));
    char name[50], address1[50];
    int i = 0, rollno;
    char contact_num[11];
    getchar();
    printf("\nEnter the name of student :\n");
    gets(name);
    printf("\nEnter the address of student :\n");
    gets(address1);
    printf("\nEnter the contact number of student:\n");
    scanf("%s", &contact_num);
    printf("\nEnter the roll number of student :\n");
    scanf("%i", &rollno);
    strcpy(insertnode->name, name);
    strcpy(insertnode->address, address1);
    strcpy(insertnode->contact_num, contact_num);

    insertnode->rollno =rollno;
    insertnode->next = head;
    insertnode->prev = NULL;
    if (head != NULL)
    {
        head->prev = insertnode;
    }
    head = insertnode;
}


void Search()
{
    struct node *tempnode;

    tempnode = head;
    if (head != NULL)
    {
        int key, i = 1;
        printf("\nEnter the rollno  of student you want to search :\n");
        scanf("%i", &key);
        while (tempnode != NULL)
        {
            if (tempnode->rollno == key)
            {
                printf("\nThe details of student of rollno %i is below: ", key);
                printf("\n==============================================\n");
                printf("Name = %s\n", tempnode->name);
                printf("Address =%s\n", tempnode->address);
                printf("Contact number = %s\n", tempnode->contact_num);
                break;
                
            }
            else
            {
                i++;
                tempnode = tempnode->next;
            }
        }
    }
    else
    {
        printf("\nEmpty list \n");
    }
}
void Display()
{
    printf("\nThe list of student inside the linked list:\n");
    struct node *outputlink;
    outputlink= head;
    while (outputlink != NULL)
    {
        int i = 0;
        printf("%s,", outputlink->name);
        printf(" %s,", outputlink->contact_num);
        printf("%s,", outputlink->address);
        printf("%i ,", outputlink->rollno);
       
        outputlink = outputlink->next;
    }
}
void Delete()
{
    struct node *temp_ptr;
    struct node *ptr;
    ptr = head;
    int pos, i = 1;
    printf("\nEnter the  index of student  you want to delete :");
    scanf("%i", &pos);
     for (int i = 0; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
   

    temp_ptr = ptr->next;
    ptr->next = temp_ptr->neixt;
    temp_ptr->next->prev = ptr;
    free(temp_ptr);
    printf("\n Deletion sucessfull .\n", pos);
    
}

int main()
{
    char runoption;
    do
    {
        int choose;
        printf("\n Student Management system\n");
        printf("Enter :\n1. To Insert student data \n2. To Delete Student data \n3. To Search Student list \n4. To display whole List  .\n");
        scanf("%i", &choose);
        switch (choose)
        {
        case 1:
            Insert();
            break;
        case 2:
             Delete();
            break;
        case 3:
            Search();
            break;
        case 4:
            Display();
            break;
        default:
            printf("\nOOPS !!! Invalid Inupt.\n");
            break;
        }
        getchar();
        printf("\nDo you want to continue(Y/N) ?  ");
        scanf("%c", &runoption);
    } while (runoption == 'y');
    return 0;
}
