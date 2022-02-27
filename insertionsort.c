
#include <stdio.h>


void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    while (key < array[j] && j >= 0) 
    {
      array[j + 1] = array[j];
      j-=1; 
      
    }
    array[j + 1] = key;
  }
}
int main()
{
    
    int size;
    int array1[20];
    printf("Enter the size of array \n");
    scanf("%i",&size);
    
    printf("Enter the random number inside the array :\n");
    for (int i=0;i<size;i++)
    {
        scanf("%d",&array1[i]);
    }
    printf("Before sorting \n");
    printArray(array1,size);
    insertionSort(array1,size);
    printf("After sotring \n");
    printArray(array1,size);

}
