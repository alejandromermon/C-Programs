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
#include "Shape.h"

using namespace std;

namespace seneca {
    ostream& operator <<(ostream& os, const Shape& sh) {
        sh.draw(os);
        return os;
    }
    istream& operator >>(istream& is, Shape& sh) {
        sh.getSpecs(is);
        return is;
    }
}