#include<iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check if character is an operand (i.e., a number or variable)
bool isOperand(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to convert infix to postfix expression
string infixToPostfix(string infix) {
    stack<char> s;  // Stack to store operators
    string postfix; // Resultant postfix expression

    cout << "Infix to Postfix Conversion Steps:\n";
    cout << "----------------------------------\n";
    for (char& ch : infix) {
        if (isOperand(ch)) {
            postfix += ch;
            cout << "Added operand: " << ch << " to postfix -> " << postfix << endl;
        }
        else if (ch == '(') {
            s.push(ch);
            cout << "Pushed '(' onto stack\n";
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                cout << "Popped operator: " << s.top() << " from stack to postfix -> " << postfix << endl;
                s.pop();
            }
            s.pop();  // Pop the '('
            cout << "Popped '(' from stack\n";
        }
        else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                cout << "Popped operator: " << s.top() << " from stack to postfix -> " << postfix << endl;
                s.pop();
            }
            s.push(ch);
            cout << "Pushed operator: " << ch << " onto stack\n";
        }
    }

    // Pop remaining operators in stack
    while (!s.empty()) {
        postfix += s.top();
        cout << "Popped operator: " << s.top() << " from stack to postfix -> " << postfix << endl;
        s.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(string postfix) {
    stack<int> s;
    for (char& ch : postfix) {
        if (isOperand(ch)) {
            s.push(ch - '0'); // Assume single digit numbers for simplicity
        }
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "\nPostfix expression: " << postfix << endl;

    // Evaluation is only done for numeric expressions (you can skip evaluation for alphabets)
    if (postfix.find_first_not_of("0123456789+-*/") == string::npos) {
        int result = evaluatePostfix(postfix);
        cout << "Postfix evaluation result: " << result << endl;
    }

    return 0;
}
