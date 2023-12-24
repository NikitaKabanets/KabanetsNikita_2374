#include <iostream>
using namespace std;

class Stack
{
    int* arr;
    int top;
    int capacity;

public:

    Stack(int size = 1000);         // �����������
    ~Stack();                       // ����������

    void push(const int&);
    int& pop();
    int& peek();

    int size();
    bool isEmpty();
    bool isFull();

};

// ����������� ��� ������������� stack
Stack::Stack(int size)
{

    arr = new int[size];
    capacity = size;
    top = -1;

}

// ����������
Stack::~Stack() {

    delete[] arr;

}

//  ������� ��� ���������� �������� � stack
void Stack::push(const int& x) 
{
    if (isFull())
    {

        exit(EXIT_FAILURE);
    }
    arr[++top] = x;

}

// ������� ��� ���������� �������� �������� �� stack
int& Stack::pop()
{
    // �������� �� ����������� stack
    if (isEmpty())
    {

        exit(EXIT_FAILURE);

    }

    return arr[top--];

}

// ������� ��� �������� �������� �������� stack
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

// ������� ��� �������� ������� �����
int Stack::size()
{

    return top + 1;
}

// �������� ������� �����
bool Stack::isEmpty()
{

    return top == -1;

}

// �������� ������������� �����
bool Stack::isFull()
{

    return top == capacity - 1;

}
