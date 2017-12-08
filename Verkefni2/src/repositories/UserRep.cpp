#include "UserRep.h"

UserRep::UserRep()
{
    //ctor
}

vector<Employee> UserRep::getSalaryList() {
    vector <Employee> salaryList;
    ifstream fin;
    fin.open("SalaryList_Binary.dat", ios::binary);
    if(fin.is_open()) {
        Employee employee;
        while(!fin.eof()){
            employee.read(fin);
            if(!fin.eof()){
                salaryList.push_back(employee);
            }
        }
        fin.close();
    }
    return salaryList;
}

void UserRep::addSalary(const Employee &employee) {
    ofstream fout;
    fout.open("SalaryList_Binary.dat", ios::binary|ios::app);
    if(fout.is_open()) {
        employee.write(fout);
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}

void UserRep::changeSalaryList(vector<Employee> &salaryList) {

    ofstream fout;
    fout.open("SalaryList_Binary.dat", ios::binary);
    if(fout.is_open()) {
        for (unsigned int i = 0; i < salaryList.size(); i++) {
            salaryList[i].write(fout);
        }
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}
