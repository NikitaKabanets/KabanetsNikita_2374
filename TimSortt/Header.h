#include <iostream>
using namespace std;

class Stack
{
    int* arr;
    int top;
    int capacity;

public:

    Stack(int size = 1000);         // конструктор
    ~Stack();                       // деструктор

    void push(const int&);
    int& pop();
    int& peek();

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
void Stack::push(const int& x) 
{
    if (isFull())
    {

        exit(EXIT_FAILURE);
    }
    arr[++top] = x;

}

// функция для извлечения верхнего элемента из stack
int& Stack::pop()
{
    // проверка на опустошение stack
    if (isEmpty())
    {

        exit(EXIT_FAILURE);

    }

    return arr[top--];

}

// функция для возврата верхнего элемента stack
int& Stack::peek()
{

    if (!isEmpty())
    {

        return arr[top];

    }
    else
    {

        exit(EXIT_FAILURE);

    }
}

// функция для возврата размера стека
int Stack::size()
{

    return top + 1;
}

// проверка пустоты стека
bool Stack::isEmpty()
{

    return top == -1;

}

// проверка заполненности стека
bool Stack::isFull()
{

    return top == capacity - 1;

}
