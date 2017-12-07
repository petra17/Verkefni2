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
        int month_salary;
        int month;
        int year;

    public:
        Employee();
        Employee(string name, string SSN, int month_salary, int month, int year);
        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend ostream &operator << (ostream &out, Employee &employee);
        friend bool operator == (const Employee &left_emp, const Employee &right_emp);

        string getName();
        string getSSN();
        int getMonthSalary();
        int getMonth();
        int getYear();
};

#endif // EMPLOYEE_H
