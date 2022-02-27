#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct StudentInfo
{   char name[50];
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
   
    FILE *fileptr;
	fileptr = fopen("studentdata.txt", "a");
    struct StudentInfo *insertnode;
    insertnode = (struct StudentInfo *)malloc(sizeof(struct StudentInfo));

    char name[50], address1[50], email[50];
    int i = 0, rollno, courseId[4];
    char contact_num[11];
    

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

    fprintf(fileptr, "%i ", insertnode->rollNo);
    fprintf(fileptr, "%s ", insertnode->name);
    fprintf(fileptr, "%s ", insertnode->address1);
    fprintf(fileptr, "%s ", insertnode->email);
    fprintf(fileptr, " %s", insertnode->contact_num);
    for (i = 0; i < 4; i++)
    {
        fprintf(fileptr, "%i ", datanode->courseID[i]);
    }
    fprintf(fileptr,"%s\n" " ");
     fclose(fileptr);
}

void Search()
{
    FILE *readptr;
    readptr = fopen("studentdata.txt", "r+");
    if (readptr == NULL)
    {
        printf("\n No element to show data");
    }
    else
    {
        int i;
        struct StudentInfo *tempnode;
        tempnode =malloc(sizeof(struct StudentInfo));
        int key;
        int notfound;

        printf("\nEnter the Rollno that you want to search :\n");
        scanf("%i", &key);

        char endofflie;

        while (endofflie != EOF)
        {

            fscanf(readptr, "%i", &tempnode->rollNo);
            fscanf(readptr, "%s", tempnode->name);
            fscanf(readptr, "%s", tempnode->address1);
            fscanf(readptr, "%s", tempnode->email);
            fscanf(readptr, "%s", tempnode->contact_num);
            for (i = 0; i < 4; i++)
            {
                fscanf(readptr, "%i", &tempnode->courseID[i]);
            }

            if (tempnode->rollNo == key)
            {
                printf("\nThe details of student of rollno %i is below: ", key);
                printf("\n==============================================\n");
                printf("Name = %s\n", tempnode->name);
                printf("Address =%s\n", tempnode->address1);
                printf("Contact number = %s\n", tempnode->address1);
                printf("E-mail = %s\n", tempnode->email);

                for (i = 0; i < 4; i++)
                {

                    printf("cousrse id of subject %i = %i \n", i + 1,tempnode->courseID[i]);
                }
                printf("==============================================\n");
                // notfound = -1;
                // break;
            }
            else
            {

                endofflie = fgetc(readptr);
            }
        }
        if (notfound != -1)
        {
            printf("\nElement you have entered is not found inside the file.\n");
        }

        fclose(readptr);
    }
}
void Update()
{
    FILE *readptr;
    readptr = fopen("studentdata.txt", "r+");
    if (readptr == NULL)
    {
        printf("\n No element to show data");
    }
    else
    {
        int i;
        struct StudentInfo *tempnode;
        tempnode =malloc(sizeof(struct StudentInfo));
        int key;
        int notfound;

        printf("\nEnter the Rollno that you want to search :\n");
        scanf("%i", &key);

        char endofflie;

        while (endofflie != EOF)
        {

            fscanf(readptr, "%i", &tempnode->rollNo);
            fscanf(readptr, "%s", tempnode->name);
            fscanf(readptr, "%s", tempnode->address1);
            fscanf(readptr, "%s", tempnode->email);
            fscanf(readptr, "%s", tempnode->contact_num);
            for (i = 0; i < 4; i++)
            {
                fscanf(readptr, "%i", tempnode->courseID[i]);
            }
            
            endofflie=getc(readptr);
        }
        if (notfound != -1)
        {
            printf("\nElement you have entered is not found inside the file.\n");
        }

        fclose(readptr);
    }
}
void Delete()
{
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
