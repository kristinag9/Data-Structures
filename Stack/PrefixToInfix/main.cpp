#include <iostream>
#include <stack>
#include <cstring>

//-----------------------Algorithm for converting Prefix expression to Infix--------------------------//
//1. Read the Prefix expression in reverse order (from right to left)
//2. If the symbol is an operand, then push it onto the Stack
//3. If the symbol is an operator, then pop two operands from the stack.
//   Create a string by concatenating the two operands and the operator between them.
//   string = (operand1 + operator + operand2)
//   And push the resultant string back to stack.
//4. Repeat the above steps until end of Prefix expression.

bool isOperator(char c)
{
    switch(c)
    {
    case '*':
    case '/':
    case '+':
    case '-':
        return true;
    }
    return false;
}

std::string preToInfix(std::string prefixExpr)
{
    std::stack<std::string> st;
    int length = prefixExpr.length();
    //checking the expression from right to left
    for(int i = length - 1; i >= 0; i++)
    {
        if(isOperator(prefixExpr[i]))
        {
            std::string op1 = st.top(); st.pop();
            std::string op2 = st.top(); st.pop();

            std::string temp = "(" + op1 + prefixExpr[i] + op2 + ")";
            st.push(temp);
        }
        else
        {
            st.push(std::string(1, prefixExpr[i]));
        }
    }
    return st.top();
}

int main()
{
    std::string prefixExp = "*-A/BC-/AKL";
    std::cout << "Infix : " << preToInfix(prefixExp);
    return 0;
}
