#include<stdio.h>
#define size 20

int binary_search(int array[],int n,int key)
{
    int start = 0;
    int end = n;
    int mid = (start + end) / 2;
    int i;
   
    for (i = 0; i < n; i++)
    {
        if (array[mid] == key)
        {
            return mid;
        }
        else if (key < array[mid])
        {
            end = mid - 1;
        }
        else if(key >array[mid])
        {
            start = mid + 1;
        }
        else if (start>end)
        {
            return -1;
        }
        mid = (start + end) / 2;
    }
    
    }
 int main()
 {
     int arr[size],n,i,key;
     printf("Enter the number of elements :\n");
     scanf("%d",&n);
     printf("enter the %d element inside the array :\n",n);
     for (i=0;i<n;i++)
     {
         scanf("%d",&arr[i]);
     }
     printf("Enter element that you want to search \n");
     scanf("%d", &key);
    int  pos =binary_search(arr,n,key);
     
     if (pos!=-1)
     {
         printf("%d key is found at postion %d",key,pos);
     }
     else
     {
         printf("Error ! Element not found ");
     }
 }