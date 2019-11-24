#include <iostream>
#include <stack>
#include <string>

//-------------------------Algorithm for converting Postfix expression to Prefix---------------------------//
//1. Read the Postfix expression from left to right
//2. If the symbol is an operand, then push it into the Stack
//3. If the symbol is an operator, then pop two operands from the Stack
//   Create a string by concatenating the two operands and the operator before them.
//   string = operator + operand2 + operand1
//   And push the resultant string back to Stack
//4. Repeat the above steps until end of Prefix expression.

bool isOperator(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

std::string postToPrefix(std::string postExpr)
{
    std::stack<std::string> st;
    int length = postExpr.size();
    for (int i = 0; i < length; i++)
    {
        if (isOperator(postExpr[i]))
        {
            std::string op1 = st.top(); st.pop();
            std::string op2 = st.top(); st.pop();

            std::string temp = postExpr[i] + op2 + op1;

            // Push string temp back to stack
            st.push(temp);
        }
        else
        {
            st.push(std::string(1, postExpr[i]));
        }
    }
    //stack[0] contains the Prefix expression
    return st.top();
}

int main()
{
    std::string postExpr = "ABC/-AK/L-*";
    std::cout << "Prefix : " << postToPrefix(postExpr);
    return 0;
}
