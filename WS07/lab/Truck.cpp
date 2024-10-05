/******************************************************************
				Workshop 7 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 13/07/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Truck.h"

using namespace std;

namespace seneca {
	Truck::Truck(const char plate[], const int year, const double capacity, const char address[]) :
		MotorVehicle(plate, year)
	{
		m_capacity = capacity;
		m_currCargo = 0;
		moveTo(address);
	}
	// Adds to the attribute that stores the current cargo load the weight specified as a parameter.
	//  Returns true if added, false if not.
	bool Truck::addCargo(double cargo) {
		bool hasChanged = false;

		if (cargo && m_currCargo != m_capacity)
		{
			m_currCargo += cargo;
			m_currCargo = m_currCargo > m_capacity ? m_capacity : m_currCargo;
			hasChanged = true;
		}
		return hasChanged;
	}
	// Unloads current cargo (sets the attribute to 0). Returns true if unloaded, false if not.
	bool Truck::unloadCargo() {
		bool hasChanged = false;

		if (m_currCargo) {
			m_currCargo = 0;
			hasChanged = true;
		}
		return hasChanged;
	}
	// Displays the Truck object
	ostream& Truck::write(ostream& os) const {
		return MotorVehicle::write(os) << " | " << m_currCargo << '/' << m_capacity;
	}
	// Reads from the stream in the data for the current object
	istream& Truck::read(istream& in) {
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_currCargo;

		return in;
	}

	ostream& operator <<(ostream& os, const Truck& tr) {
		return tr.write(os);
	}
	istream& operator >>(istream& in, Truck& tr) {
		return tr.read(in);
	}
}