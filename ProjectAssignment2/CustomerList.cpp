/***********************************************
 * File: CustomerList.cpp
 * Author: Paul Abers
 * Assignment 2: Customer List Class
 *
 * This program is entirely my own work.
 **********************************************/

#include <iostream>
#include <string.h>
#include "CustomerList.h"

CustomerList::CustomerList() { //Default Constructor with initialized values for class
    m_pHead = NULL;
}

CustomerList::~CustomerList() { //Destructor for class
	// nothing to do here;
}

bool checkNull(Store *s) { //check if any attributes of store are null and return false if so
	bool ret = false;
	if (s->getStoreID() == 0) { ret = true; }
	if (s->getStoreName() == NULL) { ret = true; }
	if (s->getStoreAddress() == NULL) { ret = true; }
	if (s->getStoreCity() == NULL) { ret = true; }
	if (s->getStoreState() == NULL) { ret = true; }
	if (s->getStoreZip() == NULL) { ret = true; }
	return ret;
}

bool CustomerList::addStore(Store *s) { //add a store to customer list
	bool success = false;
	if (checkNull(s)) {
		success = false;
	}
	else {
		if (m_pHead == NULL) {
			m_pHead = s;
			success = true;
		}
		else {
			int inputStoreID = s->getStoreID();
			Store *curr = m_pHead;
			if (inputStoreID < curr->getStoreID()) {
				s->m_pNext = curr;
				m_pHead = s;
				success = true;
			}
			else {
				while (curr->m_pNext != NULL) {
					if (inputStoreID < curr->m_pNext->getStoreID()) {
						s->m_pNext = curr->m_pNext;
						curr->m_pNext = s;
						success = true;
						break;
					}
					curr = curr->m_pNext;
				}
				if (success == false) {
					curr->m_pNext = s;
					success = true;
				}
			}
		}
	}
	return success;
}

Store *CustomerList::removeStore(int ID) { //remove store with id ID from list
	Store *removed;
	Store *curr = m_pHead;
	bool found = false;
	if (m_pHead == NULL) {
		removed = NULL;
	}
	else {
		if (curr->getStoreID() == ID) {
			removed = curr;
			m_pHead = curr->m_pNext;
		}
		else {
			while (curr->m_pNext != NULL) {
				if (curr->m_pNext->getStoreID() == ID) {
					removed = curr->m_pNext;
					curr->m_pNext = curr->m_pNext->m_pNext;
					found = true;
					break;
				}
				curr = curr->m_pNext;
			}
			if (!found) {
				removed = NULL;
			}
		}
	}
	return removed;
}

Store *CustomerList::getStore(int ID) { //get store with id ID from list
	Store *curr = m_pHead;
	bool found = false;
	if (curr == NULL || curr->getStoreID() == ID) {
	    found = true;
	}
	else {
		while (curr->m_pNext != NULL) {
			if (curr->m_pNext->getStoreID() == ID) {;
				curr = curr->m_pNext;
				found = true;
				break;
			}
			curr = curr->m_pNext;
		}
		if (!found) {
			if (curr->getStoreID() != ID) {
				curr = NULL;
			}
		}
	}
	return curr;
}

bool CustomerList::updateStore(int ID, char *name, char *addr, char *city, char *st, char *zip) { // update store with id ID from list
	Store *curr = m_pHead;
	bool update = false;
	if (curr == NULL) {
	    update = false;
	}
	else if (curr->getStoreID() == ID) {
		curr->setStoreName(name);
		curr->setStoreAddress(addr);
		curr->setStoreCity(city);
		curr->setStoreState(st);
		curr->setStoreZip(zip);
		update = true;
	}
	else {
		while (curr->m_pNext != NULL) {
			if (curr->m_pNext->getStoreID() == ID) {;
				curr = curr->m_pNext;
				curr->setStoreName(name);
				curr->setStoreAddress(addr);
				curr->setStoreCity(city);
				curr->setStoreState(st);
				curr->setStoreZip(zip);
				update = true;
				break;
			}
			curr = curr->m_pNext;
		}
		if (!update) {
			if (curr->getStoreID() == ID) {
				curr->setStoreName(name);
				curr->setStoreAddress(addr);
				curr->setStoreCity(city);
				curr->setStoreState(st);
				curr->setStoreZip(zip);
				update = true;
			}
		}
	}
	return update;
}

void CustomerList::printStoresInfo() { //print each stores info in list
	std::cout << "---------Customer List-----------" << std::endl;
	if (m_pHead != NULL) {
		Store *curr = m_pHead;
		while (curr->m_pNext != NULL) {
			curr->printStoreInfo();
			curr = curr->m_pNext;
		}
		curr->printStoreInfo();
	}
	else {
		std::cout << "-----------Empty List------------" << std::endl;
	}
	std::cout << std::endl;
	return;
}
