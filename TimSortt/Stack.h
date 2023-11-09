
class Stack
{
    string* arr;
    int top;
    int capacity;

public:

    Stack(int size = 100);         // конструктор
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
