#pragma once
#include "Employee.h"

class Manager : public Employee
{
private:
    int inChargeOf;
public:
    Manager(const char* name, unsigned period, double salary, int inChargeOf);

    void setInChargeOf(int inChargeOf);
    int getInChargeOf() const;

    void print() const;

    Type type()
    {
        return MANAGER;
    }
};
