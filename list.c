#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int insert(int *arr, int value, int n)
{
    arr[n] = value;
    ++n;
    return n;
}

int search(int *arr, int value, int n)
{
    int i, flag = 0;
    for (i = 0; i < n; ++i)
    {
        if (arr[i] == value)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        return i;
    }

    return -1;
}

int del(int *arr, int value, int n)
{
    int result, temp;
    result = search(arr, value, n);
    if (result == -1)
    {
        return -1;
    }
    for (int i = result + 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    return n - 1;
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[10], choice, n = 0, value, result;

    do
    {
        system("cls");
        printf("Implimentation of list\nchoose any operation\n");
        printf("1. Insert an element\n2. Delete an element\n3. Search\n4. View list\n5. Exit \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value you want to insert: ");
            scanf("%d", &value);
            n = insert(arr, value, n);
            printf("\nValue Added at index: %d\n", n - 1);
            printf("Updated array is :\n");
            display(arr, n);

            break;
        case 2:
            printf("Enter the value you want to delete\n\t");
            scanf("%d", &value);
            result = del(arr, value, n);
            if (result == -1)
            {
                printf("Element not found or array is empty");
                break;
            }
            else
            {
                n = result;
                printf("Element is deleted\n");
            }
            printf("Updated array is :\n");
            display(arr, n);
            break;
        case 3:
            printf("Enter the value you want to search\n\t");
            scanf("%d", &value);
            result = search(arr, value, n);
            if (result == -1 || n == 0)
                printf("Element not found or array is empty");
            else
                printf("Element found on index: %d", result);
            break;
        case 4:
            system("cls");
            display(arr, n);
            break;
        case 5:
            printf("press enter to exit...");
            getch();
            exit(0);
            break;
        default:

            printf("Wrong choice");
            break;
        }
        printf("\nPress enter to continue");
        getch();
    } while (1);
}
