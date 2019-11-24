#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;
int len;

void Append();
void Addatbegin();
void Addatafter();
int Length();
void Display();

void main()
{
    int ch;
    while(1)
    {
        printf("Double Linked operations\n");
        printf("1. Append\n");
        printf("2. Add at begin\n");
        printf("3. Add at after\n");
        printf("4. Length\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
            {
                Append();
                break;
            }
            case 2:
            {
                Addatbegin();
                break;
            }
            case 3:
            {
                Addatafter();
            }
            case 4:
            {
                len = Length();
                printf("Length is %d\n", len);
            }
            case 5:
            {
                Display();
                break;
            }
            case 6:
            {
                exit(0);
            }
            default: printf("Invalid choice\n");
        }
    }
}

void Append()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node* p;
        p = root;
        while(p->right != NULL)
        {
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }
    
}

void Addatbegin()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &temp->data);
    temp->left = NULL;
    temp->right = NULL;
    if(root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->right = root;
        root->left = temp;
        root = temp;
    }
}

void Addatafter()
{
    struct node* temp, *p;
    int loc, i =1;
    printf("Enter location to add: ");
    scanf("%d", &loc);
    len = Length();
    if( loc > len)
    {
        printf("Invalic location\n");
        printf("List contains %d nodes\n", len);
    }
    else
    {
        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter node data: ");
        scanf("%d", &temp->data);
        temp->left = NULL;
        temp->right = NULL;
        p = root;
        while( i < loc)
        {
            p = p->right;
            i++;
        }
        temp->right = p->right;
        p->right->left = temp;
        temp->left = p;
        p->right = temp;
    }
}

int Length()
{
    struct node* temp = root;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}

void Display()
{
    struct node* temp = root;
    if(root == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp  != NULL)
        {
            printf("%d-> ", temp->data);
            temp = temp->right;
        }
    }
    
}
