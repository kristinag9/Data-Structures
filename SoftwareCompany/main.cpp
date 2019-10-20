#include "SoftwareCompany.h"

int main()
{
    SoftwareCompany company;

    company.newEmployee();
    company.newEmployee();

    company.removeRecentlyEmployed();

    cout << "Salaries: " << company.sumSalaries() << endl;
    company.increaseSalaries();
    cout << "Salaries after the increment: " << company.sumSalaries() << endl;

    company.printAll();

    return 0;
}
