#pragma once
#include "Employee.h"

class Manager : public Employee
{
private:
    bool inChargeOf;
public:
    Manager(const char* name, unsigned period, double salary, bool inChargeOf);
    void print();
    Type type()
    {
        return MANAGER;
    }
};
