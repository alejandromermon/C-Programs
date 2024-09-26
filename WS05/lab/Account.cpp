/******************************************************************
                Workshop 5 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 15/06/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   /********        Member Operators       ********/

   Account::operator bool() const
   {
       return m_number > 9999 && m_number < 100000 && m_balance >= 0 ? true : false;
   }
   Account::operator int() const
   {
       return m_number;
   }
   Account::operator double() const
   {
       return m_balance;
   }
   bool Account::operator ~() const
   {
       return !m_number;
   }
   Account& Account::operator =(const int num)
   {
       if (~*this)
       {
           if (num > 9999 && num < 100000)
               m_number = num;
           else
               m_number = -1;
       }
       return *this;
   }
   Account& Account::operator =(Account& src)
   {
       if (~*this && src)
       {
           m_number = src.m_number;
           m_balance = src.m_balance;
           src.m_number = 0;
           src.m_balance = 0;
       }
       return *this;
   }
   Account& Account::operator +=(const double amt)
   {
       if (*this && amt > 0)
       {
           m_balance += amt;
       }
       return *this;
   }
   Account& Account::operator -=(const double amt)
   {
       if (*this && amt > 0 && this->m_balance > amt)
       {
           m_balance -= amt;
       }
       return *this;
   }
   Account& Account::operator <<(Account& src)
   {
       if (*this && src && m_number != src.m_number)
       {
           m_balance += src.m_balance;
           src.m_balance = 0;
       }
       return *this;
   }
   Account& Account::operator >>(Account& dest)
   {
       if (*this && dest && m_number != dest.m_number)
       {
           dest.m_balance += m_balance;
           m_balance = 0;
       }
       return *this;
   }

   /********        Helper Operators       ********/

   double operator +(const Account& acc1, const Account& acc2)
   {
       double sum = 0;

       if (acc1 && acc2)
           sum = double(acc1) + double(acc2);

       return sum;
   }
   void operator +=(double& amt, const Account& acc)
   {
       if (acc)
           amt += double(acc);

       //return amt;
   }
}