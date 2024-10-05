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
#include <cstring>
#include <iostream>
#include "MotorVehicle.h"

using namespace std;

namespace seneca {
    MotorVehicle::MotorVehicle(const char plate[], const int year) {
        strcpy(m_plate, plate);
        m_year = year;
        strcpy(m_address, "Factory");
    }
    // Moves the vehicle to the new address if the new address is different from the current address
    void MotorVehicle::moveTo(const char* address){
        if (address && m_address != address) {
            cout << '|';
            cout.width(8);
            cout << m_plate << "| |";
            cout.width(20);
            cout << m_address << " ---> ";
            cout.setf(ios::left);
            cout.width(20);
            cout << address << '|' << endl;
            cout.unsetf(ios::left);

            strcpy(m_address, address);
        }
    }
    // Displays the MotorVehicle object
    ostream& MotorVehicle::write(ostream& os) const{
        return os << "| " << m_year << " | " << m_plate << " | " << m_address;
    }
    // Reads from the stream in the data for the current object
    istream& MotorVehicle::read(istream& in) {
        cout << "Built year: ";
        in >> m_year;
        cout << "License plate: ";
        in >> m_plate;
        cout << "Current location: ";
        in >> m_address;

        return in;
    }

    ostream& operator <<(ostream& os, const MotorVehicle& mv) {
        return mv.write(os);
    }
    istream& operator >>(istream& in, MotorVehicle& mv) {
        return mv.read(in);
    }
}