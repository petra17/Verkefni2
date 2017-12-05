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
        void printRecordYear();
        void printHighest();
};

#endif // USERUI_H
