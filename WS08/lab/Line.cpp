/******************************************************************
                Workshop 8 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 20/07/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/
#include <iostream>
#include "Line.h"

using namespace std;

namespace seneca {
    Line::Line(const char* label, const int length) : LblShape(label){
        m_length = length;
    }
    void Line::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.clear();
        while (is.get() != '\n');
    }
    void Line::draw(ostream& os) const{
        if (m_length > 0 && label()) {
            os << label() << endl;
            for (auto i = 0; i < m_length; i++)
                os << '=';
        }
    }
}