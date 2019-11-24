#include <stdio.h>
#include <stdlib.h>

int arr[5];

void bubble_sort();

int main()
{
    printf("Enter 5 numbers to sort: ");
    for(int i=0; i<5; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubble_sort();
    printf("The sorted array is: \n");
    for(int i=0; i<5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort()
{
    int temp;
    for(int i=0; i<5-1; i++)
    {
        for(int j=0; j<5-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\n....Sorted....\n");
}