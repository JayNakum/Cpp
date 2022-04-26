#include <cstring>


void pointersAndReferences()
{
    char *buffer = new char[8];
    memset(buffer, 0, 8);
    char **ptr = &buffer;
    delete[] buffer;

    int a = 5;
    int &ref = a;
    ref = 2;
}

