// Circular Queue implementation in C

#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
void enqueue() {
    int element;
    printf("Enter the element you want to enter :\n");
    scanf("%i", &element);
    if (isFull())
        printf("\n Queue is full!! \n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\n element inserted \n");
    }
}

// Removing an element
int dequeue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n element Deleted \n");
    return (element);
  }
}

// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {

    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    
  }
}

int main() {
  // Fails because front = -1
 
   char choice = 'y';
    int  ch;
    while (1)
    {
        printf("\n press 1::enqueue 2::dequeue 3::display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
             
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        default:
            printf("\nInvalid operation\n");
            break;
        }
        getchar();
        printf("\ndo you want to continue(y/n)");
        scanf("%c", &choice);
        if (choice !='y')
        {
            break;
        }
    }

  return 0;
}