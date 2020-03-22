# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: main.o EmployeeRecord.o CustomerList.o Store.o EmployeeDatabase.o
	$(CXX) $(CXXFLAGS) -o main main.o EmployeeRecord.o CustomerList.o Store.o EmployeeDatabase.o

# The main.o target can be written more simply

main.o: main.cpp EmployeeRecord.h CustomerList.h Store.h
	$(CXX) $(CXXFLAGS) -c main.cpp

EmployeeDatabase.o: EmployeeDatabase.h EmployeeRecord.h

EmployeeRecord.o: EmployeeRecord.h CustomerList.h Store.h

CustomerList.o: CustomerList.h Store.h

Store.o: Store.h
