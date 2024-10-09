/******************************************************************
				Workshop 8 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 20/07/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/
#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include <iostream>
#include "LblShape.h"

namespace seneca {
	class Rectangle : public LblShape {
		int m_width = 0,
			m_height = 0;
	public:
		Rectangle() : LblShape() {};
		Rectangle(const char* label, const int width, const int height);
		virtual ~Rectangle() = default;

		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};
}
#endif // !SENECA_RECTANGLE_H
