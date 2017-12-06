#include "UserUI.h"
#include "Employee.h"

UserUI::UserUI()
{
    //ctor
}

void UserUI::startUI() {
    char answer = '0';
    while (answer != '6') {
        cout << "Welcome user" << endl;
        cout << "Choose an option" << endl;
        cout << "----------------" << endl;
        cout << "1: Add salary record" << endl;
        cout << "2: Print out records for given SSN" << endl;
        cout << "3: Print out records for given SSN and year" << endl;
        cout << "4: Print out employee with highest salary for given year" << endl;
        cout << "5: Print all salary records" << endl;
        cout << "6: Quit" << endl;

        cin >> answer;
        switch(answer) {
            case '1': addSalary();
            break;
            case '2': printRecordSSN();
            break;
            case '3': printRecordSSNYear();
            break;
            case '4': printHighest();
            break;
            case '5': printAllRecords();
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
    Employee employee(name, SSN, monthSalary, month, year);

    try {
        userServ.addSalary(employee);
    }
    catch(SalaryListChangedException) {
        cout << endl;
        cout << "Salary for " << employee.getName() << " in month " << employee.getMonth();
        cout << ", year " << employee.getYear() << " has been changed" << endl;
        cout << endl;
    }
}

void UserUI::printRecordSSN() {
    string SSN;
    cout << "Print records given SSN" << endl;
    cout << "Enter SSN/kennitala: ";
    cin >> ws;
    getline(cin, SSN);

    try {
        bool valid = userServ.checkSSN(SSN);
        vector<Employee> SSNSalaryList = userServ.getSSNRecords(SSN);
        for (int i = 0; i < SSNSalaryList.size(); i++) {
        cout << SSNSalaryList[i];
        }
    }
    catch(SSNNotInListExeption) {
        cout << "This SSN is not in the list" << endl;
    }
}

void UserUI::printRecordSSNYear() {
    string SSN;
    int year;
    cout << "Print records for given SSN and year" << endl;
    cout << "Enter SSN/kennitala: ";
    cin >> ws;
    getline(cin, SSN);
    cout << "Enter year ";
    cin >> year;
}

void UserUI::printHighest() {
    int year;
    cout << "Highest Salary for given year" << endl;
    cout << "Choose a year: ";
    cin >> year;
    try {
        bool valid = userServ.checkYear(year);
        Employee highestEmployee = userServ.getHighestEmployee(year);
        cout << highestEmployee << endl;
    }
    catch(YearNotInListExeption) {
        cout << "This year is not on the list" << endl;
    }
}

void UserUI::printAllRecords() {
    vector<Employee> salaryList = userServ.printSalaryList();

    for (int i = 0; i < salaryList.size(); i++) {
        cout << salaryList[i] << endl;
    }
}
