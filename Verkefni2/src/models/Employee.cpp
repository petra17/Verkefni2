#include "Employee.h"

Employee::Employee()
{
    this->name = "";
    this->SSN = "";
    this->month_salary = 0;
    this->month = 0;
    this->year = 0;
}

Employee::Employee(string name, string SSN, int month_salary, int month, int year) {
    this->name = name;
    this->SSN = SSN;
    this->month_salary = month_salary;
    this->month = month;
    this->year = year;
}

void Employee::write(ofstream& fout) const {

    int strLen = name.length() + 1;
    fout.write((char*)(&strLen), sizeof(int));
    fout.write(name.c_str(), strLen);

    int strLen1 = SSN.length() + 1;
    fout.write((char*)(&strLen1), sizeof(int));
    fout.write(SSN.c_str(), strLen1);

    fout.write((char*)(&month_salary), sizeof(int));
    fout.write((char*)(&month), sizeof(int));
    fout.write((char*)(&year), sizeof(int));
}

void Employee::read(ifstream& fin) {

    int strLen = name.length();
    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    name = str;

    int strLen1 = SSN.length();
    fin.read((char*)(&strLen1), sizeof(int));
    char *str1 = new char[strLen1];
    fin.read(str1, strLen1);
    SSN = str1;

    fin.read((char*)(&month_salary), sizeof(int));
    fin.read((char*)(&month), sizeof(int));
    fin.read((char*)(&year), sizeof(int));

    delete[] str;
    delete[] str1;
}

ostream &operator << (ostream &out, Employee &employee) {
    out << "Name: " << employee.name << " ";
    out << "SSN: " << employee.SSN << " ";
    out << "Month's Salary: " << employee.month_salary << " ";
    out << "Month: " << employee.month << " ";
    out << "Year: " << employee.year << endl;

    return out;
}

bool operator == (const Employee &left_emp, const Employee &right_emp) {
        if (left_emp.SSN == right_emp.SSN) {
            if (left_emp.month == right_emp.month) {
                if (left_emp.year == right_emp.year) {
                    return true;
                }
            }
        }
    return false;
}

string Employee::getName() {
    return this->name;
}
string Employee::getSSN() {
    return this->SSN;
}
int Employee::getMonthSalary() {
    return this->month_salary;
}
int Employee::getMonth() {
    return this->month;
}
int Employee::getYear() {
    return this->year;
}



