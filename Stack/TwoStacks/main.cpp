#include <iostream>

//Implementing two stacks
class twoStacks
{
private:
    int *arr;
    int size;
    int top1, top2;
public:
    twoStacks(int size)
    {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = this->size;
    }

    void push1(int x)
    {
        if(top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            std::cout << "Overflow\n";
            exit(1);
        }
    }

    void push2(int x)
    {
        if(top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            std::cout << "Overflow.\n";
            exit(1);
        }
    }

    int pop1()
    {
        if(top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
        {
            std::cout << "Underflow.\n";
            exit(1);
        }
    }

    int pop2()
    {
        if(top2 < this->size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
        {
            std::cout <<"Underflow.\n";
            exit(1);
        }
    }
};

int main()
{
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    std::cout << "Popped element from stack1 is " << ts.pop1() << "\n";
    ts.push2(40);
    std::cout << "Popped element from stack2 is " << ts.pop2();

    return 0;
}
