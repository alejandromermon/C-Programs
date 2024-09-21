/******************************************************************
				Workshop 1 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 18/05/2024

I have done all the coding by myself and only copied the code that 
my professor provided to complete my workshops and assignments.
*****************************************************************/

#ifndef SENECA_FILE_H
#define SENECA_FILE_H

namespace seneca {
	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(struct ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}

#endif