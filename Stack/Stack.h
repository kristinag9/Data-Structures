#pragma once
#include <iostream>

template <class Type>
class Stack
{
public:
    Stack();
    Stack(unsigned maxsize);
    Stack(const Stack<Type>& other);
    Stack& operator=(const Stack<Type>& other);
    ~Stack();

    void Push(Type element);
    unsigned Pop();
    int top() const;
    bool isEmpty() const;
    bool isFull() const;
    unsigned getSize() const;
private:
    Type* arr;
    unsigned maxsize;    //capacity
    unsigned tos;        //size
};

template <class Type>
 Stack<Type>::Stack()
 {
     this->maxsize = 0;
     this->tos = 0;
     this->arr = new Type[this->maxsize];
 }

template<class Type>
Stack<Type>::Stack(unsigned maxsize)
{
    this->maxsize = maxsize;
    this->tos = 0;
    this->arr = new Type[maxsize];
}

template<class Type>
Stack<Type>::Stack(const Stack<Type>& other)
{
    this->maxsize = other.maxsize;
    this->tos = other.tos;
    this->arr = new Type[other.maxsize];
    for(unsigned i = 0; i < maxsize; i++)
    {
        arr[i] = other.arr[i];
    }
}

template<class Type>
Stack<Type>& Stack<Type>::operator=(const Stack<Type>& other)
{
    if(this != &other)
    {
        this->maxsize = other.maxsize;
        this->tos = other.tos;
        this->arr = new Type[other.maxsize];
        for(unsigned i = 0; i < maxsize; i++)
        {
            arr[i] = other.arr[i];
        }
        delete [] arr;
    }
    return *this;
}

template<class Type>
Stack<Type>::~Stack()
{
    delete [] arr;
}

template<class Type>
void Stack<Type>::Push(Type element)
{
    if(isFull())
    {
        throw "There is not enough place for more elements.\n";
    }
    arr[tos++] = element;
}

template<class Type>
unsigned Stack<Type>::Pop()
{
    if(isEmpty())
    {
        throw "There are not any elements in the stack!\n";
    }
    return arr[--tos];
}

template<class Type>
int Stack<Type>::top() const
{
    return arr[tos - 1];
}

template<class Type>
bool Stack<Type>::isEmpty() const
{
    return tos == 0;
}

template<class Type>
bool Stack<Type>::isFull() const
{
    return tos == maxsize;
}

template<class Type>
unsigned Stack<Type>::getSize() const
{
    return this->maxsize;
}
