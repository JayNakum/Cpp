/*
Name: Karan Yatinbhai Dalsania
Email: kdalsania@myseneca.ca
Student ID: 171553217

I have done all the coding by myself and only copied the code that my professor provided to complete my workshop.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "TagList.h"

using namespace sdds;


int TagList::numCount = -1;

void TagList::set()
{
	this->tl = nullptr;
	this->nl = nullptr;
}

void TagList::set(int num)
{
	TagList::cleanup();
	this->nl = new NameTag[num];
	TagList::numCount = 0;
}

void TagList::add(const NameTag& nt)
{
	this->nl[TagList::numCount] = nt;
	TagList::numCount++;
}

void TagList::print()
{
	int count = 0;
	int i;
	while(count < TagList::numCount)
	{
		std::cout << "**";
		for(i = 0; i < NameTag::longNameLen; i++)
		{
			std::cout << "*";
		}
		std::cout << "**" << std::endl;

		
		std::cout.setf(std::ios::left);
		std::cout << "* " << nl[count].name;
		std::cout.fill(' ');
		std::cout.width(NameTag::longNameLen - strlen(nl[count].name) + 2);
		std::cout.unsetf(std::ios::left);
		std::cout << " *" << std::endl;
		
		std::cout << "**";
		for(i = 0; i < NameTag::longNameLen; i++)
		{
			std::cout << "*";
		}
		std::cout << "**" << std::endl;
		count++;
	}
}

void TagList::cleanup()
{
	delete tl;
	delete[] nl;
}