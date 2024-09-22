/******************************************************************
                Workshop 3 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 01/06/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#ifndef SENECA_ITEM_H_
#define SENECA_ITEM_H_

namespace seneca {
   class Item {
      char m_itemName[21]; // holds the item name up to 20 chars
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;
      double price()const;
      double tax()const;
   };
}

#endif // !SENECA_SUBJECT_H
