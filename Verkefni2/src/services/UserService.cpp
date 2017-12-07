#include "UserService.h"

UserService::UserService() {
    //ctor
}

void UserService::fixName(string& name) {

    for(unsigned int i = 0; i < name.length(); i++){
        if(name[i] != ' ' && isupper(name[i])){
            name[i] = tolower(name[i]);
        }
    }
}

bool UserService::isValidName(string name) {

    for(unsigned int i = 0; i < name.length(); i++){
        if(isdigit(name[i])){
             throw InvalidNameException();
        }
    }
    return true;
}

void UserService::fixSNN(string& kennitala) {

    for(unsigned int i = 0; i < kennitala.length(); i++){
        if(kennitala[i] == ' ' || kennitala[i] == '-'){
            kennitala.erase(i,1);
        }
    }
}

bool UserService::isValidSNN(string kennitala) {

    for(unsigned int i = 0; i < kennitala.length(); i++){
        if(!isdigit(kennitala[i]) || kennitala.length() != 10){
             throw invalidSNNExeption();
        }
    }
    return true;
}

int UserService::isValidSalary(string salary) {
    int intSalary = 0;
    for(unsigned int i = 0; i < salary.length(); i++){
        if(isalpha(salary[i])){
            throw InvalidSalaryException();
        }
    }
    intSalary = atoi(salary.c_str());

    if(intSalary < 100000 || intSalary > 2000000){
        throw InvalidSalaryException();
    }
    return intSalary;
}

int UserService::isValidMonth(string month) {
    int intMonth = 0;
    for(unsigned int i = 0; i < month.length(); i++){
        if(isalpha(month[i])){
            throw InvalidMonthException();
        }
    }
    intMonth = atoi(month.c_str());
    if(intMonth < 1 || intMonth > 12){
        throw InvalidMonthException();
    }
    return intMonth;
}

int UserService::isValidYear(string year) {
    int intYear = 0;
    for(unsigned int i = 0; i < year.length(); i++){
        if(isalpha(year[i])){
            throw InvalidYearException();
        }
    }
    intYear = atoi(year.c_str());

    if(intYear < 1900 || intYear > 2017){
        throw InvalidYearException();
    }
    return intYear;
}

bool UserService::addSalary(const Employee &employee) {
    vector<Employee> salaryList = userRep.getSalaryList();

    for (int i = 0; i < salaryList.size(); i++){
        if (salaryList[i] == employee) {
            salaryList[i] = employee;
            userRep.changeSalaryList(salaryList);
            throw SalaryListChangedException();
        }
    }
    userRep.addSalary(employee);
    return true;
}

vector<Employee> UserService::printSalaryList() {
    vector<Employee> salaryList = userRep.getSalaryList();
    return salaryList;
}

vector<Employee> UserService::getSSNRecords(string SSN) {
    vector<Employee> salaryList = userRep.getSalaryList();
    vector<Employee> SSNRecordList;
    for (int i = 0; i < salaryList.size(); i++) {
        if (salaryList[i].getSSN() == SSN) {
            SSNRecordList.push_back(salaryList[i]);
        }
    }
    return SSNRecordList;
}

Employee UserService::getHighestEmployee(int year) {

     vector<Employee> salaryList = userRep.getSalaryList();
     Employee highestEmployee;

     for (int i = 0; i < salaryList.size(); i++) {
        if (salaryList[i].getYear() == year) {
            if (salaryList[i].getMonthSalary() > highestEmployee.getMonthSalary()) {
                highestEmployee = salaryList[i];
            }
        }
     }
     return highestEmployee;
}

bool UserService::checkSSN(string SSN) {
    vector<Employee> salaryList = userRep.getSalaryList();

    for (int i = 0; i < salaryList.size(); i++) {
        if (salaryList[i].getSSN() == SSN) {
            return true;
        }
     }
     throw SSNNotInListExeption();
}

bool UserService::checkYear(int year) {
    vector<Employee> salaryList = userRep.getSalaryList();

    for (int i = 0; i < salaryList.size(); i++) {
        if (salaryList[i].getYear() == year) {
            return true;
        }
     }
    throw YearNotInListExeption();
}
