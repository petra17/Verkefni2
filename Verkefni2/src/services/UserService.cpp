#include "UserService.h"

UserService::UserService() {
    //ctor
}

void UserService::fixName(string& name) {

    for(unsigned int i = 0; i < name.length(); i++){
        if(name[i] != ' ' && isupper(name[i])){
            tolower(name[i]);
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
    intSalary = convertToInt(salary);
    if(intSalary < 150000 || intSalary > 1500000){
        throw InvalidSalaryException();
    }
    return intSalary;
}
int UserService::convertToInt(string integer){
    return atoi(integer.c_str());
}
int UserService::isValidMonth(string month) {
    int intMonth = 0;
    for(unsigned int i = 0; i < month.length(); i++){
        if(isalpha(month[i])){
            throw InvalidMonthException();
        }
    }
    intMonth = convertToInt(month);
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
    intYear = convertToInt(year);
    if(intYear > 2017){
        throw InvalidYearException();
    }
    return intYear;
}
