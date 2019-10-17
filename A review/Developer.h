#pragma once
#include "Employee.h"

class Developer : public Employee
{
private:
    bool knowsCpp;
    bool knowsCs;
public:
    Developer(const char* name, unsigned period, double salary, bool knowsCpp, bool knowsCs);
    Developer& operator=(const Developer& rhs);
    void print();
    Type type()
    {
        return DEVELOPER;
    }
};
