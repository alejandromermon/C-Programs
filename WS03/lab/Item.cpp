/******************************************************************
				Workshop 3 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 01/06/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

namespace seneca {
	const double salesTax = 0.13;

	void Item::setEmpty() {
		m_itemName[0] = '\0';
		m_price = 0.0;
		m_taxed = false;
	}

	void Item::set(const char* name, double price, bool taxed) {
		if (name == nullptr || m_itemName[0] == '\0' || price < 1)
			setEmpty();
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}

	}

	void Item::setName(const char* name) {
		strncpy(m_itemName, name, 20);
		m_itemName[20] = '\0';
	}

	double Item::price()const {
		return m_price;
	}

	double Item::tax()const {
		double calcTax;

		if (m_taxed)
			calcTax = m_price * salesTax;
		else
			calcTax = 0;

		return calcTax;
	}

	bool Item::isValid()const {
		bool valid = true;

		if (m_itemName[0] == '\0' || m_itemName == nullptr)
			valid = false;

		return valid;
	}

	void Item::display()const {
		if (isValid()) {
			cout << "| ";

			cout.fill('.');
			cout.width(20);
			cout.setf(ios::left);
			cout << m_itemName;
			cout << " | ";

			// Reset output objects
			cout.fill(' ');
			cout.unsetf(ios::left);

			cout.width(7);
			cout.precision(2);
			cout.setf(ios::fixed);
			cout << m_price;
			cout << " | ";

			cout << (m_taxed ? "Yes" : "No ");
			cout << " |" << endl;
		}
		else
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
	}

}