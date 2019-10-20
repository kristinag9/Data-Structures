#pragma once
#include <iostream>

using namespace std;

enum Type
{
    DEVELOPER = 1,
    MANAGER = 2
};

class Employee
{
private:
    char* name;
    unsigned period;
    double salary;

    void copy(const Employee& e);
    void erase();
public:
    Employee(const char* name, unsigned period, double salary);
    Employee(const Employee& e);
    Employee& operator=(const Employee& rhs);

    void setName(const char* name);
    void setPeriod(unsigned period);
    void setSalary(double salary);

    const char* getName() const;
    unsigned getPeriod() const;
    double getSalary() const;

    virtual Type type() = 0;
    virtual void print() const;
    virtual ~Employee();
};
