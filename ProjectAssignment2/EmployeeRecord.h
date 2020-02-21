/***********************************************
 * File: EmployeeRecord.h
 * Author: Paul Abers
 * Assignment 2: Employee Record Class
 *
 * This program is entirely my own work.
 **********************************************/


#ifndef EMPLOYEERECORD_H
#define EMPLOYEERECORD_H

#include "CustomerList.h"

class EmployeeRecord {
    private: // Declare private class variables
        int m_iEmployeeID;
        char *m_sLastName;
        char *m_sFirstName;
        int m_iDeptID;
        double m_dSalary;
	    CustomerList *m_pCustomerList;

     public: // Declare public class methods
        EmployeeRecord();
	    EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal, CustomerList *cl);
        ~EmployeeRecord();
        int getID();
        void setID(int ID);
        void getName(char *fName, char *lName);
        void setName(char *fName, char *lName);
        int getDept();
        void setDept(int d);
        double getSalary();
        void setSalary(double sal);
        void printRecord();
    	CustomerList *getCustomerList();
};

#endif
