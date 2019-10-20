#include "Manager.h"

Manager::Manager(const char* name, unsigned period, double salary, int inChargeOf) : Employee(name, period, salary)
{
    this->inChargeOf = inChargeOf;
}

void Manager::setInChargeOf(int inChargeOf)
{
    if (inChargeOf < 0)
    {
        throw runtime_error("Invalid in charge of value");
    }
    this->inChargeOf = inChargeOf;
}

int Manager::getInChargeOf() const
{
    return this->inChargeOf;
}

void Manager::print() const
{
    cout << "Manager" << endl;
    Employee::print();
    cout << "In charge of: " << inChargeOf << endl;
}
