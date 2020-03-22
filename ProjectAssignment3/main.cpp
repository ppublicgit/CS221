#include <iostream>
#include "EmployeeRecord.h"
#include "CustomerList.h"
#include "Store.h"
#include "EmployeeDatabase.h"

int main(){

    // create customer lists, and datasets
    CustomerList *p_EmptyCL = new CustomerList;
    CustomerList *p_FullCL = new CustomerList;

    char name[5] = "name";
	char addr[8] = "address";
	char city[5] = "city";
	char stat[7] = "state";
	char zipc[8] = "zipcode";

	char name2[6] = "name2";
	char addr2[9] = "address2";
	char city2[6] = "city2";
	char stat2[8] = "state2";
	char zipc2[9] = "zipcode2";

	char name3[6] = "name3";
	char addr3[9] = "address3";
	char city3[6] = "city3";
	char stat3[8] = "state3";
	char zipc3[9] = "zipcode3";

    Store *s2 = new Store;
	s2->setStoreID(5);
	s2->setStoreName(name);
	s2->setStoreAddress(addr);
	s2->setStoreCity(city);
	s2->setStoreState(stat);
	s2->setStoreZip(zipc);

	Store *s3 = new Store;
	s3->setStoreID(8);
	s3->setStoreName(name3);
	s3->setStoreAddress(addr3);
	s3->setStoreCity(city3);
	s3->setStoreState(stat3);
	s3->setStoreZip(zipc3);

    Store *s = new Store;
    s->setStoreID(7);
	s->setStoreName(name2);
	s->setStoreAddress(addr2);
	s->setStoreCity(city2);
	s->setStoreState(stat2);
	s->setStoreZip(zipc2);

	p_FullCL->addStore(s);
    p_FullCL->addStore(s2);
	p_FullCL->addStore(s3);
	//p_FullCL->printStoresInfo();

    char fname1[32] = "James";
	char lname1[32] = "Abers";
    EmployeeRecord *er1 = new EmployeeRecord(50, fname1, lname1, 3, 50000.0, p_EmptyCL);
    //er2.printRecord();

    char fname2[32] = "Paul";
	char lname2[32] = "Abers";
    EmployeeRecord *er2 = new EmployeeRecord(30, fname2, lname2, 3, 50000.0, p_EmptyCL);
    //er2.printRecord();

    char fname3[32] = "Max";
	char lname3[32] = "Abers";
    EmployeeRecord *er3 = new EmployeeRecord(20, fname3, lname3, 3, 50000.0, p_EmptyCL);
    //er2.printRecord();

    char fname4[32] = "Rich";
	char lname4[32] = "Abers";
    EmployeeRecord *er4 = new EmployeeRecord(40, fname4, lname4, 3, 50000.0, p_EmptyCL);
    //er2.printRecord();

    char fname5[32] = "Jazz";
	char lname5[32] = "Abers";
    EmployeeRecord *er5 = new EmployeeRecord(70, fname5, lname5, 3, 50000.0, p_EmptyCL);
    //er2.printRecord();

    char fname6[32] = "Ann";
	char lname6[32] = "Abers";
    EmployeeRecord *er6 = new EmployeeRecord(60, fname6, lname6, 3, 50000.0, p_FullCL);

    char fname7[32] = "Lana";
	char lname7[32] = "Abers";
    EmployeeRecord *er7 = new EmployeeRecord(80, fname7, lname7, 3, 50000.0, p_FullCL);

    EmployeeDatabase *ed = new EmployeeDatabase();
    ed->addEmployee(er1);
    ed->addEmployee(er2);
    ed->addEmployee(er3);
    ed->addEmployee(er4);
    ed->addEmployee(er5);
    ed->addEmployee(er6);
    ed->addEmployee(er7);
    ed->printEmployeeRecords();

    // Test getEmployee, addEmployee, and printEmployeerecords
    EmployeeRecord *ret;
/*
    ret = ed->getEmployee(60);
    ret->printRecord();
    ed->printEmployeeRecords();

    // Test destroy and remove customer list work properly
    EmployeeRecord *assign;
    CustomerList *acl;
    assign = ret;
    assign->printRecord();
    acl = assign->getCustomerList();
    acl->printStoresInfo();
    ret->removeCustomerList();
    delete ret;
    std::cout << "ret deleted " << std::endl;
    assign->printRecord();
    acl->printStoresInfo();
*/
    // Test removeEmployee
    // Test no child removal
    ret = ed->removeEmployee(30);
    ret->printRecord();
    ed->printEmployeeRecords();
    // Test one child left removal
    ret = ed->removeEmployee(20);
    ret->printRecord();
    ed->printEmployeeRecords();
    // Test one child right removal
    ret = ed->removeEmployee(50);
    ret->printRecord();
    ed->printEmployeeRecords();
    // Test two child removal
    ret = ed->removeEmployee(60);
    ret->printRecord();
    ed->printEmployeeRecords();

    ret = ed->removeEmployee(70);
    ret->printRecord();
    ed->printEmployeeRecords();

    ret = ed->removeEmployee(40);
    ret->printRecord();
    ed->printEmployeeRecords();

    ret = ed->removeEmployee(80);
    ret->printRecord();
    ed->printEmployeeRecords();

    ret = ed->removeEmployee(70);

    ret = ed->getEmployee(30);

	return 0;
}
