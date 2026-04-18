#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
struct Node* insertBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Insert at position (1-based)
struct Node* insertPosition(struct Node* head, int data, int pos) {
    if (pos == 1)
        return insertBeginning(head, data);

    struct Node* newNode = createNode(data);
    struct Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return head;

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Delete from beginning
struct Node* deleteBeginning(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

// Delete from end
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    return head;
}

struct Node* deletePosition(struct Node* head, int pos) {
    if (head == NULL)
        return NULL;

    // Delete first node
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;

    // Move to (pos-1)th node
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    // If position is invalid
    if (temp->next == NULL)
        return head;

    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}
// Search element
int search(struct Node* head, int key) {
    struct Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free entire list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    head = insertBeginning(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertPosition(head, 15, 2);

    display(head);

    head = deleteBeginning(head);
    display(head);

    head = deleteEnd(head);
    display(head);

    head = deletePosition(head, 2);
    display(head);

    int pos = search(head, 15);
    if (pos != -1)
        printf("Found at position: %d\n", pos);
    else
        printf("Not found\n");

    freeList(head);

    return 0;
}
