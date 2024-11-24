#include <iostream>
#include <stdlib.h>

using namespace std;

struct node {
    int data;
    struct node *next;
};

void insert(struct node** head, int newdata) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = newdata;
    newnode->next = (*head);
    (*head) = newnode;
}

int main() {
    node *head = NULL;
    node *second = NULL;
    node *third = NULL;

    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    insert(&head, 40);

    struct node *ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }

    return 0;
}
