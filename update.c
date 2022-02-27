#include <stdio.h>
#include<string.h>
#include<stdlib.h>
struct data
{
    int id;
    char *name;
};
struct data *head=NULL;
void update()
{
    FILE *fileptr;
    fileptr=fopen("student.txt","r+");
    struct data *temp=(struct data *) malloc(sizeof(struct data));
    temp->name=(char*) malloc(sizeof(char));
    char name[50];
    int id ;
    int store=45;  
    // fwrite(&store, sizeof(int), 1, fileptr);
    // fclose(fileptr);
    // while (!feof(fileptr))
    // {
     
     fread(&id,sizeof(int),10,fileptr);
     printf("%d",id);
      fclose(fileptr);
}
    





int main()
{
 update();
}