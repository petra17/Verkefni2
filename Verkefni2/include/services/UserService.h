#ifndef USERSERVICE_H
#define USERSERVICE_H
#include "UserRep.h"

#include "InvalidNameException.h"
#include "InvalidSSNExeption.h"
#include "InvalidSalaryException.h"
#include "InvalidMonthException.h"
#include "InvalidYearException.h"
#include "AnotherEmployeesSSNException.h"


#include "SalaryListChangedException.h"

#include "SSNNotInListExeption.h"
#include "YearNotInListExeption.h"
#include "SSNYearNotInListExeption.h"
#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

const int LOWESTSALARY = 0;
const int HIGHESTSALARY = 1500000;

class UserService
{
    private:
        UserRep userRep;

    public:
        UserService();

        bool addSalary(const Employee &employee);
        vector<Employee> getSSNRecords(string SSN);
        vector<Employee> getSSNYearRecords(string SSN, int year);
        Employee getHighestEmployee(int year);
        vector<Employee> printSalaryList();

        bool notFound(string name, vector<Employee> set1);

        void fixName(string& name);
        void fixSNN(string& kennitala);

        bool isValidName(string name);
        bool isValidSNN(string kennitala);
        bool compairSNNandName(string kennitala, string name);
        int isValidSalary(string salary);
        int isValidMonth(string month) ;
        int isValidYear(string year);

        bool checkSSN(string SSN);
        bool checkSSNYear(string SSN, int year);
        void checkYear(int year);
};

#endif // USERSERVICE_H
