#include <iostream>
#include <stack>

//----------------------------Algorithm-------------------------//
//1. Create a temporary stack say tmpStack.
//2. While input stack is NOT empty do this:
//   - Pop an element from input stack call it temp
//   - while temporary stack is NOT empty and top of temporary stack is greater than temp,
//   pop from temporary stack and push it to the input stack
//   - push temp in temporary stack
//3. The sorted numbers are in tmpStack

std::stack<unsigned> sortedStack(std::stack<unsigned> orig)
{
    std::stack<unsigned> tmpStack;
    while(!orig.empty())
    {
        int temp = orig.top();
        orig.pop();
        while(!tmpStack.empty() && tmpStack.top() > temp)
        {
            orig.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(temp);
    }
    return tmpStack;
}

int main()
{
    std::stack<unsigned> orig;
    orig.push(34);
    orig.push(3);
    orig.push(31);
    orig.push(98);
    orig.push(92);
    orig.push(23);

    // This is the temporary stack
    std::stack<unsigned> tmpStack = sortedStack(orig);
    std::cout << "Sorted numbers are:\n";

    while (!tmpStack.empty())
    {
        std::cout << tmpStack.top()<< " ";
        tmpStack.pop();
    }
    return 0;
}
