/***********************************************
 * File: CustomerList.h
 * Author: Paul Abers
 * Assignment 2: Customer List Class
 *
 * This program is entirely my own work.
 **********************************************/


#pragma once

#include "Store.h"

class CustomerList {
    private: // Declare private class variables
     	Store *m_pHead;

    public: // Declare public class methods
        CustomerList();
		~CustomerList();
    	bool addStore(Store *s);
		Store *removeStore(int ID);
		Store *getStore(int ID);
		bool updateStore(int ID, char *name, char *addr, char *city, char *st, char *zip);
		void printStoresInfo();
};
