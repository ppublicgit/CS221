#include <iostream>
#include "EmployeeRecord.h"

int main(){
	EmployeeRecord er;
	er.printRecord();
	
	std::cout << "Current ID is: " << er.getID() << std::endl;
    std::cout << "Setting ID to 4" << std::endl;
	er.setID(4);
	std::cout << "New ID is: " << er.getID() << std::endl;
	std::cout << std::endl;
	
	char fname[32];
	char lname[32];
	er.getName(fname, lname);
	std::cout << "Current Last Name: " << lname << std::endl;
	std::cout << "Current First Name: " << fname << std::endl;
	std::cout << "Setting Last Name to: Abers" << std::endl;
	std::cout << "Setting First Name to: Paul" << std::endl;
	char newfname[32] = "Paul";
	char newlname[32] = "Abers";
	er.setName(newfname, newlname);
	er.getName(fname, lname);
	std::cout << "New Last Name: " << lname << std::endl;
	std::cout << "New First Name: " << fname << std::endl;
	std::cout << std::endl;

	int deptID = -1000;
	er.getDept(deptID);
	std::cout << "Current Deparment ID: " << deptID << std::endl;
	std::cout << "Setting Department ID: 5" << std::endl;
	er.setDept(5);
	er.getDept(deptID);
	std::cout << "New Department ID: " << deptID << std::endl;
	std::cout << std::endl;

	double *salary_ptr = new double;
	double salary = -10000.0;
	salary_ptr = &salary;
	std::cout << "Initialized Salary: " << *salary_ptr << std::endl;
	std::cout << "Salary Memory Address: " << salary_ptr << std::endl;
	er.getSalary(salary_ptr);
	std::cout << "Current Salary: " << *salary_ptr << std::endl;
	std::cout << "Setting Salary: 60000.0" << std::endl;
	double *new_salary_ptr = new double;
	*salary_ptr=60000.0;
	er.setSalary(*salary_ptr);
	er.getSalary(salary_ptr);
	er.getSalary(new_salary_ptr);
	std::cout << "New Salary: " << *new_salary_ptr << std::endl;
	std::cout << "New Salary: " << *salary_ptr << std::endl;
	std::cout << "Salary Ptr Address: " << salary_ptr << std::endl;
	std::cout << "New Salary Ptr Address: " << new_salary_ptr << std::endl;
	std::cout << std::endl;

	er.printRecord();

	char fname2[32] = "James";
	char lname2[32] = "Abers";
    EmployeeRecord er2(2, fname2, lname2, 3, 50000.0);
    er2.printRecord();

	delete new_salary_ptr;
	
	return 0;
}
