/******************************************************************
                Workshop 8 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 20/07/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include "LblShape.h"

using namespace std;

namespace seneca {
    LblShape::LblShape(const char* label) {
        m_label = new char[strlen(label) + 1];
        strcpy(m_label, label);
    }
    LblShape::~LblShape() {
        delete[] m_label;
    }
    char* LblShape::label() const {
        return m_label;
    }
    void LblShape::getSpecs(istream& is) {
        string str;

        getline(is, str, ',');

        delete[] m_label;
        m_label = new char[strlen(str.c_str()) + 1];
        strcpy(m_label, str.c_str());
    }
}