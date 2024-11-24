#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertionAtBeginning(Node** head, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void insertionAfter(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "The given previous node is NULL" << endl;
        return;
    }
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertAtEnd(Node** head, int new_data) {
    Node* new_node = new Node();
    Node* last = *head;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void deleteNode(Node** head, int value) {
    Node* temp = *head, *prev = nullptr;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head = nullptr;

    insertAtEnd(&head, 7);
    insertionAtBeginning(&head, 2);
    insertionAtBeginning(&head, 4);
    insertAtEnd(&head, 3);
    insertionAfter(head->next, 1);

    cout << "Linked list: ";
    printList(head);
    cout << "\nAfter deleting a node: ";
    deleteNode(&head, 1);
    printList(head);

    return 0;
}
