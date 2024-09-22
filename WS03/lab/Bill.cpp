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
#include "Bill.h"

using namespace std;

namespace seneca {
	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid()const {
		bool valid = false;

		if (m_title[0] != '\0' && m_items != nullptr) {
			valid = true;
			for (auto i = 0; i < m_noOfItems && valid; i++) {
				valid = m_items[i].isValid();
			}
		}

		return valid;
	}

	double Bill::totalTax()const {
		double calcTax = 0;

		for (auto i = 0; i < m_noOfItems; i++) {
			if (m_items[i].isValid())
				calcTax += m_items[i].tax();
		}

		return calcTax;
	}

	double Bill::totalPrice()const {
		double total = 0;

		for (auto i = 0; i < m_noOfItems; i++) {
			if (m_items[i].isValid())
				total += m_items[i].price();
		}

		return total;
	}

	void Bill::title()const {
		cout << "+--------------------------------------+" << endl;

		if (isValid()) {
			cout << "| ";
			cout.width(36);
			cout.setf(ios::left);
			cout << m_title;
			cout << " |" << endl;
			cout.unsetf(ios::left);
		}
		else
			cout << "| Invalid Bill                         |" << endl;

		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;

		if (isValid()) {
			cout << "|                Total Tax: ";

			cout.precision(2);
			cout.width(10);
			cout << totalTax();
			cout << " |" << endl;

			cout << "|              Total Price: ";
			cout.width(10);
			cout << totalPrice();
			cout << " |" << endl;

			cout << "|          Total After Tax: ";
			cout.width(10);
			cout << totalTax() + totalPrice();
			cout << " |" << endl;
		}
		else
			cout << "| Invalid Bill                         |" << endl;

		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems) {

		if (title == nullptr || noOfItems < 1)
			setEmpty();
		else
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;

			strncpy(m_title, title, 36);
			m_title[36] = '\0';
			m_items = new Item[m_noOfItems];

			// Set all items from the newly created array to an empty state
			for (auto i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		int added = false;

		if (m_itemsAdded < m_noOfItems && price > 0) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			added = true;
		}

		return added;
	}

	void Bill::display()const {
		title();

		for (auto i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}

		footer();
	}

	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}
}