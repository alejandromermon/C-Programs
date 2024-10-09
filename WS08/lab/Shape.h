/******************************************************************
                Workshop 8 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 20/07/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>

namespace seneca {                                                                      
    class Shape {
    public:
        virtual void draw(std::ostream& os) const = 0;
        virtual void getSpecs(std::istream& is) = 0;

        virtual ~Shape() = default;
    };
    std::ostream& operator <<(std::ostream& os, const Shape& sh);
    std::istream& operator >>(std::istream& is, Shape& sh);
}
#endif // !SENECA_SHAPE_H
