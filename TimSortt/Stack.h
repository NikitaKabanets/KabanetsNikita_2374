
class Stack
{
    string* arr;
    int top;
    int capacity;

public:

    Stack(int size = 100);         // �����������
    ~Stack();                       // ����������

    void push(string&);
    string& pop();
    string& peek();

    int size();
    bool isEmpty();
    bool isFull();

};

// ����������� ��� ������������� stack
Stack::Stack(int size)
{

    arr = new string[size];
    capacity = size;
    top = -1;

}

// ����������
Stack::~Stack() {

    delete[] arr;

}

//  ������� ��� ���������� �������� � stack
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

// ������� ��� ���������� �������� �������� �� stack
string& Stack::pop()
{
    // �������� �� ����������� stack
    if (isEmpty())
    {

        cout << "Underflow\n";
        exit(EXIT_FAILURE);

    }

    cout << "Removing " << peek() << endl;

    return arr[top--];

}

// ������� ��� �������� �������� �������� stack
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
