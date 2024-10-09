/******************************************************************
                Workshop 8 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 20/07/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/
#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include <iostream>
#include "LblShape.h"

namespace seneca {
    class Line : public LblShape {
        int m_length{};
    public:
        Line() : LblShape() {};
        Line(const char* label, const int length);
        virtual ~Line() = default;

        void getSpecs(std::istream& is);
        void draw(std::ostream& os) const;
    };
}
#endif // !SENECA_LINE_H
