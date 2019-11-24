/* Implementation of static queue */

#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

int queue[CAPACITY];
int front = 0;
int rear = 0;

void insert();
void delete();
void display();

void main()
{
    printf("Welcome to Queue Facility\n");
    int ch;
    
    while(1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");

        printf("Enter choice: \n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

void insert()
{
    if(CAPACITY == rear)
    {
        printf("Queue is full\n\n");
    }
    else
    {
        int element;
        printf("Enter element to insert: ");
        scanf("%d", &element);
        queue[rear] = element;
        rear++;
        printf("Element inserted\n\n");
    }
}

void delete()
{
    if(front == rear)
    {
        printf("Queue is empty\n\n");
    }
    else
    {
        printf("Element deleted is %d\n\n", queue[front]);
        for(int i = 1; i < rear; i++)
        {
            queue[i-1] = queue[i];
        }
        rear--;
    }
}

void display()
{
    if( front == rear)
    {
        printf("Queue is empty\n\n");
    }
    else
    {
        printf("Queue elements: \n");
        for( int i = front; i < rear; i++)
        {
            printf("%d\n", queue[i]);
        }
        printf("\n\n");
    }
}