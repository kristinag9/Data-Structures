#include "Developer.h"

Developer::Developer(const char* name, unsigned period, double salary, bool knowsCpp, bool knowsCs) : Employee(name, period, salary)
{
    this->knowsCpp = knowsCpp;
    this->knowsCs = knowsCs;
}

void Developer::setKnowsCpp(bool knowsCpp)
{
    this->knowsCpp = knowsCpp;
}

void Developer::setKnowsCs(bool knowsCs)
{
    this->knowsCs = knowsCs;
}

bool Developer::getKnowsCpp() const
{
    return knowsCpp;
}

bool Developer::getKnowsCs() const
{
    return knowsCs;
}

void Developer::print() const
{
    cout << "Developer" << endl;
    Employee::print();
    cout << "Knows Cpp: " << (knowsCpp ? "yes" : "no") << endl;
    cout << "Knows Cs: " << (knowsCs ? "yes" : "no") << endl;
}

