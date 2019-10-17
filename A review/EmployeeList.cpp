#include "EmployeeList.h"

void EmployeeList::resize()
{
    Employee** temp = new Employee*[capacity*2];
    for(int i = 0; i< this->size; i++)
    {
        temp[i] = employees[i];
    }
    this->erase();
    employees = temp;
    this->capacity *= 2;
}

void EmployeeList::copy(const EmployeeList& other) //= delete
{
    this->capacity = other.capacity;
    this->size = other.size;
    this->employees = new Employee*[other.capacity];
}

void EmployeeList::erase()
{
    delete this->employees;
}

EmployeeList::EmployeeList()
{
    this->size = 0;
    this->capacity = 3;
    employees = new Employee*[this->capacity];
}

EmployeeList::EmployeeList(const EmployeeList& other)
{
    this->copy(other);
}

EmployeeList& EmployeeList::operator=(const EmployeeList& other)
{
    if(this != &other)
    {
        this->copy(other);
        this->erase();
    }
    return *this;
}

EmployeeList::~EmployeeList()
{
    for(int i = 0; i < this->size; i++)
    {
        delete employees[i];
    }
}

void EmployeeList::map(void*(op)(Employee*))
{
    for(int i = 0; i < this->size; i++)
        op(employees[i]);
}

void EmployeeList::filter(bool(*pred)(Employee*))
{
    for(int i = 0; i < this->size; i++)
    {
        if(pred(employees[i]))
        {
            delete employees[i];
            employees[i] = NULL;
        }
        int write = 0;                                //write => there is an element corresponding to the current predicate
        for(int read = 0; read < this->size; read++)  //read => when an element is different from zero
        {
            if(employees[read])
            {
                employees[write++] = employees[read];
            }
        }
        this->size = write;
    }
}

double EmployeeList::accumulate(double(*op)(Employee* e), double(*comp)(double,double),double nullVal)
{
    double result;
    for(int i = 0; i < this->size; i++)
    {
        result = comp(result, op(employees[i]));
                //plus(result, getSalary());
    }
    return result;
}


