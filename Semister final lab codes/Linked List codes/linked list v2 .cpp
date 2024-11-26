#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* second = new Node{20, nullptr};
    Node* third = new Node{30, nullptr};
    head = new Node{10, second};
    second->next = third;

    insert(head, 40);
    printList(head);

    return 0;
}
