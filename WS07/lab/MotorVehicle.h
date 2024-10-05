/******************************************************************
                Workshop 7 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 13/07/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#ifndef SENECA_MOTORVEHICLE_H
#define SENECA_MOTORVEHICLE_H
#include <iostream>

namespace seneca {
    class MotorVehicle {
        char m_plate[9]{};
        char m_address[64]{};
        int m_year;

    public:
        MotorVehicle(const char plate[], const int year);

        // Moves the vehicle to the new address if the new address is different from the current address
        void moveTo(const char* address);
        // Displays the MotorVehicle object
        std::ostream& write(std:: ostream& os) const;
        // Reads from the stream in the data for the current object
        std::istream& read(std::istream& in);
    };
    std::ostream& operator <<(std::ostream& os, const MotorVehicle& mv);
    std::istream& operator >>(std::istream& in, MotorVehicle& mv);
}

#endif // !SENECA_MOTORVEHICLE_H
