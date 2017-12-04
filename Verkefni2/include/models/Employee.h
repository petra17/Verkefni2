#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

class Employee
{
    private:
        string name;
        char SSN[11];
        int month_salary;
        int month;
        int year;

    public:
        Employee();

};

#endif // EMPLOYEE_H
