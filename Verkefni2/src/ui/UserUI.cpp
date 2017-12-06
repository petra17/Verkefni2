#include "UserUI.h"
#include "Employee.h"

UserUI::UserUI()
{
    //ctor
}

void UserUI::startUI() {
    char answer = '0';
    while (answer != '5') {
        cout << "Welcome user" << endl;
        cout << "Choose an option" << endl;
        cout << "----------------" << endl;
        cout << "1: Add salary record" << endl;
        cout << "2: Print out records for given SSN" << endl;
        cout << "3: Print out records for given SSN and year" << endl;
        cout << "4: Print out employee with highest salary of given year" << endl;
        cout << "5: Quit" << endl;

        cin >> answer;
        switch(answer) {
            case '1': addSalary();
            break;
            case '2': printRecordSSN();
            break;
            case '3': printRecordYear();
            break;
            case '4': printHighest();
            break;
            default: cout << "Option invalid" << endl;
        }
    }
}

void UserUI::addSalary() {
    bool allowed = false;
    string name;
    string SSN;
    string monthSalary1;
    string month1;
    string year1;
    int monthSalary;
    int month;
    int year;

    cout << "----Add Salary----" << endl;
    while(!allowed){
        cout << "Name: ";
        cin >> ws;
        getline(cin, name);
        userServ.fixName(name);
        try{
            allowed = userServ.isValidName(name);
        }
        catch(InvalidNameException){
            cout << "Invalid name kopboii" << endl;
        }
    }
    allowed = false;
    while(!allowed){
        cout << "SSN/kennitala: ";
        cin >> ws;
        getline(cin, SSN);
        userServ.fixSNN(SSN);
        try{
            allowed = userServ.isValidSNN(SSN);
        }
        catch(invalidSNNExeption){
            cout << "Invalid SNN kopboii" << endl;
        }
    }
    allowed = false;
    while(!allowed){
        cout << "Month's Salary: ";
        cin >> monthSalary1;
        try{
            monthSalary = userServ.isValidSalary(monthSalary1);
            allowed = true;
        }
        catch(InvalidSalaryException){
            cout << "Invalid salary kopboii" << endl;
        }
    }
    allowed = false;
    while(!allowed){
        cout << "Month: ";
        cin >> month1;
        try{
            month = userServ.isValidMonth(month1);
            allowed = true;
        }
        catch(InvalidMonthException){
            cout << "Invalid month kopboii" << endl;
        }

    }

    allowed = false;
    while(!allowed){
        cout << "Year: ";
        cin >> year1;
        try{
            year = userServ.isValidYear(year1);
            allowed = true;
        }
        catch(InvalidYearException){
            cout << "Invalid Year kopboii" << endl;
        }

    }
    //Employee employee(name, SSN, monthSalary1, month, year);
    //cout << employee << endl;


}

void UserUI::printRecordSSN() {
    cout << "Print records given SSN" << endl;
}

void UserUI::printRecordYear() {
    cout << "Print records given SSN and year" << endl;
}

void UserUI::printHighest() {
    cout << "Highest Salary" << endl;
}
