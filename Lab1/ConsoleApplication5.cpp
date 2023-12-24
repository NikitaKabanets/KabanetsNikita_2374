#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include<iostream>
#include "DoublyLinkedList.cs"

#define SIZE 10

using namespace std;

// реализация stack
class Stack
{
    string* arr;
    int top;
    int capacity;

public:

    Stack(int size = SIZE);         // конструктор
    ~Stack();                       // деструктор

    void push(string&);
    string& pop();
    string& peek();

    int size();
    bool isEmpty();
    bool isFull();

};

// конструктор для инициализации stack
Stack::Stack(int size)
{

    arr = new string[size];
    capacity = size;
    top = -1;

}

// деструктор
Stack::~Stack() {

    delete[] arr;

}

//  функция для добавления элемента в stack
void Stack::push(string& x)
{
    if (isFull())
    {
        cout << "Overflow\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << x << endl;
    arr[++top] = x;

}

// функция для извлечения верхнего элемента из stack
string& Stack::pop()
{
    // проверка на опустошение stack
    if (isEmpty())
    {

        cout << "Underflow\n";
        exit(EXIT_FAILURE);

    }

    cout << "Removing " << peek() << endl;

    return arr[top--];

}

// функция для возврата верхнего элемента stack
string& Stack::peek()
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

vector<string> tokenize(const string& input) {

    vector<string> tokens;
    istringstream iss(input);
    string token;

    while (iss >> token) {

        tokens.push_back(token);

    }

    return tokens;
}

bool isOperator(const string& token) {

    return (token == "+" || token == "-" || token == "*" || token == "/" || token == "^" || token == "sin" || token == "cos");

}

int getPrecedence(const string& token) {

    if (token == "+" || token == "-") {

        return 1;

    }
    else if (token == "*" || token == "/") {

        return 2;

    }
    else if (token == "^") {

        return 3;

    }
    else if (token == "sin" || token == "cos") {

        return 4;

    }
    return 0;

}

string infixToPostfix(string& input) {

    vector<string> tokens = tokenize(input);
    string postfix;
    Stack stack;

    for (string& token : tokens) {

        if (isOperator(token)) {

            while (!stack.isEmpty() && (getPrecedence(stack.peek()) >= getPrecedence(token))) {

                postfix += stack.peek() + " ";
                stack.pop();

            }

            stack.push(token);

        }
        else if (token == "(") {
            stack.push(token);
        }
        else if (token == ")") {
            while (!stack.isEmpty() && stack.peek() != "(") {
                postfix += stack.peek();
                postfix += ' ';
                stack.pop();
            }
            if (!stack.isEmpty() && stack.peek() == "(") {
                stack.pop();
            }
        }
        else if (!isOperator(token)) {

            postfix += token + " ";

        }
        

    }

    while (!stack.isEmpty()) {

        postfix += stack.peek() + " ";
        stack.pop();

    }

    return postfix;
}

int main() {

    int a;
    string input = "cos ( 5 - 2 ) / 2";
    string postfix = infixToPostfix(input);
    cout << "Postfix notation: " << postfix << endl;
    cout << "DLL : " << endl;



    DoublyLinkedList<int> dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.prepend(0);
    dll.insertAt(2, 10);
    dll.removeAt(1);
    std::cout << "Element at index 1: " << dll.get(1) << std::endl;
    dll.show();
    std::cout << "Size of the doubly linked list: " << dll.getSize() << std::endl;

    return 0;

}


