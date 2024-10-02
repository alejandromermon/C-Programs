#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"
using namespace std;
namespace seneca {
	// ***** Line Member functions *****
	Line::operator const char* () const {
		return (const char*)m_value;
	}
	// Make sure Line can not be copied or assigned to another Line.
	Line& Line::operator=(const char* lineValue) {
		delete[] m_value;
		m_value = new char[strlen(lineValue) + 1];
		strcpy(m_value, lineValue);
		return *this;
	}
	Line::~Line() {
		delete[] m_value;
	}

	// ***** TextFile Member Functions *****
	void TextFile::setEmpty() {
		delete[] m_textLines;
		m_textLines = nullptr;

		delete[] m_filename;
		m_filename = nullptr;

		m_noOfLines = 0;
	}
	void TextFile::setFilename(const char* fname, bool isCopy) {
		if (fname) {
			if (isCopy) {
				m_filename = new char[strlen(fname) + 3];
				strcpy(m_filename, "C_");
				strcat(m_filename, fname);
			}
			else {
				m_filename = new char[strlen(fname) + 1];
				strcpy(m_filename, fname);
			}
		}
	}
	void TextFile::setNoOfLines() {
		if (m_filename) {
			ifstream file(m_filename);
			char ch;

			while (file.get(ch)) {
				if (ch == '\n')
					m_noOfLines++;
			}
			file.close();
		}

		if (!m_noOfLines)
			this->setEmpty();
		else
			m_noOfLines++;
	}
	void TextFile::loadText() {
		if (m_filename) {
			delete[] m_textLines;
			m_textLines = new Line[m_noOfLines];

			ifstream file(m_filename);
			string str;

			unsigned i = 0;
			for (i = 0; i < m_noOfLines; i++) {
				if (getline(file, str)) {
					m_textLines[i].m_value = new char[strlen(str.c_str()) + 1];
					strcpy(m_textLines[i].m_value, str.c_str());
				}
			}
			m_noOfLines = i;
			file.close();
		}
	}
	void TextFile::saveAs(const char* fileName) const {
		ofstream file(fileName);

		for (unsigned i = 0; i < m_noOfLines; i++) {
			file << m_textLines[i].m_value << endl;
		}
		file.close();
	}
	void TextFile::deallocateLineMemory() {
		for (unsigned i = 0; i < m_noOfLines; i++) {
			delete[] m_textLines[i].m_value;
			m_textLines[i].m_value = nullptr;
		}
		delete[] m_textLines;
		m_textLines = nullptr;
	}
	TextFile::TextFile(unsigned pageSize) {
		m_filename = nullptr;
		m_textLines = nullptr;
		m_noOfLines = 0;
		m_pageSize = pageSize;
	}
	TextFile::TextFile(const char* filename, unsigned pageSize) {
		m_filename = nullptr;
		m_textLines = nullptr;
		m_noOfLines = 0;
		m_pageSize = pageSize;
		if (filename) {
			setFilename(filename);
			setNoOfLines();
			loadText();
		}
	}
	TextFile::TextFile(const TextFile& src) {
		m_filename = nullptr;
		m_textLines = nullptr;
		m_noOfLines = 0;
		m_pageSize = src.m_pageSize;

		if (src.m_filename) {
			setFilename(src.m_filename, true);
			src.saveAs(m_filename);
			m_noOfLines = src.m_noOfLines;
			loadText();
		}
	}
	TextFile& TextFile::operator=(const TextFile& src) {
		if (this != &src && m_filename && src.m_filename) {
			deallocateLineMemory();
			src.saveAs(this->m_filename);
			m_noOfLines = src.m_noOfLines;
			loadText();
		}

		return *this;
	}
	TextFile::~TextFile() {
		delete[] m_filename;
		delete[] m_textLines;
	}
	unsigned TextFile::lines()const {
		return m_noOfLines;
	}
	ostream& TextFile::view(ostream& ostr)const {
		if (*this) {
			unsigned i, j, len = strlen(m_filename);

			ostr << m_filename << endl;
			for (i = 0; i < len; i++)
				ostr << '=';
			ostr << endl;

			for (i = 0; i < m_noOfLines; i += m_pageSize) {
				for (j = 0; j < m_pageSize && i + j < m_noOfLines; j++)
					ostr << m_textLines[i + j].m_value << endl;

				if (i + j < m_noOfLines) {
					cout << "Hit ENTER to continue...";
					while (getchar() != '\n');
				}
			}
		}
		return ostr;
	}
	istream& TextFile::getFile(istream& istr) {
		string fname;

		cin >> fname;
		while (getchar() != '\n');

		setFilename(fname.c_str());
		setNoOfLines();
		loadText();

		return istr;
	}
	const char* TextFile::operator[](unsigned index)const {
		return this ? m_textLines[index % m_noOfLines].m_value : NULL;
	}
	TextFile::operator bool()const {
		return m_noOfLines ? true : false;
	}
	const char* TextFile::name()const {
		return m_filename;
	}
	ostream& operator<<(ostream& ostr, const TextFile& text) {
		text.view(ostr);

		return ostr;
	}
	istream& operator>>(istream& istr, TextFile& text) {
		text.getFile(istr);

		return istr;
	}
}