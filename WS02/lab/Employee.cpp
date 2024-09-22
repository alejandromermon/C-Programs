/******************************************************************
				Workshop 2 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 25/05/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Employee.h"
#include "File.h"
using namespace std;
namespace seneca {

	int noOfEmployees;
	Employee* employees;


	void sort() {
		int i, j;
		Employee temp;
		for (i = noOfEmployees - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (employees[j].m_empNo > employees[j + 1].m_empNo) {
					temp = employees[j];
					employees[j] = employees[j + 1];
					employees[j + 1] = temp;
				}
			}
		}
	}

	bool load(Employee& emp) {
		bool ok = false;
		char name[128] = { 0 };
		int len, empNumber;
		double salary;

		if (read(empNumber) && read(salary) && read(name)) {
			len = strlen(name) + 1;
			emp.m_name = new char[len];
			strcpy(emp.m_name, name);

			emp.m_empNo = empNumber;
			emp.m_salary = salary;

			ok = true;
		}
		return ok;
	}
	bool load() {
		bool ok = false;
		int i = 0, valRec = 0;
		if (openFile(DATAFILE)) {
			noOfEmployees = noOfRecords();

			employees = new Employee[noOfEmployees];

			for (i = 0; i < noOfEmployees; i++) {
				ok = load(employees[i]);

				if (ok)
					valRec++;
			}

			if (valRec != noOfEmployees) {
				cout << "Error: incorrect number of records read; the data is possibly corrupted.\n";
				ok = false;
			}
			else
			{
				ok = true;
			}

			closeFile();
		}
		else {
			cout << "Could not open data file: " << DATAFILE << endl;
		}
		return ok;
	}

	void display(const Employee& emp) {
		cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
	}
	void display() {
		int i = 0;

		cout << "Employee Salary report, sorted by employee number\n";
		cout << "no- Empno, Name, Salary\n";
		cout << "------------------------------------------------\n";

		sort();

		for (i = 0; i < noOfEmployees; i++) {
			cout << i + 1 << "- ";
			display(employees[i]);
		}
	}

	void deallocateMemory() {
		int i;

		for (i = 0; i < noOfEmployees; i++) {
			delete[] employees[i].m_name;
		}

		delete[] employees;
	}

}