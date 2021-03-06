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
        cout << "--------------------------------------------------------" << endl;
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
            case '6':
            break;
            default: cout << "Option invalid" << endl;
        }
    }
}

void UserUI::addSalary() {

    cout << "-----------------------Add Salary-----------------------" << endl;
    string name = validName();
    string SSN = validateSSNAndName(name);
    int monthSalary = validMonthSalary();
    int month = validMonth();
    int year = validYear();

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

    cout << "----------------Print records given SSN-----------------" << endl;

    string SSN = validSSN();
    bool valid = false;
    while(!valid){
        try {
            valid = userServ.checkSSN(SSN);
            vector<Employee> SSNSalaryList = userServ.getSSNRecords(SSN);
            for (unsigned int i = 0; i < SSNSalaryList.size(); i++) {
                cout << SSNSalaryList[i];
            }
        }
        catch(SSNNotInListExeption) {
            cout << "No salary from this SSN" << endl;
        }
    }
    cout << "--------------------------------------------------------" << endl;
}

void UserUI::printRecordSSNYear() {

    cout << "--Print records for given SSN and year--" << endl;
    bool valid = false;
    while(!valid){
        string SSN = validSSN();
        int year = validYear();
        try {
            valid = userServ.checkSSNYear(SSN, year);
            vector<Employee> SSNYearSalaryList = userServ.getSSNYearRecords(SSN, year);
             for (unsigned int i = 0; i < SSNYearSalaryList.size(); i++) {
                cout << SSNYearSalaryList[i];
            }
        }
        catch(SSNYearNotInListExeption) {
            cout << "No salary from this SSN and year" << endl;
        }
    }
    cout << "--------------------------------------------------------" << endl;
}

void UserUI::printHighest() {

    cout << "---------------------Highest Salary---------------------" << endl;
    int year = validYear();

    try {
        userServ.checkYear(year);
        Employee highestEmp = userServ.getHighestEmployee(year);
        cout << highestEmp.getName() << " with year salary of " << highestEmp.getYearSalary() << " kr!"<< endl;;
    }
    catch(YearNotInListExeption) {
        cout << "No salary from this year" << endl;
    }
    cout << "--------------------------------------------------------" << endl;
}


void UserUI::printAllRecords() {
    cout << "----------------------Salary List-----------------------" << endl;
    vector<Employee> salaryList = userServ.printSalaryList();

    for (unsigned int i = 0; i < salaryList.size(); i++) {
        cout << salaryList[i];
    }
    cout << "--------------------------------------------------------" << endl;
}

string UserUI::validName() {
    string name = "";
    bool allowed = false;
    while(!allowed){
        cout << "Name: ";
        cin >> ws;
        getline(cin, name);
        userServ.fixName(name);
        try{
            allowed = userServ.isValidName(name);
        }
        catch(InvalidNameException){
            cout << "Invalid name" << endl;
        }
    }
    return name;
}

string UserUI::validSSN() {

    string SSN = "";
    bool allowed = false;
    while(!allowed){
        cout << "SSN/kennitala: ";
        cin >> ws;
        getline(cin, SSN);
        userServ.fixSNN(SSN);
        try{
            allowed = userServ.isValidSNN(SSN);
        }
        catch(InvalidSSNExeption){
            cout << "Invalid SNN" << endl;
        }
    }
    return SSN;
}

string UserUI::validateSSNAndName(string name) {

    string SSN = "";
    bool allowed = false;
    while(!allowed){
        cout << "SSN/kennitala: ";
        cin >> ws;
        getline(cin, SSN);
        userServ.fixSNN(SSN);
        try{
            allowed = userServ.isValidSNN(SSN);
            if(allowed){
                allowed = userServ.compairSNNandName(SSN,name);
            }
        }
        catch(InvalidSSNExeption){
            cout << "Invalid SNN" << endl;
            allowed = false;
        }
        catch(AnotherEmployeesSSNException){
            cout << "SSN belongs to another person!" << endl;
            allowed = false;
        }
    }

    return SSN;
}
int UserUI::validMonthSalary() {
    string monthSalary1 = "";
    int monthSalary = 0;
    bool allowed = false;

    while(!allowed){
        cout << "Month's Salary: ";
        cin >> monthSalary1;
        try{
            monthSalary = userServ.isValidSalary(monthSalary1);
            allowed = true;
        }
        catch(InvalidSalaryException){
            cout << "Invalid salary" << endl;
        }
    }
    return monthSalary;
}

int UserUI::validMonth() {
    string month1 = "";
    int month = 0;
    bool allowed = false;

    while(!allowed){
        cout << "Month: ";
        cin >> month1;
        try{
            month = userServ.isValidMonth(month1);
            allowed = true;
        }
        catch(InvalidMonthException){
            cout << "Invalid month" << endl;
        }
    }
    return month;
}

int UserUI::validYear() {
    string year1 = "";
    int year = 0;
    bool allowed = false;

    while(!allowed){
        cout << "Year: ";
        cin >> year1;
        try{
            year = userServ.isValidYear(year1);
            allowed = true;
        }
        catch(InvalidYearException){
            cout << "Invalid Year" << endl;
        }
    }
    return year;
}
