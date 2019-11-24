#include <iostream>
#include <stack>

//removing min element of a stack
std::stack<int> removeMin(std::stack<int> st)
{
    std::stack<int> reversed;
    int minElem = INT_MIN;
    while(!st.empty())
    {
        if(minElem > st.top())
        {
            minElem = st.top();
        }
        reversed.push(st.top());
        st.pop();
    }

    std::stack<int> temp;
    while(!temp.empty())
    {
        if(temp.top() == minElem)
        {
            temp.pop();
            continue;
        }
        st.push(temp.top());
        temp.pop();
    }
}

int main()
{
    std::stack<int> s;
    s.push(2);
    s.push(4);
    s.push(1);
    removeMin(s);
    return 0;
}
