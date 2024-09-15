#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

// Function to perform arithmetic operations
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> values;

    for (char c : postfix) {
        // If the character is a digit, push it to the stack
        if (isdigit(c)) {
            values.push(c - '0');  // Convert char to int
        }
        // If the character is an operator, pop two values from the stack and apply the operator
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            int val2 = values.top(); values.pop();
            int val1 = values.top(); values.pop();
            int result = applyOp(val1, val2, c);
            values.push(result);
        }
    }

    // The final result will be at the top of the stack
    return values.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression (single digits, no spaces): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result of evaluation: " << result << endl;

    return 0;
}
