#ifndef USERUI_H
#define USERUI_H
#include "UserService.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class UserUI
{
    private:
        UserService userServ;
    public:
        UserUI();
        void startUI();

        void addSalary();

        string validName();
        string validSSN();
        int validMonthSalary();
        int validMonth();
        int validYear();

        void printRecordSSN();
        void printRecordSSNYear();
        void printHighest();
        void printAllRecords();
};

#endif // USERUI_H
