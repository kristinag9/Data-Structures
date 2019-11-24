#pragma once
#include <iostream>

template <class Type>
class LinkedStack
{
    struct Node
    {
        Type data;
        Node* next;

        Node(Type _data, Node* _next = nullptr) : data(_data), next(_next) {}
    };
private:
    Node* pTop;    //A pointer to the top of the stack
    size_t Size;   //Number of elements in the stack

    void copy(const LinkedStack& other);
    void clear();
public:
    LinkedStack();
    LinkedStack(const LinkedStack& other);
    LinkedStack<Type>& operator=(const LinkedStack& other);
    ~LinkedStack();

    void push(size_t elem);
    int pop();
    const Type top() const;
    Type top();
    bool isEmpty() const;
    //bool isFull() const;
};

template <class Type>
void LinkedStack<Type>::copy(const LinkedStack<Type>& other)
{
    if(other.isEmpty())
        return;

    Node *temp1, *temp2;
    pTop = new Node(other.pTop->data);
    temp1 = pTop;
    temp2 = other.pTop->next;

    while(temp2)
    {
        temp1->next = new Node(temp2->data);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    Size = other.Size;
}

template <class Type>
void LinkedStack<Type>::clear()
{
    Node* p;
    while(pTop)
    {
        p = pTop;
        pTop = pTop->next;
        delete p;
    }
    return isEmpty();
}

template <class Type>
LinkedStack<Type>::LinkedStack()
{
    pTop = nullptr;
    Size = 0;
}

template <class Type>
LinkedStack<Type>::LinkedStack(const LinkedStack& other)
{
    copy(other);
}

template <class Type>
LinkedStack<Type>& LinkedStack<Type>::operator=(const LinkedStack& other)
{
    if(this != &other)
    {
        clear();
        copy(other);
    }
    return *this;
}

template <class Type>
LinkedStack<Type>::~LinkedStack()
{
    clear();
}

template <class Type>
void LinkedStack<Type>::push(size_t elem)
{
    Node* node = new Node(elem, pTop);
    pTop = elem;
}

template <class Type>
int LinkedStack<Type>::pop()
{
    Node* temp = pTop;
    if(!temp)
        throw "Error.\n";
    int x = temp->data;
    pTop = temp->next;
    delete temp;

    return x;
}

template <class Type>
const Type LinkedStack<Type>::top() const
{
    if(isEmpty())
        throw "Invalid size.\n";
    return pTop->data;
}

template <class Type>
Type LinkedStack<Type>::top()
{
    if(!isEmpty())
        return pTop->data;
    throw "Invalid data.\n";
}

template <class Type>
bool LinkedStack<Type>::isEmpty() const
{
    return pTop = nullptr;
}

/*
template <class Type>
bool LinkedStack<Type>::isFull() const
{
    return prealloc != NULL;
}*/
