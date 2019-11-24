#include <iostream>
#include <stack>

//---------------------Algorithm for converting Prefix expression to Postfix-------------------//
//1. Read the Prefix expression in reverse order (from right to left)
//2. If the symbol is an operand, then push it onto the stack
//3. If the symbol is an operator, then pop two operands from the Stack
//   Create a string by concatenating the two operands and the operator after them.
//   string = operand1 + operand2 + operator
//   and push the resultant string back to stack
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

std::string preToPostfix(std::string preExpr)
{
    std::stack<std::string> st;
    int length = preExpr.size();
    for(int i = length; i >= 0; i++)
    {
        if(isOperator(preExpr[i]))
        {
            std::string op1 = st.top(); st.pop();
            std::string op2 = st.top(); st.pop();

            std::string temp = op1 + op2 + preExpr[i];
            st.push(temp);
        }
        else
        {
            st.push(std::string(1, preExpr[i]));
        }
    }
    return st.top();
}

int main()
{
    std::string preExpr = "*-A/BC-/AKL";
    std::cout << "Postfix : " << preToPostfix(preExpr);
    return 0;
}
