#include <stdio.h>
#include<stdlib.h>
#define MAX 4
int queue[MAX];
int front = -1;
int rear = -1;
void insert(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = value;
    printf("%d inserted into queue\n", value);
}
void delete()
{
    if (front == -1)
    {
        printf("Queue underflow  \n");
        return;
    }
    printf("%d deleted from queue\n", queue[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue Empty\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main()
{
    int item;
    int choice;
    while (1)
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exit");
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
