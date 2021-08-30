#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
}

int isEmpty(struct queue *q)
{
    if (q->front > q->rear || q->rear == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}

void enQueue(struct queue *q, int val)
{

    if (isFull(q))
    {
        printf("HAHH!! This Queue is full!!!\n");
    }
    else
    {
        if (q->rear == -1)
        {
            q->front = 0;
        }

        q->rear++;
        q->arr[q->rear] = val;
        printf("Woohoo!! Operation successfull!!! The Enqeued element is:  %d\n", val);
    }
}

int deQueue(struct queue *q)
{
    int deQueuedelement = -1;
    if (isEmpty(q))
    {
        printf("Alas!! This Queue is empty:(\n");
        return INT_MIN;
    }
    else
    {

        deQueuedelement = q->arr[q->front];
        q->front++;
    }
    return deQueuedelement;
}
void Display(struct queue *q)
{
    int i;
    if (isEmpty(q))
    {
        printf("Huh!!! This Queue is empty:(\n");
    }

    else
    {

        for (i = q->front; i <= q->rear; i++)
            printf("Queue is:  %d \n", q->arr[i]);
    }
}

int main()
{
    struct queue q;
    int size, disp;
    printf("HOLA!!!\n");
    printf("Enter Maximum size of the Queue:  \n");
    scanf("%d", &size);
    create(&q, size);
    int choice;
    do
    {
        printf("MENU:\n");
        printf("1. Press 1 to EnQueue element in Queue!\n");
        printf("2. Press 2 to DeQueue element from Queue!\n");
        printf("3. Press 3 to Print Queue!\n");
        printf("4. Exit!\n");
        printf("Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:;
            int x;
            printf("Enter element: \n");
            scanf("%d", &x);

            enQueue(&q, x);
            break;
        case 2:;
            int temp = deQueue(&q);

            printf("Woohoo!! deQueued operation is successfull!!!  :%d is deQueued\n", temp);

            break;
        case 3:
            Display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("OOPS!...Wrong Choice:(\n");
            break;
        }
    } while (choice < 4 && choice > 0);

    return 0;
}
