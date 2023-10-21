using System;

template < typename T >
class ArrayList
{
    private:

    T* arr; // указатель на динамический массив
    int capacity; // текущая ёмкость массива
    int size; // текущий размер массива

    public:

    ArrayList()
    {

        capacity = 10; // начальная ёмкость массива
        size = 0;
        arr = new T[capacity]; // выделение памяти для массива

    }

    ~ArrayList()
    {

        delete[] arr; // освобождение памяти

    }

    void add(const T& element) { //функция добавления элемента в массив

        if (size == capacity) {

            // при заполнении массива, увеличиваем ёмкость
            capacity *= 2;
            T* newArr = new T[capacity];

            for (int i = 0; i<size; i++) {

                newArr[i] = arr[i];

            }
delete[] arr;
arr = newArr;

        }

        arr[size] = element;
size++;

    }

    T get(int index)
{ //взять элемент массива
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index out of range");
    }
    return arr[index];
}

void set(int index, const T& element)
{ //добавить элемент по индексу
    if (index < 0 || index >= size)
    {
        throw out_of_range("Index out of range");
    }
    arr[index] = element;
}

void remove(int index)
{ //удалить элемент
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
{ //размер
    return size;
}
};
