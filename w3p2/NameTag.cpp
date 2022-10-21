/*
Name: Karan Yatinbhai Dalsania
Email: kdalsania@myseneca.ca
Student ID: 171553217

I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "NameTag.h"

using namespace sdds;

int NameTag::longNameLen = -1;

void NameTag::set(const char* name)
{
	strcpy(this->name, name);
	checklength(this->name);
}

void NameTag::checklength(const char* name)
{
	int temp = strlen(name);
	
	if (NameTag::longNameLen < temp)
	{
		NameTag::longNameLen = temp;
	}
}
