#include "EmployeeRecord.h"
#include <iostream>
#include <string.h>

EmployeeRecord::EmployeeRecord() {
    m_iEmployeeID = 0;
	m_sFirstName = new char[32];
	m_sLastName = new char[32];
    strcpy(m_sFirstName, "");
    strcpy(m_sLastName, "");
    m_iDeptID = 0;
    m_dSalary = 0.0;
}
EmployeeRecord::EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal) {
    m_iEmployeeID = ID;
	m_sFirstName = new char[32];
	m_sLastName = new char[32];
    strcpy(m_sFirstName, fName);
    strcpy(m_sLastName, lName);
    m_iDeptID = dept;
    m_dSalary = sal;
}
EmployeeRecord::~EmployeeRecord() {
	delete [] m_sFirstName;
	delete [] m_sLastName;
}
int EmployeeRecord::getID() {
    return m_iEmployeeID;
}
void EmployeeRecord::setID(int ID) {
    m_iEmployeeID = ID;
    return;
}
void EmployeeRecord::getName(char *fName, char *lName) {
	strcpy(fName, m_sFirstName);
	strcpy(lName, m_sLastName);
    return;
}
void EmployeeRecord::setName(char *fName, char *lName) {
	strcpy(m_sFirstName, fName);
    strcpy(m_sLastName, lName);
    return;
}
void EmployeeRecord::getDept(int& d) {
	d = m_iDeptID;
    return;
}
void EmployeeRecord::setDept(int d) {
	m_iDeptID = d;
    return;
}
void EmployeeRecord::getSalary(double *sal) {
	*sal = m_dSalary;
    return;
}
void EmployeeRecord::setSalary(double sal) {
	m_dSalary = sal;
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
