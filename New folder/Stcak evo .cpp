#include <iostream>
#define MAX 10
using namespace std;

// Creating a stack
struct stack {
  int items[MAX];
  int top;
};

// Function to create an empty stack
void createEmptyStack(stack *s) {
  s->top = -1;
}

// Check if the stack is full
bool isFull(stack *s) {
  return s->top == MAX - 1;
}

// Check if the stack is empty
bool isEmpty(stack *s) {
  return s->top == -1;
}

// Add elements into stack
void push(stack *s, int newitem) {
  if (isFull(s)) {
    cout << "STACK FULL" << endl;
  } else {
    s->top++;
    s->items[s->top] = newitem;
    cout << "Item pushed: " << newitem << endl;
  }
}

// Remove element from stack
void pop(stack *s) {
  if (isEmpty(s)) {
    cout << "STACK EMPTY" << endl;
  } else {
    cout << "Item popped: " << s->items[s->top] << endl;
    s->top--;
  }
}

// Print elements of stack
void printStack(stack *s) {
  if (isEmpty(s)) {
    cout << "Stack is empty" << endl;
  } else {
    cout << "Stack elements:" << endl;
    for (int i = 0; i <= s->top; i++) {
      cout << s->items[i] << endl;
    }
  }
}

int main() {
  stack s;
  createEmptyStack(&s);

  push(&s, 1);
  push(&s, 2);
  push(&s, 3);
  push(&s, 4);
  push(&s, 10);
  push(&s, 20);
  push(&s, 30);
  push(&s, 40);
  push(&s, 12);
  push(&s, 22);

  printStack(&s);

  pop(&s);
  pop(&s);

  cout << "After popping out:" << endl;
  printStack(&s);

  return 0;
}
