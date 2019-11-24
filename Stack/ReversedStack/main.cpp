#include <iostream>
#include <stack>

void reverseStack(std::stack<unsigned> orig)
{
    for(size_t i = 0; i < 10; i++)
    {
        orig.push(i);
    }

    std::stack<unsigned> temp, cpy;
    while(!orig.empty())
    {
        temp.push(orig.top());
        orig.pop();
    }
    while(!temp.empty())
    {
        cpy.push(temp.top());
        temp.pop();
    }
    while(!cpy.empty())
    {
        orig.push(cpy.top());
        cpy.pop();
    }

    std::cout << "Reversed stack: " << std::endl;
    while(!orig.empty())
    {
        std::cout << orig.top() << std::endl;
        orig.pop();
    }
}

int main()
{
    std::stack<unsigned> st;
    reverseStack(st);

    return 0;
}
