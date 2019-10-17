#pragma once
#include "Employee.h"

class EmployeeList
{
private:
    Employee** employees;
    int size;
    int capacity;

    void resize();
    void copy(const EmployeeList& other);
    void erase();
public:
    EmployeeList();
    EmployeeList(const EmployeeList& other);             //= delete
    EmployeeList& operator=(const EmployeeList& other);  //forbid the assumption
    ~EmployeeList();
    void InsertEmployee(Employee*);
    void map(void*(op)(Employee*));
    void filter(bool(*pred)(Employee*));
    double accumulate(double(*op)(Employee* e), double(*comp)(double,double),double nullVal);
    //funReturn(*funName)(Arg..);
};
