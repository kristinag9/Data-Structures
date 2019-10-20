#include "SoftwareCompany.h"

bool filterLessThan3Months(Employee* emp);
void printEmployee(Employee* emp);
void increseSalary(Employee* emp);
double getSalary(Employee* emp);
double pluss(double a, double b);

void SoftwareCompany::EmployeeList::resize()
{
    Employee** temp = new Employee*[capacity*2];
    for(int i = 0; i< this->size; i++)
    {
        temp[i] = employees[i];
    }
    delete [] employees;
    employees = temp;
    this->capacity *= 2;
}

SoftwareCompany::EmployeeList::EmployeeList()
{
    this->size = 0;
    this->capacity = 3;
    employees = new Employee*[capacity];
}

bool SoftwareCompany::EmployeeList::insertEmployee(Employee* newEmployee)
{
    if(size == capacity)
    {
        return false;
    }
    employees[size++] = newEmployee;
    return true;
}

void SoftwareCompany::EmployeeList::map(void(*op)(Employee*))
{
    for(int i = 0; i < size; i++)
        op(employees[i]);
}

void SoftwareCompany::EmployeeList::filter(bool(*pred)(Employee*))
{
    for(int i = 0; i < size; i++)
    {
        if(pred(employees[i]))
        {
            delete employees[i];
            employees[i] = NULL;
        }
        int write = 0;
        for(int read = 0; read < size; read++)
        {
            if(employees[read])
            {
                employees[write++] = employees[read];
            }
        }
        size = write;
    }
}

double SoftwareCompany::EmployeeList::accumulate(double(*op)(Employee* e), double(*comp)(double,double),double nullVal)
{
    double result;
    for(int i = 0; i < size; i++)
    {
        result = comp(result, op(employees[i]));
                //plus(result, getSalary());
    }
    return result;
}

SoftwareCompany::EmployeeList::~EmployeeList()
{
    for(int i = 0; i < size; i++)
    {
        delete employees[i];
    }
    delete [] employees;
}

void SoftwareCompany::newEmployee()
{
    char type;
    cout << "Type employer (d/m):";
    cin >> type;
    Employee* newEmployee = createEmployee(type);
    if(newEmployee)
    {
        cout << (list.insertEmployee(newEmployee) ? "Employer is added." : "Failed operation.");
        cout << endl;
    }
}

void SoftwareCompany::removeRecentlyEmployed()
{
    list.filter(filterLessThan3Months);
}

void SoftwareCompany::increaseSalaries()
{
    list.map(increseSalary);
}

void SoftwareCompany::printAll()
{
    list.map(printEmployee);
}

double SoftwareCompany::sumSalaries()
{
    return list.accumulate(getSalary, pluss, 0);
}

void SoftwareCompany::readCommonData(Employee *e)
{
    char name[500];
    cout << "Name: ";
    cin >> name;
    e->setName(name);

    int period;
    cout << "Period: ";
    cin >> period;
    e->setPeriod(period);

    double salary;
    cout << "Salary: ";
    cin >> salary;
    e->setSalary(salary);
}

Developer* SoftwareCompany::createDeveloper()
{
    Developer *developer = new Developer("", 0, 0, false, false);
    int knows;
    readCommonData(developer);
    bool knowsCpp, knowsCs;
    cout << "Knows Cpp (1/0)?: ";
    cin >> knows;
    knowsCpp = knows == 1;
    developer->setKnowsCpp(knowsCpp);
    cout << "Knows C# (1/0)?: ";
    cin >> knows;
    knowsCs = knows == 1;
    developer->setKnowsCs(knowsCs);
    return developer;
}

Manager* SoftwareCompany::createManager()
{
    Manager *manager = new Manager("", 0, 0, 0);
    readCommonData(manager);
    int inChargeOf;
    cout << "How many people he is in charge of?:";
    cin >> inChargeOf;
    manager->setInChargeOf(inChargeOf);
    return manager;
}

Employee* SoftwareCompany::createEmployee(char type)
{
    switch(type)
    {
    case 'd': return createDeveloper();
    case 'm': return createManager();
    }
    return NULL;
}

double getSalary(Employee* emp)
{
    return emp->getSalary();
}

double pluss(double a, double b)
{
    return a + b;
}

bool filterLessThan3Months(Employee* emp)
{
    return emp->getPeriod() >= 3;
}

void printEmployee(Employee* emp)
{
    emp->print();
}

void increseSalary(Employee* emp)
{
    Developer* dev = dynamic_cast<Developer*>(emp);
    if (dev != nullptr && dev->getKnowsCpp())
    {
        emp->setSalary(emp->getSalary() + 100);
    }

    Manager* mng = dynamic_cast<Manager*>(emp);
    if (mng != nullptr)
    {
        emp->setSalary(emp->getSalary() + 500);
    }
}
