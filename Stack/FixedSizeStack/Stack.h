#pragma once
#include <iostream>

template <class Type>
class Stack
{
public:
    Stack();
    Stack(unsigned maxsize);
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);
    ~Stack();

    bool Push(Type element);
    unsigned Pop();
    int top() const;
    bool isEmpty() const;
    unsigned getSize() const;
private:
    Type* arr;
    unsigned maxsize;    //capacity
    unsigned tos;        //size
};

template <class Type>
 Stack<Type>::Stack()
 {
     this->arr = nullptr;
     this->maxsize = 0;
     this->tos = 0;
 }

template<class Type>
Stack<Type>::Stack(unsigned maxsize)
{
    this->arr = new Type[maxsize];
    this->maxsize = maxsize;
    this->tos = 0;
}

template<class Type>
Stack<Type>::Stack(const Stack& other)
{
    this->arr = new Type[other.maxsize];
    this->maxsize = other.maxsize;
    this->tos = other.tos;
    for(unsigned i = 0; i < maxsize; i++)
    {
        arr[i] = other.arr[i];
    }
}

template<class Type>
Stack<Type>& Stack<Type>::operator=(const Stack& other)
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
bool Stack<Type>::Push(Type element)
{
    if(tos >= maxsize - 1)
    {
        std::cout << "Stack overflow!\n";
        return false;
    }
    else
    {
        arr[tos++] = element;
        std::cout << element << " is pushed into the stack.\n";
        return true;
    }
}

template<class Type>
unsigned Stack<Type>::Pop()
{
    if(isEmpty())
    {
        std::cout << "Stack underflow!\n";
        return 0;
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
unsigned Stack<Type>::getSize() const
{
    assert(maxsize >= 0);
    return this->maxsize;
}
