#include "Employee.h"
#include <cstring>

void Employee::copy(const Employee& e)
{
    setName(e.name);
    setPeriod(e.period);
    setSalary(e.salary);
    /*
    this->erase();
    this->name = new char[strlen(e.name) + 1];
    strcpy(this->name, e.name);
    this->period = e.period;
    this->salary = e.salary;
    */
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
    this->erase();
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Employee::setPeriod(unsigned period)
{
    this->period = period;
}

void Employee::setSalary(double salary)
{
    this->salary = salary;
}

const char* Employee::getName() const
{
    return this->name;
}

unsigned Employee::getPeriod() const
{
    return this->period;
}

double Employee::getSalary() const
{
    return this->salary;
}

void Employee::print()
{
    cout << "Name: " << this->name << endl;
    cout << "Period: " << this->period << endl;
    cout << "Salary: " << this->salary << endl;
}
