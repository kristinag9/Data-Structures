#pragma once
#include <iostream>
#include "Manager.h"
#include "Developer.h"

using namespace std;

class SoftwareCompany
{
public:
    void newEmployee();
    void removeRecentlyEmployed();
    void increaseSalaries();
    void printAll();
    double sumSalaries();
private:
    void readCommonData(Employee *e);

    Developer* createDeveloper();
    Manager* createManager();
    Employee* createEmployee(char type);

    class EmployeeList
    {
    private:
        Employee** employees;
        int size;
        int capacity;
        void resize();
    private:
        //Forbid these operations
        EmployeeList(const EmployeeList& other);
        EmployeeList& operator=(const EmployeeList& other);
    public:
        EmployeeList();
        bool insertEmployee(Employee* newEmployee);
        void map(void(*op)(Employee*));
        void filter(bool(*pred)(Employee*));
        double accumulate(double(*op)(Employee* e), double(*comp)(double,double),double nullVal);
        ~EmployeeList();
    }list;
};
