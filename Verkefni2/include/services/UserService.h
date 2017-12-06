#ifndef USERSERVICE_H
#define USERSERVICE_H
#include "UserRep.h"
#include "invalidSNNExeption.h"
#include "InvalidNameException.h"
#include "InvalidSalaryException.h"
#include "InvalidMonthException.h"
#include "InvalidYearException.h"
#include "SalaryListChangedException.h"
#include "SSNNotInListExeption.h"
#include "YearNotInListExeption.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class UserService
{
    public:
        UserService();
        void fixName(string& name);
        bool isValidName(string name);
        void fixSNN(string& kennitala);
        bool isValidSNN(string kennitala);
        int isValidSalary(string salary);
        int convertToInt(string integer);
        int isValidMonth(string month) ;
        int isValidYear(string year);

        bool addSalary(const Employee &employee);
        bool checkYear(int year);
        bool checkSSN(string SSN);
        vector<Employee> printSalaryList();
        vector<Employee> getSSNRecords(string SSN);
        Employee getHighestEmployee(int year);

    private:
        UserRep userRep;
};

#endif // USERSERVICE_H
