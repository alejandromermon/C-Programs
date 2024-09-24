/******************************************************************
				Workshop 4 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 08/06/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include <cstring>
#include "Canister.h"

using namespace std;

namespace seneca {
	const double PI = 3.14159265;

	// ***********       Private methods       **********

	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_height = 13.0;
		m_diameter = 10.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	bool Canister::isEmpty()const {
		bool empty = false;

		if (m_contentVolume < 0.00001)
			empty = true;

		return empty;
	}

	bool Canister::hasSameContent(const Canister& C)const {
		bool sameContent = false;

		if (m_contentName != nullptr && C.m_contentName != nullptr &&
			!strcmp(m_contentName, C.m_contentName))
			sameContent = true;

		return sameContent;
	}

	void Canister::setName(const char* Cstr) {
		if (Cstr != nullptr && m_usable)
		{
			delete[] m_contentName;
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
		}
	}

	// ***********       Constructors       **********

	Canister::Canister() {
		setToDefault();
	}

	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();

		if (height < 10 || height > 40 || diameter < 10 || diameter > 30)
			m_usable = false;
		else
		{
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0;

			setName(contentName);
		}
	}

	// ***********       Destructor       **********

	Canister::~Canister() {
		delete[] m_contentName;
	}

	// ***********       Public methods       **********

	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0;
		m_usable = true;
	}

	double Canister::capacity()const {
		double capacity;

		capacity = PI * (m_height - 0.267) * (m_diameter / 2.0) * (m_diameter / 2.0);

		return capacity;
	}

	double Canister::volume()const {
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName) {
		if (contentName == nullptr)
			m_usable = false;
		else if (isEmpty())
			setName(contentName);
		else if (!hasSameContent(contentName))
			m_usable = false;

		return *this;
	}

	Canister& Canister::pour(double quantity) {
		if (m_usable && quantity > 0 && (quantity + volume()) <= capacity())
			m_contentVolume += quantity;
		else
			m_usable = false;

		return *this;
	}

	Canister& Canister::pour(Canister& C) {
		double availableVolume;

		if (m_usable && C.m_usable)
		{
			setContent(C.m_contentName);

			availableVolume = capacity() - volume();

			if (C.volume() > availableVolume)
			{
				C.m_contentVolume -= availableVolume;
				m_contentVolume = capacity();
			}
			else
			{
				pour(C.m_contentVolume);
				C.m_contentVolume = 0;
			}
		}

		return *this;
	}

	std::ostream& Canister::display()const {
		cout.setf(ios::fixed);
		cout.precision(1);
		cout.width(7);
		cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";

		if (!m_usable)
			cout << " of Unusable content, discard!";
		else if (m_contentName != nullptr)
		{
			cout << " of ";
			cout.width(7);
			cout << m_contentVolume << "cc   " << m_contentName;
		}

		return cout;
	}
}