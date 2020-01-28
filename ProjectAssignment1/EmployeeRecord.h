#ifndef EMPLOYEERECORD_H
#define EMPLOYEERECORD_H

class EmployeeRecord {
    private:
        int m_iEmployeeID;
        char *m_sLastName;
        char *m_sFirstName;
        int m_iDeptID;
        double m_dSalary;

    public:
        EmployeeRecord();
        EmployeeRecord(int ID, char *fName, char *lName, int dept, double sal);
        ~EmployeeRecord();
        int getID();
        void setID(int ID);
        void getName(char *fName, char *lName);
        void setName(char *fName, char *lName);
        void getDept(int& d);
        void setDept(int d);
        void getSalary(double *sal);
        void setSalary(double sal);
        void printRecord();
};

#endif
