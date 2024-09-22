/******************************************************************
                Workshop 3 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 01/06/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#ifndef SENECA_BILL_H_
#define SENECA_BILL_H_
#include "Item.h"

namespace seneca {
   class Bill {
      char m_title[37]; // title of the shopping list
      Item* m_items;    // pointer to the dynamically allocated array of Items
      int m_noOfItems;  // size of the dynamically allocated array of Items
      int m_itemsAdded; // number of the Items added by the add method

      // returns the total tax applied to the Items
      double totalTax()const;

      // returns the sum of prices of Items
      double totalPrice()const;

      // Prints the title of the shopping list
      void title()const;

      // Prints the footer contaning total tax, price and total price after tax
      void footer()const;

      // sets the Bill to an emtpy state
      void setEmpty();

      // returns true is the Bill and all of its Items are valid
      bool isValid()const;
   public:
      void init(const char* title, int noOfItems);
      bool add(const char* item_name, double price, bool taxed);
      void display()const;
      void deallocate();
   };
}
#endif // !SENECA_TRANSCRIPT_H
