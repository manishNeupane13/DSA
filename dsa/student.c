#include <stdio.h>
#include <string.h>
#include <stdlib.h>
    struct info
{
    char name[50];
    int data;
    char address[35];
    char email[50];
    char contact_num[11];
    int courseID[4];
    struct info *next;
};
struct info *datanode = NULL;
void insertintonode(char name[30], int number, char address[50], char email[50],char contact_num[11], int courseId [])
{
    struct info *insertnode = malloc(sizeof(struct info));
    strcpy(insertnode->name, name);
    insertnode->data = number;
    strcpy(insertnode->address, address);
    strcpy(insertnode->email, email);
    strcpy(insertnode->contact_num, contact_num);
    for (int i = 0; i < 4; i++)
    {
        insertnode->courseID [i] = courseId [i];
    }
    insertnode->next = datanode;
    datanode = insertnode;
}
 void fetech()
{
    FILE *fileptr;
    fileptr = fopen("student.csv", "r");
    if (fileptr == NULL)
    {
        printf("\n no element inside the file");
    }
    else
    {
        struct info *tempnode;
        tempnode = (struct info *)malloc(sizeof(struct info));
        char name1[30];
        char address[35];
        char email[50];
        char contact_num[11];
        int item;
        char endofflie;
        while (endofflie != EOF)
        {
            fscanf(fileptr, "%i ", &tempnode->data);
            fscanf(fileptr, "%s ", name1);
            fscanf(fileptr, "%s ", address);
            fscanf(fileptr, "%s ", email);
            fscanf(fileptr, "%s ", contact_num);
            for (int i = 0; i < 4; i++)
            {
                fscanf(fileptr, "%i", &tempnode->courseID[i]);
            }
            strcpy(tempnode->name, name1);
            strcpy(tempnode->address, address);
            strcpy(tempnode->email, email);
            strcpy(tempnode->contact_num, contact_num);
            insertintonode(tempnode->name, tempnode->data, tempnode-> address, tempnode->email, tempnode->contact_num, tempnode->courseID);
            endofflie = fgetc(fileptr);
        }
    }
    fclose(fileptr);
}
void writeinfile(char *ch)
{
    printf("\nwriting data inside the file :\n");
    FILE *filewrite;
    filewrite = fopen("student.csv", ch);
    struct info *writefilenode = datanode;
    while (writefilenode != NULL)
    {
        fprintf(filewrite, "\n%i ", writefilenode->data);
        fprintf(filewrite, "%s ", writefilenode->name);
        fprintf(filewrite, "%s ", writefilenode->address);
        fprintf(filewrite, "%s ", writefilenode->email);
        fprintf(filewrite, "%s ", writefilenode->contact_num);
        for (int i = 0; i < 4; i++)
        {
            fprintf(filewrite, "%i ", writefilenode->courseID[i]);
        }
        writefilenode = writefilenode->next;
    }
    fclose(filewrite);
}
 void insert()
{
    struct info *insertnode = malloc(sizeof(struct info));
    char name[30], address1[50], email[50];
    int i = 0, rollno, courseId[4];
    char contact_num[11];
    int items;
    FILE *fileptr;
    fileptr = fopen("student.csv", "a");
    printf("\nEnter the name :\n");
    scanf("%s", name);
    printf("\nEnter the rollno :\n");
    scanf("%i", &items);
    printf("\nEnter the address of student :\n");
    scanf("%s", address1);
    printf("\nEnter the email of student :\n");
    scanf("%s", email);
    printf("\nEnter the contact number of student:\n");
    scanf("%s", &contact_num);
    for (i = 0; i < 4; i++)
    {
        printf("Enter the Cousrse Id of %i subject : ", i + 1);
        scanf("%i", &courseId[i]);
    }
    strcpy(insertnode->name, name);
    strcpy(insertnode->address, address1);
    strcpy(insertnode->email, email);
    strcpy(insertnode->contact_num, contact_num);
    insertnode->data = items;
    for (i = 0; i < 4; i++)
    {
        insertnode->courseID[i] = courseId[i];
    }
    insertnode->next = datanode;
    datanode = insertnode;
    fprintf(fileptr, "%i ", insertnode->data);
    fprintf(fileptr, "%s ", insertnode->name);
    fprintf(fileptr, "%s ", insertnode->address);
    fprintf(fileptr, "%s ", insertnode->email);
    fprintf(fileptr, "%s ", insertnode->contact_num);
    for (i = 0; i < 4; i++)
    {
        fprintf(fileptr, "%i ", datanode->courseID[i]);
    }
    fprintf(fileptr, "%s","\n");
    fclose(fileptr);
}
void search()
{
    printf("inside the search method");
    fetech();
    struct info *searchnode = datanode;
    int rollnumber, i;
    int found = -1;
    printf("\nEnter the roll number of student :\n");
    scanf("%i", &rollnumber);
    while (searchnode != NULL)
    {
        if (searchnode->data == rollnumber)
        {
            printf("name = %s \n", searchnode->name);
            printf("Address =%s\n", searchnode->address);
            printf("Contact number = %s\n", searchnode->contact_num);
            printf("E-mail = %s\n", searchnode->email);
            for (i = 0; i < 4; i++)
            {
                printf("cousrse id of subject %i = %i \n", i + 1, searchnode-> courseID[i]);
            }
            printf("==============================================\n");
            found = 1;
            return;
            break;
        }
        searchnode = searchnode->next;
    }
    if (found != 1)
    {
        printf("student with roll number %i is not found !!!!\n", rollnumber);
    }
}
void update()
{
    printf("\ninside the update method\n");
    datanode = NULL;
    fetech();
    struct info *updatenode = datanode;
    int rollnumber;
    int found = -1;
    printf("\nEnter the roll number of student :\n");
    scanf("%i", &rollnumber);
    while (updatenode != NULL)
    {

        if (updatenode->data == rollnumber)
        {
            //entering new data
            printf("Record with roll number %d Found !!!\n", rollnumber);
            printf("\n Enter new name :");
            scanf("%s", updatenode->name);
            printf("\nEnter the address of student :\n");
            scanf("%s", updatenode->address);
            printf("\nEnter the email of student :\n");
            scanf("%s", updatenode->email);
            printf("\nEnter the contact number of student:\n");
            scanf("%s", updatenode->contact_num);
            printf("\nupdation sucessfull\n");
            found = 1;
        }
        updatenode = updatenode->next;
    }
    writeinfile("w");
    if (found == -1)
    {
        printf("\nstudent with roll number %i is not found !!!!\n", rollnumber);
    }
}
void delete ()
{
    printf("\nInside the delete method :\n");
    datanode = NULL;
    fetech();
    struct info *tempdeletenode1 = datanode, *tempdeletenode2 = datanode;
    int rollnumber;
    int found = -1;
    printf("\nEnter the roll number of student :\n");
    scanf("%i", &rollnumber);
    while (tempdeletenode1 != NULL)
    {
        if (tempdeletenode1->data == rollnumber)
        {
            printf("Record with roll number %d Found !!!\n", rollnumber);
            if (tempdeletenode1 == tempdeletenode2)
            {
                // this condition will run if
                // the record that we need to delete is the first node
                // of the linked list
                datanode = datanode->next;
                free(tempdeletenode1);
            }
            else
            {
                // tempdeletenode1 is the node we need to delete
                // tempdeletenode2 is the node previous to tempdeletenode1
                tempdeletenode2->next = tempdeletenode1->next;
                free(tempdeletenode1);
            }
            found = 1;
            printf("Record Successfully Deleted !!!\n");
        }
        tempdeletenode2 = tempdeletenode1;
        tempdeletenode1 = tempdeletenode1->next;
    }
    writeinfile("w");
    if (found == -1)
        printf("Student with roll number %d is not found !!!\n", rollnumber);
}
 void display()
{
    datanode = NULL;
    fetech();
    struct info *outputlink = datanode;
    printf("\nThe data inside the file :\n");
    int i = 0;
    while (outputlink != NULL)
    {
        printf("==============================================\n");
        printf("name = %s \n", outputlink->name);
        printf("rollno =%i\n", outputlink->data);
        printf("Email =%s\n", outputlink->email);
        printf("address =%s\n", outputlink->address);
        printf("contact number =%s\n", outputlink->contact_num);
        for (int i = 0; i < 4; i++)
        {
            printf("cousrse id of subject %i = %i \n", i + 1, outputlink->courseID[i]);
        }
        printf("==============================================\n");
        i++;
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
        printf("\nPress : \ni.To Insert the data .\nu. To Update the data .\nd. T o Delete the data.\ns. To Search the data.\np. To print data on terminal\n");
        //asking user input to run switch operation
        scanf("%c", &switch_choice);
        //executing switch command
        switch ((switch_choice))
        {
        //conditions to perform the insert, update, delete, search operationy
        case 'i':
            insert();
            break;
        case 'u':
            update();
            break;
        case 'd':
            delete ();
            break;
        case 's':
            search();
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