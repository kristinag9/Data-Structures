#include "Developer.h"

Developer::Developer(const char* name, unsigned period, double salary, bool knowsCpp, bool knowsCs) : Employee(name, period, salary)
{
    this->knowsCpp = knowsCpp;
    this->knowsCs = knowsCs;
}
Developer& Developer::operator=(const Developer& rhs)
{
    if(this != &rhs)
    {
        Employee::operator=(rhs);
        knowsCpp = rhs.knowsCpp;
        knowsCs = rhs.knowsCs;
    }
    return *this;
}

void Developer::print()
{
    Employee::print();
    cout << "Knows Cpp: " << knowsCpp << endl;
    cout << "Knows Cs: " << knowsCs << endl;
}

