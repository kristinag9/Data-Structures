#pragma once
#include "Employee.h"

class Developer : public Employee
{
private:
    bool knowsCpp;
    bool knowsCs;
public:
    Developer(const char* name, unsigned period, double salary, bool knowsCpp, bool knowsCs);

    void setKnowsCpp(bool knowsCpp);
    void setKnowsCs(bool knowsCs);

    bool getKnowsCpp() const;
    bool getKnowsCs() const;

    void print() const;
    Type type()
    {
        return DEVELOPER;
    }
};
