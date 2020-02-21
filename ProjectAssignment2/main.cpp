#include <iostream>
#include "EmployeeRecord.h"
#include "CustomerList.h"
#include "Store.h"

int main(){
	char fname2[32] = "James";
	char lname2[32] = "Abers";
	CustomerList *cl = new CustomerList;
	Store *s = new Store;
	bool failure = cl->addStore(s);
	if (!failure) {std::cout << "add failed" << std::endl;}
	Store *retRemove = cl->removeStore(19);
	Store *retGet = cl->getStore(10);
	if (retRemove == NULL) {std::cout<< "remove Null" << std::endl;}
	if (retGet == NULL) {std::cout<< "get Null" << std::endl;}
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
	bool retUpdateFail = cl->updateStore(10, name, addr, city, stat, zipc);
	if (!retUpdateFail) {std::cout << "update fail" << std::endl;}
	cl->printStoresInfo();

	Store *s2 = new Store;
	s2->setStoreID(5);
	s2->setStoreName(name);
	s2->setStoreAddress(addr);
	s2->setStoreCity(city);
	s2->setStoreState(stat);
	s2->setStoreZip(zipc);

	s2->printStoreInfo();

	Store *s3 = new Store;
	s3->setStoreID(8);
	s3->setStoreName(name3);
	s3->setStoreAddress(addr3);
	s3->setStoreCity(city3);
	s3->setStoreState(stat3);
	s3->setStoreZip(zipc3);

	cl->addStore(s2);
	cl->printStoresInfo();

    s->setStoreID(7);
	s->setStoreName(name2);
	s->setStoreAddress(addr2);
	s->setStoreCity(city2);
	s->setStoreState(stat2);
	s->setStoreZip(zipc2);

	cl->addStore(s);
	cl->addStore(s3);
	cl->printStoresInfo();

	retRemove = cl->removeStore(7);
	retGet = cl->getStore(7);
	retRemove->printStoreInfo();
	//retGet->printStoreInfo();

	bool retUpdateSuccess = cl->updateStore(8, name, addr, city, stat, zipc);
	if (retUpdateSuccess) {cl->printStoresInfo();}

	EmployeeRecord er2(2, fname2, lname2, 3, 50000.0, cl);

	return 0;
}
