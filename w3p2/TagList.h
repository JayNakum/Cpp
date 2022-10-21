#ifndef SDDS_TagList
#define SDDS_TagList

#include "NameTag.h"

namespace sdds
{
	class TagList
	{
	public:
		TagList* tl;
		NameTag* nl;
		static int numCount;
		void set();
		void set(int num);
		void add(const NameTag& nt);
		void print();
		void cleanup();
	};
}
#endif