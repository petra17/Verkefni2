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
    string name;
    string SSN;
    int month_salary;
    int month;
    int year;

    cout << "----Add Salary----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "SSN/kennitala: ";
    cin >> ws;
    getline(cin, SSN);
    cout << "Month's Salary: ";
    cin >> month_salary;
    cout << "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;

    Employee employee(name, SSN, month_salary, month, year);
    cout << employee << endl;

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
