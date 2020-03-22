/***********************************************
 * File: EmployeeDatabase.h
 * Author: Paul Abers
 * Assignment 3: Employee Database Class
 *
 * This program is entirely my own work.
 **********************************************/

#pragma once

#include <fstream>
#include <iostream>
#include "EmployeeRecord.h"

class EmployeeDatabase {
private:
    EmployeeRecord *m_pRoot;
    ifstream inFile;
    void printEmployeeRecords(EmployeeRecord *rt);
    void destroyTree(EmployeeRecord *rt);
    bool getNextLine(char *line, int lineLen);
    bool addEmployee(EmployeeRecord *node, EmployeeRecord *e);
    EmployeeRecord *getEmployee(int ID, EmployeeRecord *node);
    EmployeeRecord *removeEmployee(int ID, EmployeeRecord *node);
    EmployeeRecord *removeHelp(int ID, EmployeeRecord *node);
    EmployeeRecord *getSuccessor(EmployeeRecord *node);

public:
    EmployeeDatabase();
    ~EmployeeDatabase();
    bool addEmployee(EmployeeRecord *e);
    EmployeeRecord *getEmployee(int ID);
    EmployeeRecord *removeEmployee(int ID);
    void printEmployeeRecords();
    bool buildDatabase(char *dataFile);
};
