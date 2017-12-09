#include "UserService.h"

UserService::UserService() {
    //ctor
}

bool UserService::addSalary(const Employee &employee) {
    vector<Employee> salaryList = userRep.getSalaryList();

    for (unsigned int i = 0; i < salaryList.size(); i++){
        if (salaryList[i] == employee) {
            salaryList[i] = employee;
            userRep.changeSalaryList(salaryList);
            throw SalaryListChangedException();
        }
    }
    userRep.addSalary(employee);
    return true;
}

vector<Employee> UserService::getSSNRecords(string SSN) {
    vector<Employee> salaryList = userRep.getSalaryList();
    vector<Employee> SSNRecordList;
    for (unsigned int i = 0; i < salaryList.size(); i++) {
        if (salaryList[i].getSSN() == SSN) {
            SSNRecordList.push_back(salaryList[i]);
        }
    }
    return SSNRecordList;
}

vector<Employee> UserService::getSSNYearRecords(string SSN, int year) {
    vector<Employee> salaryList = userRep.getSalaryList();
    vector<Employee> SSNYearRecordList;
    for (unsigned int i = 0; i < salaryList.size(); i++) {
        if (salaryList[i].getSSN() == SSN && salaryList[i].getYear() == year) {
            SSNYearRecordList.push_back(salaryList[i]);
        }
    }
    return SSNYearRecordList;
}

Employee UserService::getHighestEmployee(int year) {

    vector<Employee> employeeList;
    vector<Employee> salaryList = userRep.getSalaryList();

    for (unsigned int i = 0; i < salaryList.size(); i++) {
        if (salaryList[i].getYear() == year) {
            if(notFound(salaryList[i].getName(),employeeList)){
                employeeList.push_back(salaryList[i]);

            }
        }
    }
    for (unsigned int i = 0; i < employeeList.size(); i++) {
        for (unsigned int j = 0; j < salaryList.size(); j++) {
            if(salaryList[j].getName() == employeeList[i].getName()){
                if(salaryList[j].getYear() == year){
                    employeeList[i].setYearSalary(salaryList[j].getMonthSalary());
                }
            }
        }
    }
    Employee highestEmployee = employeeList[0];
    for (unsigned int i = 1; i < employeeList.size(); i++) {
        if(employeeList[i].getYearSalary() > highestEmployee.getYearSalary()){
            highestEmployee = employeeList[i];
        }
    }
    return highestEmployee;
}

vector<Employee> UserService::printSalaryList() {
    vector<Employee> salaryList = userRep.getSalaryList();
    return salaryList;
}

bool UserService::notFound(string name, vector<Employee> set){
    for(unsigned int i = 0; i < set.size(); i++){
		if(set[i].getName() == name){
			return false;
		}
	}
	return true;
}

void UserService::fixName(string& name) {

    for(unsigned int i = 0; i < name.length(); i++){
        if(name[i] != ' ' && isupper(name[i])){
            name[i] = tolower(name[i]);
        }
    }
}

void UserService::fixSNN(string& kennitala) {

    for(unsigned int i = 0; i < kennitala.length(); i++){
        if(kennitala[i] == ' ' || kennitala[i] == '-'){
            kennitala.erase(i,1);
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

bool UserService::isValidSNN(string kennitala) {
    for(unsigned int i = 0; i < kennitala.length(); i++){
        if(!isdigit(kennitala[i]) || kennitala.length() != 10){
            throw InvalidSSNExeption();
        }
    }
    return true;
}

bool UserService::compairSNNandName(string kennitala,string name) {
    vector<Employee> salaryList = userRep.getSalaryList();
    if(salaryList.size() != 0){
        for(unsigned int i = 0; i < kennitala.length(); i++){
            if(salaryList[i].getSSN() == kennitala && salaryList[i].getName() != name){
                throw AnotherEmployeesSSNException();
            }
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

    if(intSalary < LOWESTSALARY || intSalary > HIGHESTSALARY){
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

    if(intYear < YEARFOUNDED || intYear > YEARNOW){
        throw InvalidYearException();
    }
    return intYear;
}

bool UserService::checkSSN(string SSN) {
    vector<Employee> salaryList = userRep.getSalaryList();

    for (unsigned int i = 0; i < salaryList.size(); i++) {
        if (salaryList[i].getSSN() == SSN) {
            return true;
        }
     }
     throw SSNNotInListExeption();
}

bool UserService::checkSSNYear(string SSN, int year) {
    vector<Employee> salaryList = userRep.getSalaryList();

    for (unsigned int i = 0; i < salaryList.size(); i++) {
        if (salaryList[i].getSSN() == SSN && salaryList[i].getYear() == year) {
            return true;
        }
     }
    throw SSNYearNotInListExeption();

}

void UserService::checkYear(int year) {
    bool valid = false;
    vector<Employee> salaryList = userRep.getSalaryList();

    for (unsigned int i = 0; i < salaryList.size(); i++) {
        if (salaryList[i].getYear() == year) {
            valid = true;
        }
    }
    if(!valid){
        throw YearNotInListExeption();
    }
}
