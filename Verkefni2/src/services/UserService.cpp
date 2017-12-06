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

bool UserService::isValidSalary(string salary) {
    for(unsigned int i = 0; i < salary.length(); i++){
        if(!isdigit(salary[i])){
             throw InvalidSalaryException();
        }
    }
    return true;
}
bool UserService::isValidMonth(int month) {
    if(month < 1 || month > 12){
        throw InvalidMonthException();
    }
    return true;
}
