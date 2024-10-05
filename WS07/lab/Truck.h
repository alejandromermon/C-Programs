/******************************************************************
                Workshop 7 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 13/07/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#ifndef SENECA_TRUCK_H
#define SENECA_TRUCK_H
#include <iostream>
#include "MotorVehicle.h"

namespace seneca {
    class Truck : public MotorVehicle{
        double m_capacity;
        double m_currCargo;

    public:
        Truck(const char plate[], const int year, const double capacity, const char address[]);
        // Adds to the attribute that stores the current cargo load the weight specified as a parameter.
        //  Returns true if added, false if not.
        bool addCargo(double cargo);
        // Unloads current cargo (sets the attribute to 0). Returns true if unloaded, false if not.
        bool unloadCargo();
        // Displays the Truck object
        std::ostream& write(std::ostream& os) const;
        // Reads from the stream in the data for the current object
        std::istream& read(std::istream& in);
    };
    std::ostream& operator <<(std::ostream& os, const Truck& tr);
    std::istream& operator >>(std::istream& in, Truck& tr);
}

#endif // !TRUCK_H
