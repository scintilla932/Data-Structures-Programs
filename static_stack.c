/*Implementation of stack using static memory allocation*/

#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5

int stack[CAPACITY], top = -1;

int isFull();
int isEmpty();
void Push();
void Pop();
void Peek();
void Display();

void main()
{
    printf("Welcome to Static Stack Facility\n");
    int ch;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
    
        switch(ch)
        {
            case 1: 
            {
                Push();
                break;
            }
            case 2: {
                Pop();
                break;
            }
            case 3: {
                Peek();
                break;
            }
            case 4: {
                Display();
                break;
            }
            case 5: exit(0);
            default: printf("Invalid Choice\n");
        }
    }
}

int isFull()
{
    if(top == CAPACITY - 1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top == -1)
        return 1;
    else 
        return 0;
}

void Push()
{
    int element;
    printf("Enter element to be pushed: ");
    scanf("%d", &element);
    if(isFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = element;
        printf("%d is pushed\n", element);
    }
}

void Pop()
{
    if(isFull())
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int element = stack[top];
        top--;
        printf("%d is poped\n", element);   
    }
}

void Peek()
{
    if(isEmpty())
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element is %d\n", stack[top]);
    }   
}

void Display()
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        for(int i = 0; i <= top; i++)
        {
            printf("%d", stack[i]);
        }
    }
    printf("\n");    
}

