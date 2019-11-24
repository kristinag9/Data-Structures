#include <iostream>
#include <stack>
#include <cstring>

//--------------------------Algorithm for checking if parentheses are balanced---------------------//
//1. Declare a character stack S.
//2. Now traverse the expression string exp.
//   If the current character is a starting bracket ('(' or '{' or '[') then push it to stack.
//   If the current character is a closing bracket (')' or '}' or ']') then pop from stack
//   and if the popped character is the matching starting bracket then fine else parenthesis are not balanced.
//3. After complete traversal, if there is some starting bracket left in stack then “Not balanced”

const char* openBraces = "([{<";
const char* closeBraces = ")]}>";

//a function that checks if the character is an open brace
bool isOpen(char c)
{
    return strchr(openBraces, c) != nullptr;
}

//a function that checks if the character is a close brace
bool isClose(char c)
{
    return strchr(closeBraces, c) != nullptr;
}

//a function for checking whether an expression is valid (the braces in it are matched) or not
bool isBalanced(const std::string& expr)
{
    std::stack<char> st;
    for(size_t i = 0, sz = expr.size(); i < sz; ++i)
    {
        if(isOpen(expr[i])){
            st.push(expr[i]);
        }
        else if(isClose(expr[i]))
        {
            if(st.empty())
                return false;
            switch(expr[i])
            {
            case ')' :
                if(st.top() == '(')
                    st.pop();
                break;
            case '}' :
                if(st.top() == '{')
                    st.pop();
                break;
            case ']' :
                if(st.top() == '[')
                    st.pop();
                break;
            case '>' :
                if(st.top() == '<')
                    st.pop();
                break;
            }

        }
    }
    return (st.empty());
}

int main()
{
    std::string expr = "{()}<[]>";
    if(isBalanced(expr))
        std::cout << "Balanced";
    else
        std::cout << "Not Balanced";
    return 0;
}
