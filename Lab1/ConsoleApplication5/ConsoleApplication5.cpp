#include <iostream>
#include <cstdlib>
#include <Windows.h>

using namespace std;

// емкость stack по умолчанию
#define SIZE 10

// реализация stack
class Stack
{
    int* arr;
    int top;
    int capacity;

public:

    Stack(int size = SIZE);         // конструктор
    ~Stack();                       // деструктор

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();

};

// конструктор для инициализации stack
Stack::Stack(int size)
{

    arr = new int[size];
    capacity = size;
    top = -1;

}

// деструктор
Stack::~Stack() {

    delete[] arr;

}

//  функция для добавления элемента в stack
void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Overflow\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << char(x) << endl;
    arr[++top] = x;

}

// функция для извлечения верхнего элемента из stack
int Stack::pop()
{
    // проверка на опустошение stack
    if (isEmpty())
    {

        cout << "Underflow\n";
        exit(EXIT_FAILURE);

    }

    cout << "Removing " << char(peek()) << endl;

    return arr[top--];

}

// функция для возврата верхнего элемента stack
int Stack::peek()
{

    if (!isEmpty()) {

        return arr[top];

    }
    else {

        exit(EXIT_FAILURE);

    }
}

// функция для возврата размера стека
int Stack::size() {

    return top + 1;
}

// проверка пустоты стека
bool Stack::isEmpty() {

    return top == -1; 

}

// проверка заполненности стека
bool Stack::isFull() {

    return top == capacity - 1;

}


bool isOperator(const char& token) {
    return token == '+' || token == '-' || token == '*' || token == '/' || token == '^';
}

bool isFunction(const std::string& token) {
    return token == "sin" || token == "cos";
}

int getPrecedence(const char& token) {
    if (token == '+' || token == '-') {
        return 1;
    }
    else if (token == '*' || token == '/') {
        return 2;
    }
    else if (token == '^') {
        return 3;
    }
    else if (token == reinterpret_cast<char>("sin") || token == reinterpret_cast<char>("cos")) {
        return 4;
    }
    return 0;
}

string infixToPostfix(const string& expression) {
    Stack operatorStack;
    string postfix;

    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ') {
            continue;
        }

        if (isOperator(expression[i])) {
            while (!operatorStack.isEmpty() && isOperator(operatorStack.peek()) && getPrecedence(operatorStack.peek()) >= getPrecedence(expression[i])) {
                postfix += operatorStack.peek();
                postfix += ' ';
                operatorStack.pop();
            }
            operatorStack.push(expression[i]);
        }
        else if (isFunction(expression.substr(i, 3))) {
            operatorStack.push(expression[i+2]);
            operatorStack.push(expression[i+1]);
            operatorStack.push(expression[i]);
            i += 2;
        }
        else if (expression[i] == '(') {
            operatorStack.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                postfix += operatorStack.peek();
                postfix += ' ';
                operatorStack.pop();
            }
            if (!operatorStack.isEmpty() && operatorStack.peek() == '(') {
                operatorStack.pop();
            }
        }
        else {
            while (i < expression.length() && isdigit(expression[i])) {
                postfix += expression[i];
                i++;
            }
            postfix += ' ';
            i--;
        }
    }

    while (!operatorStack.isEmpty()) {
        postfix += operatorStack.peek();
        if ((const char*)operatorStack.peek() != "c" && (const char*)operatorStack.peek() != "o" && (const char*)operatorStack.peek() != "s" && (const char*)operatorStack.peek() != "i") {
            postfix += ' ';
        }
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    string postfix = infixToPostfix(expression);
    cout << "Postfix expression: " << postfix << std::endl;

    return 0;
}




