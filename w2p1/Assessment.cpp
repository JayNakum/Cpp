/*
Name: Karan Yatinbhai Dalsania
Email: kdalsania@myseneca.ca
Student ID: 171553217

I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"
#include "Utils.h"
#include <iostream>
#include <cstdio>

namespace sdds {

	bool read(int& value, FILE* fptr)
	{
		//int noOfLines;
		bool check = false;
		if (fptr != NULL)	// this if condition will check if the file is opened properly or not.
		{
			check = fscanf(fptr, "%d\n", &value);
			return check;
		}

		return check;
	}

	bool read(double& value, FILE* fptr)
	{
		bool check = false;
		if (fptr != NULL)	// this if condition will check if the file is opened properly or not.
		{
			check = fscanf(fptr, "%lf,", &value);
			return check;
		}

		return check;
	}

	bool read(char* cstr, FILE* fptr)
	{
		bool check = false;
		if (fptr != NULL)	// this if condition will check if the file is opened properly or not.
		{
			bool check = fscanf(fptr, "%[^\n]\n", cstr);
			return check;
		}

		return check;
	}

	bool read(Assessment& asmnt, FILE* fptr)
	{
		double value = 0.0;
		bool check = false;
		char str[61];
		if (fptr != NULL)	// this if condition will check if the file is opened properly or not.
		{
			check = fscanf(fptr, "%lf,%[^\n]\n",&value,str);
		}

		asmnt.m_mark = &value;
		strcpy(asmnt.m_title, str);
		return check;
	}

	void freeMem(Assessment*& aptr, int size)
	{
		int i;
		for (i = 0; i < size; i++)
		{
			// delete aptr[i].m_mark;
			// delete aptr[i].m_title;
		}

		delete[] aptr;
	}

	int read(Assessment*& aptr, FILE* fptr)
	{
		int i = 0;
		bool check;

		if (fptr != NULL)
		{
			int noOfLines;

			check = read(noOfLines, fptr);
			if (check)
			{
				std::cout << check;
				// Assessment* aptr = new Assessment[noOfLines];
				aptr = new Assessment[noOfLines];
			}

			while (!feof(fptr) || i < noOfLines)
			{
				check = read(aptr[i], fptr);
				if (check)
					++i;
				else
				{
					std::cout << "Value not fetched properly";
				}
			}

			if (i == noOfLines)
			{
				return i;
			}
			else
			{
				i = 0;
				freeMem(aptr, noOfLines);
				return i;
			}
		}
		return i;
	}
}