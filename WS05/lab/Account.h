/******************************************************************
                Workshop 5 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 15/06/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator ~() const;

      Account& operator =(const int num);
      Account& operator =(Account& src);
      Account& operator +=(const double amt);
      Account& operator -=(const double amt);
      Account& operator <<(Account& src);
      Account& operator >>(Account& dest);
   };
   
   double operator +(const Account& acc1, const Account& acc2);
   void operator +=(double& amt, const Account& acc);
}
#endif // SENECA_ACCOUNT_H_