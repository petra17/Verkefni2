#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Employee
{
    private:
        string name;
        string SSN;
        string month_salary;
        int month;
        int year;

    public:
        Employee();
        Employee(string name, string SSN, string month_salary, int month, int year);
        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend ostream &operator << (ostream &out, Employee &employee);


};

#endif // EMPLOYEE_H
