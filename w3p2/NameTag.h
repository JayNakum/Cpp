#ifndef SDDS_NameTag
#define SDDS_NameTag

namespace sdds
{
	class NameTag
	{
	public:
		char name[51];
		static int longNameLen;

		void set(const char* name);
		void checklength(const char* name);
	};
};
#endif
