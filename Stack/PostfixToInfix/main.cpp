#include <iostream>
#include <stack>
#include <string>

//-----------------------Algorithm for converting an Postfix expression into Infix-----------------//
//1.While there are input symbol left
//  Read the next symbol from the input.
//2.If the symbol is an operand
//  Push it onto the stack.
//3.Otherwise, the symbol is an operator.
//  Pop the top 2 values from the stack.
//  Put the operator, with the values as arguments and form a string.
//  Push the resulted string back to stack.
//4.If there is only one value in the stack,
//  that value in the stack is the desired infix string.

bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

std::string postToInfix(std::string postExpr)
{
    std::stack<std::string> st;
    for(int i = 0; i != '\0'; i++)
    {
        if(isOperand(postExpr[i]))
        {
            std::string op(1, postExpr[i]);
            st.push(op);
        }
        else
        {
            std::string op1 = st.top(); st.pop();
            std::string op2 = st.top(); st.pop();

            st.push("(" + op2 + postExpr[i] + op1 + ")");
        }
    }
    // There must be a single element in stack now which is the required infix.
    return st.top();
}

int main()
{
    std::string expr = "ab*c+";
    std::cout << postToInfix(expr);
    return 0;
}
