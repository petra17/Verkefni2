#ifndef USERUI_H
#define USERUI_H
#include "UserService.h"
#include <iostream>
using namespace std;

class UserUI
{
    private:
        UserService userServ;
    public:
        UserUI();
        void startUI();

        void addSalary();
        void printRecordSSN();
        void printRecordSSNYear();
        void printHighest();
        void printAllRecords();
};

#endif // USERUI_H
