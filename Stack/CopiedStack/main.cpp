#include <iostream>
#include <stack>

void copyStack(std::stack<unsigned> orig)
{
    for(unsigned i = 0; i < 10; i++)
    {
        orig.push(i);
    }

    std::stack<unsigned> tmp,cpy;
    while(!orig.empty())
    {
        tmp.push(orig.top());
        orig.pop();
    }
    while(!tmp.empty())
    {
        cpy.push(tmp.top());
        orig.push(tmp.top());
        tmp.pop();
    }

    std::cout << "Original stack | Copied stack: " << std::endl;
    while(!orig.empty())
    {
        std::cout << orig.top() << " | " << cpy.top() << std::endl;
        orig.pop();
        cpy.pop();
    }
}

int main()
{
    std::stack<unsigned> st;
    copyStack(st);

    return 0;
}
