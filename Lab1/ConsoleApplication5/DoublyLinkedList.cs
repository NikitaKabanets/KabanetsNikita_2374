using System;

# include <stdlib.h>
# include <iostream.h>

struct Node // узел списка
{

    int x;                             
    Node* Next, *Prev; 
        
 };

class List                              
{

    Node* Head, *Tail; //указатели на начало и конец списка

 public:
     List() :Head(NULL),Tail(NULL) { };   
    ~List();                           
    void Show();                       
    void Add(int x);      
    
};

List::~List() //деструктор

 {
    while (Head)                       
    {

        Tail = Head.Next;             
        delete Head;                   
        Head = Tail;  
        
    }
}

void List::Add(int x)
{

    Node* temp = new Node;               
    temp.Next = NULL;                   
    temp.x = x;                         

    if (Head != NULL) //если список не пустой
    {

        temp.Prev = Tail;
        
    }
    else //если список пустой
    {

        temp.Prev = NULL;               
        Head = Tail = temp;
        
    }
}

void List::Show()
{
    //вывод списка с конца
    Node* temp = Tail;                   

    while (temp != NULL)              
    {

        cout << temp.x << " ";        
        temp = temp.Prev;    
        
    }
    cout << "\n";

    //вывод списка с начала
    temp = Head;                       
    while (temp != NULL)              
    {

        cout << temp.x << " ";        
        temp = temp.Next;  
        
    }

    cout << "\n";
}

