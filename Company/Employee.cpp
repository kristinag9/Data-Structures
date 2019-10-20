#include "Employee.h"
#include <cstring>

void Employee::copy(const Employee& e)
{
    setName(e.name);
    setPeriod(e.period);
    setSalary(e.salary);
}

void Employee::erase()
{
    delete [] this->name;
}

Employee::Employee(const char* name, unsigned period, double salary)
{
    setName(name);
    setPeriod(period);
    setSalary(salary);
}

Employee::Employee(const Employee& e)
{
    this->copy(e);
}

Employee& Employee::operator=(const Employee& rhs)
{
    if(this != &rhs)
    {
        this->erase();
        this->copy(rhs);
    }
    return *this;
}

Employee::~Employee()
{
    this->erase();
}

void Employee::setName(const char* name)
{
    if (!name)
    {
        throw runtime_error("Invalid name");
    }
    this->erase();
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Employee::setPeriod(unsigned period)
{
    if (period < 0)
    {
        throw runtime_error("Invalid period");
    }
    this->period = period;
}

void Employee::setSalary(double salary)
{
    if (salary < 0)
    {
        throw runtime_error("Invalid salary");
    }
    this->salary = salary;
}

const char* Employee::getName() const
{
    return name;
}

unsigned Employee::getPeriod() const
{
    return period;
}

double Employee::getSalary() const
{
    return salary;
}

void Employee::print() const
{
    cout << "Name: " << name << endl;
    cout << "Period: " << period << endl;
    cout << "Salary: " << salary << endl;
}
