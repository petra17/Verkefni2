#ifndef USERSERVICE_H
#define USERSERVICE_H
#include "invalidSNNExeption.h"
#include "InvalidNameException.h"
#include "InvalidSalaryException.h"
#include "InvalidMonthException.h"
#include <iostream>
#include <string>

using namespace std;

class UserService
{
    public:
        UserService();
        void fixName(string& name);
        bool isValidName(string name);
        void fixSNN(string& kennitala);
        bool isValidSNN(string kennitala);
        bool isValidSalary(int salary);
        bool isValidMonth(int month) ;
    protected:

    private:
};

#endif // USERSERVICE_H
