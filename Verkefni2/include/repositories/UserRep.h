#ifndef USERREP_H
#define USERREP_H
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Employee.h"
using namespace std;

class UserRep
{
    private:

    public:
        UserRep();
        vector<Employee> getSalaryList();
        void addSalary(const Employee &employee);
        void changeSalaryList(vector<Employee> &salaryList);
};

#endif // USERREP_H
