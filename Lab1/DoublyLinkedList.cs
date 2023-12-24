
#include <iostream>
template < typename T >
class DoublyLinkedList
{
    private:
    struct Node
    {
        T data;
        Node* prev;
        Node* next;
    };

    Node* head;
    int size;

    public:
    DoublyLinkedList()
    {
        head = nullptr;
        size = 0;
    }

    ~DoublyLinkedList()
    {
        clear();
    }

    void insertAt(int index, T data)
    {
        if (index < 0 || index > size)
        {
            std::cout << "Error: Index out of range." << std::endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = data;

        if (index == 0)
        {
            newNode->prev = nullptr;
            newNode->next = head;
            if (head != nullptr)
            {
                head->prev = newNode;
            }
            head = newNode;
        }
        else
        {
            Node* current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }

            newNode->prev = current;
            newNode->next = current->next;
            if (current->next != nullptr)
            {
                current->next->prev = newNode;
            }
            current->next = newNode;
        }

        size++;
    }

    void removeAt(int index)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Error: Index out of range." << std::endl;
            return;
        }

        Node* nodeToRemove = head;

        if (index == 0)
        {
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                nodeToRemove = nodeToRemove->next;
            }

            nodeToRemove->prev->next = nodeToRemove->next;
            if (nodeToRemove->next != nullptr)
            {
                nodeToRemove->next->prev = nodeToRemove->prev;
            }
        }

        delete nodeToRemove;
        size--;
    }

    void append(T data)
    {
        insertAt(size, data);
    }

    void prepend(T data)
    {
        insertAt(0, data);
    }

    T get(int index)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "Error: Index out of range." << std::endl;
            return T();
        }

        Node* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->data;
    }

    int getSize()
    {
        return size;
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        size = 0;
    }

    void show()
    {
        Node* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};



