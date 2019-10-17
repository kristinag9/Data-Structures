#include "Manager.h"

Manager::Manager(const char* name, unsigned period, double salary, bool inChargeOf) : Employee(name, period, salary)
{
    this->inChargeOf = inChargeOf;
}

void Manager::print()
{
    Employee::print();
    cout << "In charge of: " << inChargeOf << endl;
}
