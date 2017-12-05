#include "Employee.h"

Employee::Employee()
{
    //ctor
}

Employee::Employee(string name, string SSN, double month_salary, int month, int year) {
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

    fout.write((char*)(&month_salary), sizeof(double));
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
    fin.read(str, strLen1);
    SSN = str1;

    fin.read((char*)(&month_salary), sizeof(double));
    fin.read((char*)(&month), sizeof(int));
    fin.read((char*)(&year), sizeof(int));

    delete[] str;
    delete[] str1;
}

ostream &operator << (ostream &out, Employee &employee) {
    out << "Name: " << employee.name << endl;
    out << "SSN: " << employee.SSN << endl;
    out << "Month's Salary: " << employee.month_salary << endl;
    out << "Month: " << employee.month << endl;
    out << "Year: " << employee.year << endl;

    return out;
}


