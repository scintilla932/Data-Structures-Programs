#include <stdio.h>
#include <stdlib.h>

void Insert();
void Delete();
void Display();

struct node
{
    int data;;
    struct node *link;
};

struct node *top = NULL;

void main()
{
    int ch;
    while(1)
    {
        printf("Welcome to dynamic stack facility\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");

        printf("Enter your choice ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: Insert();
                    break;
            case 2: Delete();
                    break;
            case 3: Display();
                    break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

void Insert()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->link = top;
    top = temp;
    printf("\n");
}

void Delete()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack is empty\n\n");
    }
    else
    {
        temp = top;
        printf("Element deleted is %d\n\n", temp->data);
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

void Display()
{
    struct node *temp;
    if(top == NULL)
    {
        printf("Stack is empty\n\n");
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->link;
        }
    }
}