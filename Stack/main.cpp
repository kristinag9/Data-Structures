#include <iostream>
#include <cstring>
#include <cassert>
#include "Stack.h"

//check if a given word is a palindrome, using a stack
bool isPalindrome(const std::string& word)
{
    bool isPali = true;
    Stack<char> reversed;
    for(unsigned i = 0; i < word.size(); i++)
    {
        reversed.Push(word[i]);
    }

    for(unsigned i = 0; i < word.size(); i++)
    {
        if(reversed.top() != word[i])
        {
            isPali = false;
            break;
        }
        reversed.Pop();
    }
    return isPali;
}


//remove the min element of a stack
Stack<int> removeMin(Stack<int> s)
{
    Stack<int> reversed;
    int min = INT_MAX;
    if(!s.isEmpty())     //s.size()
    {
        if(min > s.Pop())
        {
            min = s.top();
        }
        reversed.Push(s.top());
        s.Pop();
    }

    Stack<int> tmp;
    while(!tmp.isEmpty())
    {
        if(tmp.top() == min)
        {
            tmp.Pop();
            continue;
        }
        s.Push(tmp.top());
        tmp.Pop();
    }
}


//copy a stack
void copyStack(Stack<unsigned> orig)
{
    for(unsigned i = 0; i < 10; ++i)
    {
        orig.Push(i);
    }

    Stack<unsigned> tmp, cpy;
    while(!orig.isEmpty())
    {
        tmp.Push(orig.top());
        orig.Pop();
    }
    while(!tmp.isEmpty())
    {
        cpy.Push(tmp.top());
        orig.Push(tmp.top());
        tmp.Pop();
    }

    std::cout << "Original stack | Copied stack: " << std::endl;
    while(!orig.isEmpty())
    {
        std::cout << orig.top() << " | " << cpy.top() << std::endl;
        orig.Pop();
        cpy.Pop();
    }
}

//reverse a stack
void reverseStack(Stack<unsigned> orig)
{
    for(unsigned i = 0; i < 10; ++i)
    {
        orig.Push(i);
    }

    Stack<unsigned> tmp, cpy;
    while(!orig.isEmpty())
    {
        tmp.Push(orig.top());
        orig.Pop();
    }
    while(!tmp.isEmpty())
    {
        cpy.Push(tmp.top());
        tmp.Pop();
    }
    while(!cpy.isEmpty())
    {
        orig.Push(cpy.top());
        cpy.Pop();
    }
    std::cout << "Reversed: " << std::endl;
    while(!orig.isEmpty())
    {
        std::cout << orig.top() << std::endl;
        orig.Pop();
    }
}

//--------------------------------------Validation of an expression------------------------------------//
const char* openBraces = "([{<";
const char* closeBraces = ")]}>";

//a function that check if the character is an open brace
bool isOpen(char c)
{
    return strchr(openBraces, c) != nullptr;
}

//a function that check if the character is a close brace
bool isClose(char c)
{
    return strchr(closeBraces, c) != nullptr;
}

//a function which checks two braces and return true only if they are matched
bool isMatch(char open, char close)
{
    assert(isOpen(open) && isClose(close));
    int openPos = strchr(openBraces, open) - openBraces;
    int closePos = strchr(closeBraces, close) - closeBraces;
    return openPos == closePos;
}

//the function for checking whether an expression is valid (the braces in it are matched) or not
bool isBalanced(const std::string& expr)
{
    Stack<char> st;
    for(size_t i = 0; i < expr.size(); ++i)
    {
        if(isOpen(expr[i]))
        {
            st.Push(expr[i]);
        }
        else if(isClose(expr[i]))
        {
            if(st.isEmpty())
                return false;
            if(!isMatch(st.top(), expr[i]))
                return false;
        st.Pop();
    }
    return (st.isEmpty());
    }
}
/*
//this is a little bit easier way to check an expression validation
//without using so many helper functions
bool isBalanced(const std::string& expr)
{
    Stack<char> st;
    for(size_t i = 0, sz = expr.size(); i < sz; ++i)
    {
        if(isOpen(expr[i])){
            st.Push(expr[i]);
        }
        else if(isClose(expr[i]))
        {
            if(st.isEmpty())
                return false;
            switch(expr[i])
            {
            case ')' :
                if(st.top() == '(')
                    st.Pop();
                break;
            case '}' :
                if(st.top() == '{')
                    st.Pop();
                break;
            case ']' :
                if(st.top() == '[')
                    st.Pop();
                break;
            case '>' :
                if(st.top() == '<')
                    st.Pop();
                break;
            }

        }
    }
    return (st.isEmpty());
}
*/

//-------------------------------------Calculating an expression---------------------------------------//
//a function for the priority of the main operators
int precedence(char c)
{
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
    Stack<char> st;
    for(size_t i = 0; i < expr.size(); ++i)
    {
        if(expr[i] == '(')
                st.Push(expr[i]);
        else if(expr[i] != '(')
        {
            while(!st.isEmpty() && st.top() != ')')
            {
                postfixNotation.push_back(st.top());
                st.Pop();
            }
            st.Pop();
        }
        else if((expr[i] >= '0' && expr[i] <= '9') || (expr[i] >= 'a' && expr[i] <= 'z'))
        {
            postfixNotation.push_back(expr[i]);
        }
        else
        {
            while(!st.isEmpty() && precedence(st.top()) >= precedence(expr[i]))
            {
                postfixNotation.push_back(expr[i]);
                st.Pop();
            }
            st.Push(expr[i]);
        }
    }
    while(!st.isEmpty())
    {
        postfixNotation.push_back(st.top());
        st.Pop();
    }
    return postfixNotation;
}

//calculating an expression using the functions above
int calculateExpr(const std::string& expr)
{
    std::string toRPN = infixToPostfix(expr);
    Stack<int> st;
    for(size_t i = 0; i < toRPN.size(); ++i)
    {
        if(toRPN[i] >= '0' && toRPN[i] <= '9')
        {
            st.Push(toRPN[i] - '0');
        }
        else
        {
            int right = st.top();
            st.Pop();
            int left = st.top();
            st.Pop();
            switch(toRPN[i])
            {
            case '+':
                st.Push(left + right);
                break;
            case '-':
                st.Push(left - right);
                break;
            case '*':
                st.Push(left * right);
                break;
            case '/':
                st.Push(left / right);
                break;
            }
        }
    }
    return st.top();
}

int main()
{
    Stack<unsigned> st;
    copyStack(st);
    reverseStack(st);

    std::cout << infixToPostfix("a+b*c-d*e") << "\n";
    std::cout << infixToPostfix("(a+b)*c") << "\n";
    std::cout << calculateExpr("2*3+4*(5-6)") << "\n";

    std::cout << std::boolalpha << isPalindrome("aabbaa") << "\n";

    std::cout << std::boolalpha
        << isBalanced("(asd[asd{asdasd]}abb)") << " "
        << isBalanced("(asd[asd{asdasd}]abb)") << std::endl;
    return 0;
}
