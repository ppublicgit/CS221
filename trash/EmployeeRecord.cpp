#include "EmployeeRecord.h"
#include <iostream>

EmployeeRecord::EmployeeRecord() {
    m_iEmployeeID = 0;
    m_sLastName = "";
    m_sFirstName = "";
    m_iDeptID = 0;
    m_dSalary = 0.0;
}
EmployeeRecord::EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal) {
    m_iEmployeeID = ID;
    m_sLastName = "";
    m_sFirstName = "";
    m_iDeptID = dept;
    m_dSalary = sal;
}
EmployeeRecord::~EmployeeRecord() {
    delete[] m_sLastName;
    delete[] m_sFirstName;
}
int EmployeeRecord::getID() {
    return m_iEmployeeID;
}
void EmployeeRecord::setID(int ID) {
    m_iEmployeeID = ID;
    return;
}
void EmployeeRecord::getName(char *fName, char *lName) {
    return;
}
void EmployeeRecord::setName(char *fName, char *lName) {
    return;
}
void EmployeeRecord::getDept(int& d) {
    return;
}
void EmployeeRecord::setDept(int d) {
    return;
}
void EmployeeRecord::getSalary(double *sal) {
    return;
}
void EmployeeRecord::setSalary(double sal) {
    return;
}
void EmployeeRecord::printRecord() {
    std::cout << "------------- Employee Record Data -------------" << std::endl;
    std::cout << "Employee ID: " << m_iEmployeeID << std::endl;
    std::cout << "First Name: " << m_sFirstName << std::endl;
    std::cout << "Last Name: " << m_sLastName << std::endl;
    std::cout << "Department ID: " << m_iDeptID << std::endl;
    std::cout << "Salary: " << m_dSalary << std::endl;
    std::cout << std::endl;
    return;
}

//void EmployeeRecord::printRecordHelp(int length, char) {
//
//}