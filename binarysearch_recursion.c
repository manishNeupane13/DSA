#include<stdio.h>
#define size 20
int binarySearch_recursion(int array[],int start,int end,int key)
{


int mid=(start+end)/2;
if (start>end)
{
    return -1;
}
if (array[mid]==key)
{
    return mid;
}
else if (array[mid]>key)
{
    binarySearch_recursion(array,start,mid-1,key);
}
else
{
    binarySearch_recursion(array,start+1,end,key);
}

}
 int main()
 {
     int arr[size], n, i, key;
     printf("Enter the number of elements :\n");
     scanf("%d", &n);
     printf("enter the %d element inside the array :\n", n);
     for (i = 0; i < n; i++)
     {
         scanf("%d", &arr[i]);
     }
     printf("Enter element that you want to search \n");
     scanf("%d", &key);
     int start = 0;
     int end = n;
    int pos= binarySearch_recursion(arr,start,end,key);
    if (pos != -1)
    {
        printf("%d key is found at postion %d", key, pos);
    }
    else
    {
        printf("Error ! Element not found ");
    }
 }