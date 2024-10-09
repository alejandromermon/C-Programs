/******************************************************************
                Workshop 8 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 20/07/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/
#ifndef SENECA_LBLSHAPE_H
#define SENECA_LBLSHAPE_H
#include <iostream>
#include "Shape.h"

namespace seneca {
    class LblShape : public Shape {
        char* m_label{};
    protected:
        char* label() const;
    public:
        LblShape() = default;
        LblShape(const char* label);

        virtual ~LblShape();
        LblShape(LblShape&) = delete;
        void operator =(LblShape&) = delete;

        virtual void getSpecs(std::istream& is);
    };
}
#endif // !SENECA_LBLSHAPE_H
