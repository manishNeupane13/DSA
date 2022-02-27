#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudentInfo
{
    char name[50];
    char address1[50];
    char email[50];
    char contact_num[11];
    int rollNo;
    int courseID[4];
    struct StudentInfo *next;
};
struct StudentInfo *datanode = NULL;

void Insert()
{

    // FILE *fileptr;
    // fileptr = fopen("studentdata.txt", "a");
    struct StudentInfo *insertnode;
    insertnode = (struct StudentInfo *)malloc(sizeof(struct StudentInfo));

    char name[50], address1[50], email[50];
    int i = 0, rollno, courseId[4];
    char contact_num[11];
    float cgpa;

    //writing inside the file

    getchar();
    printf("\nEnter the name of student :\n");
    gets(name);

    printf("\nEnter the address of student :\n");
    gets(address1);
    printf("\nEnter the email of student :\n");
    gets(email);
    printf("\nEnter the contact number of student:\n");
    scanf("%s", &contact_num);
    printf("\nEnter the roll number of student :\n");
    scanf("%i", &rollno);
    for (i = 0; i < 4; i++)
    {
        printf("Enter the Cousrse Id of %i subject : ", i + 1);
        scanf("%i", &courseId[i]);
    }
    strcpy(insertnode->name, name);
    strcpy(insertnode->address1, address1);
    strcpy(insertnode->email, email);
    strcpy(insertnode->contact_num, contact_num);

    insertnode->rollNo = rollno;
    for (i = 0; i < 4; i++)
    {
        insertnode->courseID[i] = courseId[i];
    }
    insertnode->next = datanode;
    datanode = insertnode;
}

void Search()
{

    struct StudentInfo *temp = datanode;
    int rollnumber, i;
    printf("\nEnter the roll number of student :\n");
    scanf("%i", &rollnumber);
    int found =-1;
    while (temp != NULL)
    {
        if (temp->rollNo == rollnumber)
        {
            printf("\nRoll Number  : %d\n", temp->rollNo);
            printf("\nStudent Name : %s\n", temp->name);
            printf("\nPhone Number : %s\n", temp->contact_num);
            printf("\nEmail          :%s\n", temp->email);
            for (i = 0; i < 4; i++)
            {
                printf("\nCousrse Id of %i subject : ", i + 1);
                printf("%i", temp->courseID[i]);
            }
               found=1;
               break;
    
        }
        temp = temp->next;
    }
    if (found !=1)
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void Update()
{
    struct StudentInfo *temp = datanode;
    int rollnumber,i;
    printf("\nEnter the roll number of student :\n");
    scanf("%i", &rollnumber);

    while (temp != NULL)
    {

        if (temp->rollNo == rollnumber)
        {
            printf("Record with roll number %d Found !!!\n", rollnumber);
            printf("Enter new name:\n");
            scanf("%s", temp->name);
            printf("Enter new phone number: \n");
            scanf("%s", temp->contact_num);
            printf("Enter new email: \n");
            scanf("%s", &temp->email);
            for (i = 0; i < 4; i++)
            {
                printf("Enter the new Cousrse Id of %i subject : ", i + 1);
                scanf("%i",&temp->courseID[i]);
            }
            printf("Updation Successful!!!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void Delete()
{
    struct StudentInfo *temp1 =datanode;
    struct StudentInfo *temp2 =datanode;
    int rollnumber;
    printf("\nEnter the roll number of student :\n");
    scanf("%i", &rollnumber);
    while (temp1 != NULL)
    {

        if (temp1->rollNo == rollnumber)
        {

            printf("Record with roll number %d Found !!!\n", rollnumber);

            if (temp1 == temp2)
            {
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                datanode= datanode->next;
                //head=head->next;

                free(temp1);
            }
            else
            {
                // temp1 is the node we need to delete
                // temp2 is the node previous to temp1
                temp2->next = temp1->next;
               // temp1->next->prev=head;
                free(temp1);
            }

            printf("Record Successfully Deleted !!!\n");
            return;
        }
        temp2 = temp1;
        temp1 =temp1->next;
        
    }
    printf("Student with roll number %d is not found !!!\n", rollnumber);
}
void display()
{
    printf("\nThe list of student inside the linked list:\n");
    struct StudentInfo *outputlink;
    outputlink = datanode;
    while (outputlink != NULL)
    {
        int i = 0;
        printf("%s,", outputlink->name);
        printf(" %s,", outputlink->contact_num);
        printf("%s,", outputlink->address1);
        printf("%i ,", outputlink->rollNo);
        printf("%s,", outputlink->email);

        for (i = 0; i < 4; i++)
        {
            printf("%i ,", outputlink->courseID[i]);
        }
        outputlink = outputlink->next;
    }
}

int main()
{
    //variable for running switch
    char switch_choice;
    //variable to run the loop continously
    char lopping_option;
    //indicating the progrma is about student management system
    printf("\n\t\t\t==========STUDENT MANAGEMENT SYSTEM===========\n");
    // showing the user what kind of operation to perform

    do
    {
        getchar();

        printf("\nPress : \ni.To Insert the data .\nu. To Update the data .\nd. To Delete the data.\ns. To Search the data.\np. To print data on terminal\n");

        //asking user input to run switch operation

        scanf("%c", &switch_choice);
        //executing switch command
        switch ((switch_choice))
        {
        //conditions to perform the insert, update, delete, search operationy
        case 'i':
            Insert();
            break;
        case 'u':
            Update();
            break;
        case 'd':
            Delete();
            break;
        case 's':
            Search();
            break;
        case 'p':
            display();
            break;

        default:
            printf("\n===Sorry!!! Invalid operation.===\n");
            break;
        }
        //deleting all the extra characters
        getchar();
        printf("\nDo you want to continue(y/n)?\n");
        //asking user to continue or not
        scanf("%c", &lopping_option);
    }
    //checking the condition to run the loop or not
    while (lopping_option == 'y');

    return 0;
}
