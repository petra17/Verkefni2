#ifndef USERSERVICE_H
#define USERSERVICE_H
#include "invalidSNNExeption.h"
#include "InvalidNameException.h"
#include "InvalidSalaryException.h"
#include "InvalidMonthException.h"
#include "InvalidYearException.h"
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
    protected:

    private:
};

#endif // USERSERVICE_H
