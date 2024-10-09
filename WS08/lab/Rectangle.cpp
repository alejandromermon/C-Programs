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
#include <cstring>
#include "Rectangle.h"

using namespace std;

namespace seneca {
    Rectangle::Rectangle(const char* label, const int width, const int height) : LblShape(label) {
        if (height >= 3 && width > signed(strlen(label) + 2)) {
            m_width = width;
            m_height = height;
        }
    }
    void Rectangle::getSpecs(istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.clear();
        while (is.get() != '\n');
    }
    void Rectangle::draw(ostream& os) const {
        if (m_width) {
            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+' << endl;

            os << '|';
            os.width(m_width - 2);
            os.fill(' ');
            os.setf(ios::left);
            os << label() << '|' << endl;
            os.unsetf(ios::left);

            for (auto i = 0; i < m_height - 3; i++) {
                os << '|';
                os.width(m_width - 2);
                os << ' ' << '|' << endl;
            }

            os << '+';
            os.width(m_width - 2);
            os.fill('-');
            os << '-' << '+';
        }
    }
}