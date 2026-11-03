#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insertEnd(struct Node **head, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) return;
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

void deleteFromFirst(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    *head = temp->next;
    printf("Deleted first node (%d)\n", temp->data);
    free(temp);
}

void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    if (temp->next == NULL) {
        printf("Deleted last node (%d)\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted last node (%d)\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (position == 0) {
        deleteFromFirst(head);
        return;
    }
    struct Node *temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct Node *next = temp->next->next;
    printf("Deleted node at position %d (%d)\n", position, temp->next->data);
    free(temp->next);
    temp->next = next;
}

void display(struct Node *head){
  struct Node *temp = head;
  if (temp == NULL){
    printf("List is empty.\n");
    return;
  }
  while (temp != NULL){
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    printf("Initial List:\n");
    display(head);
    printf("\n1. Deleting from first:\n");
    deleteFromFirst(&head);
    display(head);
    printf("\n2. Deleting from end:\n");
    deleteFromEnd(&head);
    display(head);
    printf("\n3. Deleting node at position 1 (element index 1):\n");
    deleteAtPosition(&head, 1);
    display(head);
    return 0;
}
