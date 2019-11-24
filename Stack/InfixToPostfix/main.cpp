#include <iostream>
#include <stack>
#include <cstring>

//a function for the priority of the main operators
int precedence(char c)
{
    if(c == '^')
        return 3;
    if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    return 0;
}

//prefix: (a*b) + (c*d) - e = -e+*ab*cd
//infix: string expr = a*b + c*d - e
//postfix: infixToPostfix = ab*cd*+e-
std::string infixToPostfix(const std::string& expr)
{
    std::string postfixNotation;
    std::stack<char> st;
    for(size_t i = 0; i < expr.size(); ++i)
    {
         //if the scanned character is an '(', push it to the stack.
        if(expr[i] == '(')
                st.push(expr[i]);
        else if(expr[i] != '(')
        {
            while(!st.empty() && st.top() != ')')
            {
                postfixNotation.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if((expr[i] >= '0' && expr[i] <= '9') || (expr[i] >= 'a' && expr[i] <= 'z'))
        {
            postfixNotation.push_back(expr[i]);
        }
        else
        {
            while(!st.empty() && precedence(st.top()) >= precedence(expr[i]))
            {
                postfixNotation.push_back(expr[i]);
                st.pop();
            }
            st.push(expr[i]);
        }
    }
    while(!st.empty())
    {
        postfixNotation.push_back(st.top());
        st.pop();
    }
    return postfixNotation;
}

int main()
{
    std::cout << infixToPostfix("a+b*c-d*e") << "\n";
    std::cout << infixToPostfix("(a+b)*c") << "\n";
    return 0;
}
