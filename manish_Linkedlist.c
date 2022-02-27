#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void InsertAtBegining(int data)
{
    struct node *firstnode;
    firstnode = (struct node *)malloc(sizeof(struct node));
    if (firstnode == NULL)
    {
        printf("\noverflow\n");
    }
    else
    {
        firstnode->data = data;
        firstnode->next = head;
        head = firstnode;
    }
}
void InsertAtPosition(int data, int pos)
{
    struct node *positionnode;
    positionnode = (struct node *)malloc(sizeof(struct node));
    if (pos == 1)
    {
        InsertAtBegining(data);
    }
    else
    {
        struct node *current = head;
        int i = 0;
        for (i = 1; i < (pos); i++)

        {
            current = current->next;
        }
        positionnode->data = data;
        positionnode->next = current->next;
        current->next = positionnode;
    }
}
void printlist()
{
    struct node *outputlink;
    outputlink = head;
    printf("Elements of list : ");

    while (outputlink != NULL)
    {
        printf("%i ", (outputlink)->data);
        outputlink = outputlink->next;
    }
}
void insertAtEnd()
{
    struct node *endnode;
    struct node *tempnode;
    int item;
    endnode = (struct node *)malloc(sizeof(struct node));
    if (endnode == NULL)
    {
        printf("\noverflow\n");
    }
    else
    {
        printf("\nEnter the element to insert at last :\n");
        scanf("%d", &item);
        endnode->data = item;
        /// endnode->next=NULL;
        tempnode = head;
        while (tempnode->next != NULL)
        {
            tempnode = tempnode->next;
        }
        tempnode->next = endnode;
        endnode->next = NULL;
    }
}
void deleteFromBegining()
{
    struct node *tempnode;
    struct node *firstnode;
    if (head == NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        firstnode = head;
        tempnode = firstnode->next;
        head = tempnode;
        free(firstnode);
    }
}
void deleteFromPos()
{
    struct node *tempnode;
    struct node *positionnode;
    int pos, i = 1;
    if (head == NULL)

    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nEnter the position to delete : ");
        scanf("%i", &pos);
        positionnode = head;
        while (i < pos - 1)
        {
            positionnode = positionnode->next;
            i++;
        }
        tempnode = positionnode->next;
        positionnode->next = tempnode->next;
        free(tempnode);
        printf("\nNode delelted sucessfully\n");
    }
    //}
    //void deleteFromeEnd()
    //{
    //    struct node *tempnode;
    //    struct node *endnode;
    //    if (head == NULL)
    //    {
    //        printf("\n Underflow\n");
    //    }
    //    else
    //    {
    //        endnode = head;
    //        while (endnode->next->next != NULL)
    //        {
    //            endnode = endnode->next;
    //        }
    //        tempnode = endnode->next->next;
    //        endnode->next = NULL;
    //        free(tempnode);
    //    }
    //}
    //
    //    void delete_from_pos()
    //    {
    //        struct node *temp;
    //        struct node *ptr;
    //        int pos, i = 1;
    //        if (head == NULL)
    //        {
    //            printf("\nUnderflow\n");
    //        }
    //        else
    //        {
    //            printf("\nEnter the position: ");
    //            scanf("%d", &pos);
    //            temp = head;
    //            while (i < pos - 1)
    //            {
    //                i++;
    //                temp = temp->next;
    //            }
    //            ptr = temp->next;
    //            temp->next = ptr->next;
    //            free(ptr);
    //            printf("\n Node deleted successfully\n");
    //        }
    //    }
    //
    void delete_from_end()
    {
        struct node *temp;
        struct node *ptr;
        if (head == NULL)
        {
            printf("\nUnderflow\n");
        }
        else
        {
            temp = head;
            while (temp->next->next != NULL)
            {
            temp = temp->next;
            }
            ptr = temp->next->next;
            temp->next = NULL;
            free(ptr);
        }
    }

    void search()
    {
        struct node *temp;
        int key;
        int i = 1;
        if (head != NULL)
        {
            printf("\n Enter the key to be searched : ");
            scanf("%i", &key);
            temp = head;
            while ((temp != NULL))
            {
                if (temp->data == key)
                {
                    printf("\n %i is found at post :%i \n", key, i);
                    break;
                }
                else
                {
                    i++;
                    temp = temp->next;
                }
            }
        }
        else
        {
            printf("\n Empty list\n");
        }
    }
    int main()
    {

        InsertAtPosition(21, 1);
        InsertAtBegining(20);
        InsertAtBegining(30);
        InsertAtBegining(390);
        InsertAtPosition(31, 1);
        printlist();
        InsertAtPosition(5, 2);
        InsertAtPosition(4, 3);
        printlist();
        insertAtEnd();
        printlist();
        deleteFromBegining();
        printlist();
        deleteFromPos();
        printlist();
        deleteFromeEnd();
        printlist();
        search();
        printlist();
        return 0;
    }
