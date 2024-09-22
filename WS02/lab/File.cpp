/******************************************************************
				Workshop 2 - Part 1

Name		   : Alejandro Mercado
Email	       : amercado-monetti@myseneca.ca
Student ID     : 123350233
Date Completed : 25/05/2024

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*****************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include "File.h"

namespace seneca {

	FILE* fptr;
	bool openFile(const char filename[]) {
		fptr = fopen(filename, "r");
		return fptr != NULL;
	}
	int noOfRecords() {
		int noOfRecs = 0;
		char ch;
		while (fscanf(fptr, "%c", &ch) == 1) {
			noOfRecs += (ch == '\n');
		}
		rewind(fptr);
		return noOfRecs;
	}
	void closeFile() {
		if (fptr) fclose(fptr);
	}
	bool read(char empName[]) {
		bool valid;
		char tmp[128] = { 0 };

		if (fscanf(fptr, "%[^\n]\n", tmp) == 1) {
			valid = true;
			strcpy(empName, tmp);
		}
		else
		{
			valid = false;
		}

		return valid;
	}
	bool read(int& empNum) {
		bool valid;

		valid = fscanf(fptr, "%d,", &empNum) == 1 ? true : false;

		return valid;
	}
	bool read(double& salary) {
		bool valid;

		valid = fscanf(fptr, "%lf,", &salary) ? true : false;

		return valid;
	}

}