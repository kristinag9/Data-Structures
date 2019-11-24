#include <iostream>
#include <stack>

//a function for the precedence of the main operators
int precedence(char op)
{
    if(op == '*' || op == '/')
        return 2;
    if(op == '+' || op == '-')
        return 1;
    return 0;
}

std::string infixToPostfix(const std::string& expr)
{
    std::string postfixNotation;
    std::stack<char> st;
    for(size_t i = 0; i < expr.size(); ++i)
    {
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


int calculateExpr(const std::string& expr)
{
    std::string toRPN = infixToPostfix(expr);
    std::stack<int> st;
    for(size_t i = 0; i < toRPN.size(); ++i)
    {
        if(toRPN[i] >= '0' && toRPN[i] <= '9')
        {
            st.push(toRPN[i] - '0');
        }
        else
        {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();
            switch(toRPN[i])
            {
            case '+':
                st.push(left + right);
                break;
            case '-':
                st.push(left - right);
                break;
            case '*':
                st.push(left * right);
                break;
            case '/':
                st.push(left / right);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    std::cout << infixToPostfix("a+b*c-d*e") << "\n";
    std::cout << infixToPostfix("(a+b)*c") << "\n";
    std::cout << calculateExpr("2*3+4*(5-6)") << "\n";
    return 0;
}
