#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;

void insert(int);
void traverse(struct node*);

int main()
{
    int d;
    int ch;
    while(1)
    {
        printf("\n*** Binary Search Tree ***\n");
        printf("1. Insert\n");
        printf("2. Traverse(In order)\n");
        printf("3. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
               printf("\nEnter data: \n");
               scanf("%d", &d);
               insert(d);
               break;
            case 2:
                traverse(root);
                break;
            case 3:
                exit(0);
            default:
                printf("Inavlid choice\n");  
        }
    }
    return 0;
}

void insert(int d)
{
    struct node* t, * p;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    p = root;
    if(root == NULL)
    {
        root = t;
    }
    else
    {
        struct node* curr;
        curr = root;
        while(curr)
        {
            p = curr;
            if(t->data > curr->data)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }    
        if(t->data > p->data)
        {
            p->right = t;
        }
        else
        {
            p->left = t;
        }
            
    }
}

void traverse(struct node* t)
{
    if(t->left)
    {
        traverse(t->left);
    }

    printf("%d ", t->data);

    if(t->right)
    {
        traverse(t->right);
    }
}
