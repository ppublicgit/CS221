/***********************************************
 * File: CustomerList.cpp
 * Author: Paul Abers
 * Assignment 3: Employee Database Class
 *
 * This program is entirely my own work.
 **********************************************/

#include "EmployeeDatabase.h"

EmployeeDatabase::EmployeeDatabase() {
    //std::cout << "constructed" << std::endl;
}

EmployeeDatabase::~EmployeeDatabase() {
    //std::cout << "destructed" << std::endl;
}

bool EmployeeDatabase::addEmployee(EmployeeRecord *e) {
    //std::cout << "added" << std::endl;
    bool ret;
    if (m_pRoot == NULL) {
        m_pRoot = e;
        ret = true;
    }
    else {
        if (e->getID() < m_pRoot->getID()) {
            if (m_pRoot->m_pLeft == NULL) {
                m_pRoot->m_pLeft = e;
                ret = true;
            }
            else {
                ret = addEmployee(m_pRoot->m_pLeft, e);
            }
        }
        else if (e->getID() > m_pRoot->getID()) {
            if (m_pRoot->m_pRight == NULL) {
                m_pRoot->m_pRight = e;
                ret = true;
            }
            else {
                ret = addEmployee(m_pRoot->m_pRight, e);
            }
        }
        else {
            ret = false;
        }
    }
    return ret;
}

bool EmployeeDatabase::addEmployee(EmployeeRecord *node, EmployeeRecord *e) {
    bool ret;
    if (e->getID() < node->getID()) {
        if (node->m_pLeft == NULL) {
            node->m_pLeft = e;
            ret = true;
        }
        else {
            ret = addEmployee(node->m_pLeft, e);
        }
    }
    else if (e->getID() > node->getID()) {
        if (node->m_pRight == NULL) {
            node->m_pRight = e;
            ret = true;
        }
        else {
            ret = addEmployee(node->m_pRight, e);
        }
    }
    else {
        ret = false;
    }
    return ret;
}

EmployeeRecord *EmployeeDatabase::getEmployee(int ID) {
    EmployeeRecord *ret;
    if (m_pRoot == NULL) {
        ret = NULL;
    }
    else {
        ret = getEmployee(ID, m_pRoot);
    }
    return ret;
}

EmployeeRecord *EmployeeDatabase::getEmployee(int ID, EmployeeRecord *node) {
    EmployeeRecord *ret;
    if (node == NULL) {
        ret = NULL;
    }
    else if (ID < node->getID()) {
        ret = getEmployee(ID, node->m_pLeft);
    }
    else if (ID > node->getID()) {
        ret = getEmployee(ID, node->m_pRight);
    }
    else {
        ret = node;
    }
    return ret;
}

EmployeeRecord *EmployeeDatabase::removeEmployee(int ID) {
    EmployeeRecord *ret;
    if (m_pRoot == NULL) {
        ret = NULL;
    }
    else {
        if (ID < m_pRoot->getID()) {
            if (m_pRoot->m_pLeft == NULL) {
                ret = NULL;
            }
            else if (ID == m_pRoot->m_pLeft->getID()) {
                ret = removeHelp(ID, m_pRoot);
            }
            else {
                ret = removeEmployee(ID, m_pRoot->m_pLeft);
            }
        }
        else if (ID > m_pRoot->getID()) {
            if (m_pRoot->m_pRight == NULL) {
                ret = NULL;
            }
            else if (ID == m_pRoot->m_pRight->getID()) {
                ret = removeHelp(ID, m_pRoot);
            }
            else {
                ret = removeEmployee(ID, m_pRoot->m_pRight);
            }
        }
        else {
            char *fname = new char[32];
            char *lname = new char[32];
            m_pRoot->getName(fname, lname);
            ret = new EmployeeRecord(m_pRoot->getID(), fname, lname, m_pRoot->getDept(), m_pRoot->getSalary(), m_pRoot->getCustomerList());
            m_pRoot->removeCustomerList();
            if (m_pRoot->m_pLeft == NULL && m_pRoot->m_pRight == NULL) {
                m_pRoot = NULL;
            }
            else if (m_pRoot->m_pRight == NULL) {
                m_pRoot = m_pRoot->m_pLeft;
            }
            else if (m_pRoot->m_pLeft == NULL) {
                m_pRoot = m_pRoot->m_pRight;
            }
            else {
                EmployeeRecord *succ;
                succ = getSuccessor(m_pRoot->m_pLeft);
                if (m_pRoot->m_pLeft != succ) {
                    succ->m_pLeft = m_pRoot->m_pLeft;
                }
                if (m_pRoot->m_pRight != succ) {
                    succ->m_pRight = m_pRoot->m_pRight;
                }
                m_pRoot = succ;
            }
        }
    }
    return ret;
}

EmployeeRecord *EmployeeDatabase::removeEmployee(int ID, EmployeeRecord *node) {
    EmployeeRecord *ret;
    if (node == NULL) {
        ret = NULL;
    }
    else {
        if (ID < node->getID()) {
            if (ID == node->m_pLeft->getID()) {
                ret = removeHelp(ID, node);
            }
            else {
                ret = removeEmployee(ID, node->m_pLeft);
            }
        }
        else if (ID > node->getID()) {
            if (ID == node->m_pRight->getID()) {
                ret = removeHelp(ID, node);
            }
            else {
                ret = removeEmployee(ID, node->m_pRight);
            }
        }
    }
    return ret;
}

EmployeeRecord *EmployeeDatabase::removeHelp(int ID, EmployeeRecord *nodeParent) {
    EmployeeRecord *ret;
    EmployeeRecord *node;
    if (nodeParent->m_pLeft != NULL && ID == nodeParent->m_pLeft->getID()) {
        node = nodeParent->m_pLeft;
    }
    else if (nodeParent->m_pRight != NULL && ID == nodeParent->m_pRight->getID()) {
        node = nodeParent->m_pRight;
    }
    char *fname = new char[32];
    char *lname = new char[32];
    node->getName(fname, lname);
    ret = new EmployeeRecord(node->getID(), fname, lname, node->getDept(), node->getSalary(), node->getCustomerList());
    node->removeCustomerList();
    std::cout << "removing node: " << node->getID() << std::endl;
    if (node->m_pLeft == NULL && node->m_pRight == NULL) {
        if (nodeParent->m_pLeft != NULL && ID == nodeParent->m_pLeft->getID()) {
            nodeParent->m_pLeft = NULL;
        }
        else {
            nodeParent->m_pRight = NULL;
        }
    }
    else if (node->m_pRight == NULL) {
        if (nodeParent->m_pLeft != NULL && ID == nodeParent->m_pLeft->getID()) {
            nodeParent->m_pLeft = node->m_pLeft;
        }
        else {
            nodeParent->m_pRight = node->m_pLeft;
        }
    }
    else if (node->m_pLeft == NULL) {
        if (nodeParent->m_pLeft != NULL && ID == nodeParent->m_pLeft->getID()) {
            nodeParent->m_pLeft = node->m_pRight;
        }
        else {
            nodeParent->m_pRight = node->m_pRight;
        }
    }
    else {
        EmployeeRecord *succ;
        succ = getSuccessor(node->m_pLeft);
        if (ID == nodeParent->m_pLeft->getID()) {
            succ->m_pLeft = node->m_pLeft;
            succ->m_pRight = node->m_pRight;
            nodeParent->m_pLeft = succ;
        }
        else {
            nodeParent->m_pRight = succ;
            succ->m_pLeft = node->m_pLeft;
            succ->m_pRight = node->m_pRight;
        }
    }
    delete node;
    return ret;
}

EmployeeRecord *EmployeeDatabase::getSuccessor(EmployeeRecord *node) {
    EmployeeRecord *succ;
    if (node->m_pRight != NULL) {
        succ = getSuccessor(node->m_pRight);
    }
    else {
        succ = removeEmployee(node->getID());
    }
    return succ;
}

void EmployeeDatabase::printEmployeeRecords() {
    if (m_pRoot == NULL) {
        std::cout << "-------Empty Employee Databse-------" << std::endl;
    }
    else {
        printEmployeeRecords(m_pRoot, 0);
    }
}

void EmployeeDatabase::printEmployeeRecords(EmployeeRecord *rt, int level) {
    if (rt != NULL) {
        ++level;
        printEmployeeRecords(rt->m_pLeft, level);
        //rt->printRecord();
        for (int i=0; i!=level; i++) {
            std::cout << "  ";
        }
        std:: cout << rt->getID() << std::endl;
        printEmployeeRecords(rt->m_pRight, level);
    }
}

void EmployeeDatabase::destroyTree(EmployeeRecord *rt) {
    std::cout << "destroyed" << std::endl;
}

//-----------------------------------------------------
// Build the database
//-----------------------------------------------------
bool EmployeeDatabase::buildDatabase(char *dataFile)
{
	bool OK = true;
	int numEmp, id, dept, numStores, sID;
	double sal;
	EmployeeRecord *empRec;
	CustomerList *theList;
	Store *theStore;
	char inStr[128];
	char fName[32];
	char lName[32];
	char sName[64];
	char sAddr[64];
	char sSt[32];
	char sCity[32];
	char sZip[12];


	inFile.open(dataFile, ifstream::in);
    if(!inFile.is_open())
    {
        // inFile.is_open() returns false if the file could not be found or
        //    if for some other reason the open failed.
        cout << "Unable to open file" << dataFile << "\nProgram terminating...\n";
		cout << "Press Enter to continue...";
		getc(stdin);
        return false;
    }

	// Get number of employees
	getNextLine(inStr, 128);
	numEmp = atoi(inStr);
	for(int i=0; i<numEmp; i++)
	{
		// Instantiate an EmployeeRecord
		empRec = new EmployeeRecord();
		// Read and set the ID
		getNextLine(inStr, 127);
		id = atoi(inStr);
		empRec->setID(id);
		// Read and set the name
		getNextLine(fName, 31);
		getNextLine(lName, 31);
		empRec->setName(fName, lName);
		// Read and set the Department ID
		getNextLine(inStr, 127);
		dept = atoi(inStr);
		empRec->setDept(dept);
		// Read and set the Salary
		getNextLine(inStr, 127);
		sal = atof(inStr);
		empRec->setSalary(sal);
		// Get the customer list
		theList = empRec->getCustomerList();
		// Get the number of stores
		getNextLine(inStr, 127);
		numStores = atoi(inStr);
		for(int j=0; j<numStores; j++)
		{
			// Read the store ID
			getNextLine(inStr, 127);
			sID = atoi(inStr);
			// Read the store name
			getNextLine(sName, 63);
			// Read the store address
			getNextLine(sAddr, 63);
			// Read the store city
			getNextLine(sCity, 31);
			// Read the store state
			getNextLine(sSt, 31);
			// Read the store zip
			getNextLine(sZip, 11);
			// Create a new Store object
			theStore = new Store(sID, sName, sAddr, sCity, sSt, sZip);
			theList->addStore(theStore);
		}
		cout.flush();
		addEmployee(empRec);
	}
	inFile.close();
	return OK;	// Successfully built the database
}

//--------------------------------------------
// GetNextLine()
// Read a line from a data file.
// Author: Rick Coleman
// Used by permission
//--------------------------------------------
bool EmployeeDatabase::getNextLine(char *line, int lineLen)
{
    int    done = false;
    while(!done)
    {
        inFile.getline(line, 128);

        if(inFile.good())    // If a line was successfully read
        {
            if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else return true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");
            return false;
        }
    } // end while
    return false;
}
