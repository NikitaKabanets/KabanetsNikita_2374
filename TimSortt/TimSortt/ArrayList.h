#include <iostream>
using namespace std;

template < typename T >
class ArrayList
{
private:

    T* arr; // ��������� �� ������������ ������
    int capacity; // ������� ������� �������
    int size; // ������� ������ �������

public:

    ArrayList()
    {

        capacity = 10; // ��������� ������� �������
        size = 0;
        arr = new T[capacity]; // ��������� ������ ��� �������

    }

    ~ArrayList()
    {

        delete[] arr; // ������������ ������

    }

    void add(const T& element) { //������� ���������� �������� � ������

        if (size == capacity) {

            // ��� ���������� �������, ����������� �������
            capacity *= 2;
            T* newArr = new T[capacity];

            for (int i = 0; i < size; i++) {

                newArr[i] = arr[i];

            }
            delete[] arr;
            arr = newArr;

        }

        arr[size] = element;
        size++;

    }

    T get(int index)
    { //����� ������� �������
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

    void set(int index, const T& element)
    { //�������� ������� �� �������
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }
        arr[index] = element;
    }

    void remove(int index)
    { //������� �������
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    int getSize()
    { //������
        return size;
    }
};
